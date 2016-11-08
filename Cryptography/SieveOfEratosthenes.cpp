#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int prime(int n) {
	if(n == 1 || !n) return 0;
	if(n == 2) return 1;
	for(int i=2;i<=sqrt(n);i++) if(n % i == 0) return 0;
	return 1;
}

int sieve(int high) {
	int low = 2;
	int a[high-low+1];
	for(int i=0;i<=high-low;i++) a[i] = i+low;

	int b[(int)sqrt(high)], k = -1, n=0;
	for(int i=2;i<=sqrt(high);i++) if(prime(i)) b[++k] = i;
	for(int i=0;i<=k;i++) {
		for(int j=2;;j++) {
			if(j*b[i]>high) break;
			if(j*b[i]-low >= 0) a[j*b[i]-low] = 0;
		}
	}
	for(int i=0;i<=high-low;i++) if(a[i]) n++;
	return n;
}

int main() {
	ofstream f;
	f.open("graph.dat");
	f<<"#X\tY\n";
	for(int i=10000;i<=100000;i+=10000) f<<i<<"\t"<<sieve(i)<<"\n";
	f.close();

	f.open("lnx.dat");
	f<<"#X\tY\n";
	for(int i=10000;i<=100000;i+=10000) f<<i<<"\t"<<i/log(i)<<"\n";
	f.close();
}
