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
	long int a, k, n;
	cout<<"Enter a: ";
	cin>>a;
	cout<<"Enter k: ";
	cin>>k;
	cout<<"Enter n: ";
	cin>>n;
	cout<<"(a ^ k) mod n = "<<ModExp(a, k, n)<<endl;
}
