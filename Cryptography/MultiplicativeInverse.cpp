#include<iostream>
using namespace std;

int Inverse(int c, int p) {
	int i = 0;
	while(1) if((c * (i++)) % p == 1) return i-1;
	return 0;
}

int main() {
	int p, n;
	cout<<"Enter modulus p: ";
	cin>>p;
	cout<<"Enter number between 0 and p-1: ";
	cin>>n;
	cout<<"("<<n<<"^-1) mod "<<p<<" = "<<Inverse(n, p)<<endl;
}
