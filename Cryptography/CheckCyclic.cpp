#include<iostream>
#include<cmath>
using namespace std;

int prime(int n) {
	if(n == 1) return 0;
	if(n == 2) return 1;
	for(int i = 2;i <= floor(sqrt(n));i++) if(n % i == 0) return 0;
	return 1;
}

int MExp(int a, int K, int n) {
	int k[100], b, i = -1;
	b = 1;
	if(!K) return b;
	while(K) {
		if(K%2) k[++i] = 1;
		else k[++i] = 0;
		K /= 2;
	}
	if(k[0]) b = a;
	for(int j=1,A=a;j<=i;j++) {
		A = (A*A) % n;
		if(k[j]) b = (A * b) % n;
	}
	return b;
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
