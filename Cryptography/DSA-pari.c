#include<pari/pari.h>

GEN p, q, alpha, y, a;

void KeyGen() {
	GEN rnum;
	while(1) {
		rnum = random(2^159);
		rnum += 2^159;
		if(isprime(rnum)) {
			q = rnum;
			break;
		}
	}
	int t = random(8);
	while(1) {
		rnum = random(2^(511 + (64 * t)));
		rnum += 2^511;
		if(isprime(rnum) && !((p-1) % q)) {
			p = rnum;
			break;
		}
	}
	alpha = znprimroot(p);
	a = random(q);
	y = Fp_pow(alpha, a, p);
}

void Gen(GEN m, GEN *g, GEN *h) {
	GEN k = random(q);
	GEN r = Fp_pow(a, k, p);
	GEN k_inv = Fp_pow(k, -1, q);
	GEN s = Mod(k_inv * (m + a * r), q);
	*g = r;
	*h = s;
}

int Ver(GEN r, GEN s, GEN m) {
	if( !(abs(r) < q && abs(s) < q) ) return 0;
	GEN w = Fp_pow(s, -1, q);
	GEN u1 = Mod(w * m, q), u2 = Mod(r * w, q);
	GEN v = Mod(Fp_pow(alpha, u1, p) * Fp_pow(y, u2, p), q);
	return (v == r);
}

void main() {
	
}
