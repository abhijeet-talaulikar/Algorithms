#include <pari/pari.h>

void Keygen(GEN *p, GEN *gx, GEN *g, GEN *x) {
	*p = randomi(gpowgs(gen_2, 20));
	*p = gadd(*p, gpowgs(gen_2, 20));
	*p = nextprime(*p);
	*g = pgener_Fp(*p);
	*x = randomi(gsub(*p, gen_2));
	*gx = Fp_pow(*g, *x, *p);
}

void Encrypt(GEN m, GEN p, GEN g, GEN gx, GEN *c1, GEN *c2) {
	GEN k = randomi(gsub(p, gen_2));
	*c1 = Fp_pow(g, k, p);
	*c2 = gmod(gmul(m, powgi(gx, k)), p);
}

GEN Decrypt(GEN c1, GEN c2, GEN x, GEN p) {
	GEN temp = Fp_pow(c1, x, p);
	temp = Fp_pow(temp, gsub(p, gen_2), p);
	return gmod(gmul(c2, temp), p);
}

int main() {
	pari_init(100000000000,2);
	GEN p, gx, g, x, m, c1, c2;
	Keygen(&p, &gx, &g, &x);
	pari_printf("A's public key is (p = %Ps, g =  %Ps, g^x = %Ps)\n", p, g, gx);
	pari_printf("A's private key is x = %Ps\n", x);
	pari_printf("Enter message: ");
	m = gp_read_stream(stdin);
	Encrypt(m, p, g, gx, &c1, &c2);
	pari_printf("Ciphertext = (%Ps, %Ps)\n", c1, c2);
	pari_printf("Plaintext = %Ps\n", Decrypt(c1, c2, x, p));
	pari_close();
	return 0;
}
