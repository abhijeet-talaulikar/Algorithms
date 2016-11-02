#include<iostream>
#include<cmath>
using namespace std;

int prime(int n) {
	if(n == 1) return 0;
	if(n == 2) return 1;
	for(int i = 2;i <= floor(sqrt(n));i++) if(n % i == 0) return 0;
	return 1;
}

int phi(int n) {
	//if n is prime
	if(prime(n)) return n-1;

	//if n is composite
	double myphi = n;
	for(int i = 2;i <= ceil(sqrt(n));i++) if(prime(i) && !(n % i)) myphi = myphi * (i-1) / i;
	return myphi;
}

int order(int n, int element) {
	for(int i = 1;i <= phi(n);i++) if( !((int)(pow(element, i) - 1) % n) ) return i;
}

int main() {
	int n, element;
	cout<<"Enter modulus: ";
	cin>>n;
	cout<<"Enter element: ";
	cin>>element;
	cout<<"Order = "<<order(n, element)<<endl;
}
