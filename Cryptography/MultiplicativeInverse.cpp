#include<iostream>
using namespace std;

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

int main() {
	int p, n;
	cout<<"Enter prime modulus p: ";
	cin>>p;
	cout<<"Enter number between 0 and p-1: ";
	cin>>n;
	cout<<"("<<n<<"^-1) mod "<<p<<" = "<<ModExp(n, p - 2, p)<<endl;
}
