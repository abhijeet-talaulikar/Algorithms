#include <pari/pari.h>
GEN extgcd(GEN A, GEN B, GEN *U, GEN *V) {
	pari_sp av = avma;
	GEN ux = gen_1, vx = gen_0, a = A, b = B;
	if (typ(a) != t_INT) pari_err_TYPE("extgcd",a);
	if (typ(b) != t_INT) pari_err_TYPE("extgcd",b);
	if (signe(a) < 0) { a = negi(a); ux = negi(ux); }
	while (!gequal0(b)) {
		GEN r, q = dvmdii(a, b, &r), v = vx;
		vx = subii(ux, mulii(q, vx));
		ux = v; a = b; b = r;
	}
	*U = ux;
	*V = diviiexact( subii(a, mulii(A, ux)), B );
	gerepileall(av, 3, &a, U, V); return a;
}

GEN encrypt(GEN msg, GEN e, GEN n) {
	GEN Cipher;
	Cipher = Fp_pow(msg, e, n);
	return Cipher;
}

GEN decrypt (GEN C, GEN d, GEN n) {
	GEN M;
	M = Fp_pow(C, d, n);
	return M;
}

int main() {
	GEN n, p, q, phi_value, e, d, u, v, C, msg;
	pari_init(1000000,2);
	printf("Enter the first prime (greater than 2048) : ");
	p=gp_read_stream(stdin);
	printf("Enter the second prime : ");
	q = gp_read_stream(stdin);
	printf("Enter the message for A : ");
	msg = gp_read_stream(stdin);
	p = nextprime(randomi(p));
	q = nextprime(randomi(q));
	n = gmul(p, q);
	phi_value = gmul(gsubgs(p, 1), gsubgs(q, 1));
	e = randomi(phi_value);
	while(!gequal1(gcdii(e, phi_value))) e = randomi(phi_value);
	extgcd(e, phi_value, &u, &v);
	d = u;
	C = encrypt(msg, e, n);
	pari_printf("A's public key = (n = %Ps, e = %Ps)\n", n, e);
	pari_printf("A's private key, d = %Ps\n", d);	
	pari_printf("Ciphertext : %Ps\n", C);
	pari_printf("Decrypted plaintext : %Ps\n",decrypt(C, d, n));
	pari_close();
	return 0;
}
