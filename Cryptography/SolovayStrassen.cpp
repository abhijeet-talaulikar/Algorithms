#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
using namespace std;

int getRand(int max) {
	srand (time(NULL));
	int range = max - 1;
	return (rand() % range + 2);
}

long int ModExp(long int x, unsigned long int y, int p) {
	long int res = 1;
	x = x % p;
	while (y > 0) {
		if (y & 1) res = (res*x) % p;
		y = y>>1;
		x = (x*x) % p;
	}
	return res;
}

int jacobi(int a, int n) {
	if(a == 0 || a == 1) return a;
	int s, a1 = a, n1, e = 0;
	while(a1 % 2 == 0) {
		a1 /= 2;
		e++;
	}
	if(e % 2) {
		if(n % 8 == 1 || n % 8 == 7) s = 1;
		else if(n % 8 == 3 || n % 8 == 5) s = -1;
	} else s = 1;
	if(n % 4 == 3 && a1 % 4 == 3) s *= -1;
	n1 = n % a1;
	if(a1 == 1) return s;
	else return s * jacobi(n1, a1);
}

int SolovayStrassen(int n, int t) {
	if(n == 2) return 1;
	if(n == 1) return 0;
	if(n % 2 == 0) return 0;
	for(int i = 0;i < t;i++) {
		int a = getRand(n-1), r = ModExp(a, (n - 1) / 2, n);
		if(r != 1 && r != n-1) return 0;
		int s = jacobi(a, n);
		if(r % n != s) return 0;
	}
	return 1;
}

int main() {
	int n, t;
	cout<<"Enter integer: ";
	cin>>n;
	cout<<"Enter security parameter: ";
	cin>>t;
	cout<<n<<" is "<<(SolovayStrassen(n, t) ? "prime" : "not prime")<<endl;
}
