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

int MillerRabin(int n, int t) {
	int i = 0, j;
	int N = n-1;
	int s = 0, r = 1, a, x;
	while(1) {
		if(N % 2 == 0) {
			N /= 2;
			s++;
		} else {
			r = N;
			break;
		}
	}

	while(i < t) {
		a = getRand(n-2);
		x = MExp(a, r, n);
		if(x == 1 || x == n-1) {
			i++;
			continue;
		}
		j = 0;
		while(j < r-1 && x != n-1) {
			x = MExp(x, 2, n);
			if(x == 1) return 0;
			j++;
		}
		if(x != n-1) return 0;
		i++;
	}

	return 1;
}


int main() {
	int high = 100;
	int i = 2;
	while(i <= high) {
		if(i == 2 || i == 3 || MillerRabin(i, 1)) cout<<i<<" ";
		i++;
	}
	cout<<endl;
}
