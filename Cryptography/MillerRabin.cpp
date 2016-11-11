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
	int n, t;
	cout<<"Enter integer: ";
	cin>>n;
	cout<<"Enter security parameter: ";
	cin>>t;
	cout<<n<<" is "<<(MillerRabin(n, t) ? "prime" : "not prime")<<endl;
}
