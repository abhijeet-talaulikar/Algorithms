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

int Fermat(int n, int t) {
	if(n % 2 == 0) return 0;
	for(int i = 0;i < t;i++) {
		int a = getRand(n-2), r = MExp(a, n - 1, n);
		if(r != 1) return 0;
	}
	return 1;
}

int main() {
	int n, t;
	cout<<"Enter integer: ";
	cin>>n;
	cout<<"Enter security parameter: ";
	cin>>t;
	cout<<n<<" is "<<(Fermat(n, t) ? "prime" : "composite")<<endl;
}
