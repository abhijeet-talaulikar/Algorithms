#include<iostream>
#include<cmath>
using namespace std;

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

int main() {
	int a=5, K=596, n=1234;
	cout<<MExp(a, K, n)<<endl;
}
