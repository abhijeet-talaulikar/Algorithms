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
