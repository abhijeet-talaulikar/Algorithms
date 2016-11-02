#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
using namespace std;

class Elgamal {
	long int p, g, x, gx;

	long int getRand(int min = 0, int max = 0) {
		srand (time(NULL));
		int num = rand() % max;
		if(num < min) return num + min;
		else return num;
	}

	int prime(long int n) {
		if(n == 1) return 0;
		if(n == 2) return 1;
		for(int i = 2;i <= floor(sqrt(n));i++) if(n % i == 0) return 0;
		return 1;
	}

	long int ModExp(long int x, unsigned long int y) {
		long int res = 1;
		x = x % this->p;
		while (y > 0) {
			if (y & 1) res = (res*x) % this->p;
			y = y>>1;
			x = (x*x) % this->p;
		}
		return res;
	}

	long int phi(long int n) {
		if(prime(n)) return n-1;
		long int myphi = n;
		for(long int i = 2;i <= n/2;i++) if(prime(i) && !(n % i)) myphi = myphi * (i-1) / i;
		return myphi;
	}

	long int gcd(long int a, long int b) {
		if(!a) return b;
		return gcd(b % a, a);
	}

	long int order(long int element) {
		//for(long int i = 1;i <= phi(this->p);i++) if( !((long int)(pow(element, i) - 1) % this->p) ) return i;
		for(long int i = 1;i <= phi(this->p);i++) {
			long int temp = 1;
			for(long int j = 0;j < i;j++) temp = (temp * element) % this->p;
			if( !((temp - 1) % this->p) ) return i;
		}

	}

	void keygen(long int xt = 0) {
		if(xt) this->x = xt;
		else this->x = getRand(1, this->p - 2);
		for(long int i = 2;i < this->p;i++) {
			if(gcd(i, this->p) == 1) {
				if(order(i) == phi(this->p)) {
					this->g = i;
					this->gx = ModExp(this->g, this->x);
				}
			}
		}
		cout<<"Public key = ("<<this->p<<", "<<this->g<<", "<<this->gx<<")"<<endl;
		cout<<"Private key = "<<x<<endl;
	}

	public:
	Elgamal(long int p, long int xt = 0) {
		this->p = p;
		if(xt) this->keygen(xt);
		else this->keygen();
	}

	void encrypt(long int m, long int *c1, long int *c2) {
		long int k = getRand(1, this->p - 2);
		*c1 = ModExp(this->g, k);
		*c2 = m * ModExp(this->gx, k);
	}

	long int decrypt(long int c1, long int c2) {
		long int temp = ModExp(c1, this->x);
		return (c2 / temp) % p;
	}
};

int main() {
	long int x, m, c1, c2, p;
	cout<<"Enter p: ";
	cin>>p;
	cout<<"Enter x (enter 0 for random selection): ";
	cin>>x;
	Elgamal E(p, x);
	cout<<"Enter message: ";
	cin>>m;
	E.encrypt(m, &c1, &c2);
	cout<<"Ciphertext = ("<<c1<<", "<<c2<<")"<<endl;
	cout<<"Plaintext = "<<E.decrypt(c1, c2)<<endl;
}
