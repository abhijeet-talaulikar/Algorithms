#include <pari/pari.h>

int Fermat(GEN n, int t) {
	if(gequalgs(n, 2)) return 1;
	if(gequal1(n)) return 0;
	if(gdvd(n, gen_2)) return 0;
	int i;
	for(i = 0;i < t;i++) {
		GEN a = randomi(gsub(n, gen_2)), r = Fp_pow(a, gsub(n, gen_1), n);
		if(!gequal1(r)) return 0;
	}
	return 1;
}

int main() {
	pari_init(1000000,2);
	printf("Enter number: ");
	GEN n = gp_read_stream(stdin);
	int t;
	printf("Enter security parameter: ");
	scanf("%d", &t);
	pari_printf("%Ps is ", n);
	printf((Fermat(n, t) ? "prime\n" : "not prime\n"));
	pari_close();
	return 0;
}
