#include<iostream>
#include<cmath>
using namespace std;

int prime(int n) {
	if(n == 1) return 0;
	if(n == 2) return 1;
	for(int i = 2;i <= floor(sqrt(n));i++) if(n % i == 0) return 0;
	return 1;
}

long int MExp(long int x, unsigned long int y, int p) {
	long int res = 1;
	x = x % p;
	while (y > 0) {
		if (y & 1) res = (res*x) % p;
		y = y>>1;
		x = (x*x) % p;
	}
	return res;
}

int phi(int n) {
	//if n is prime
	if(prime(n)) return n-1;

	//if n is composite
	double myphi = n;
	for(int i = 2;i <= n/2;i++) if(prime(i) && !(n % i)) myphi = myphi * (i-1) / i;
	return myphi;
}

int order(int n, int element) {
	for(int i = 1;i < n;i++) if(MExp(element, i, n) == 1) return i;
}

int cyclic(int n) {
	int myphi = phi(n);
	for(int i = 2;i < n;i++) if(order(n, i) == myphi) return 1;
	return 0;
}

void printGenerators(int n) {
	int myphi = phi(n);
	for(int i = 2;i < n;i++) if(order(n, i) == myphi) cout<<i<<" ";
}

int main() {
	int n, element;
	cout<<"Enter modulus: ";
	cin>>n;
	if(cyclic(n)) {
		cout<<"The group is cyclic ("<<phi(phi(n))<<" generators)"<<endl;
		cout<<"Generators are ";
		printGenerators(n);
	} else cout<<"The group is acyclic"<<endl;
	cout<<endl;
}
