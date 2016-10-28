#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
using namespace std;

class RSA {
	int N, E, D;

	int getRand(int min = 0, int max = 0) {
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

	int phi(int n) {
		//if n is prime
		if(prime(n)) return n-1;

		//if n is composite
		double myphi = n;
		for(int i = 2;i <= n/2;i++) if(prime(i) && !(n % i)) myphi = myphi * (i-1) / i;
		return myphi;
	}

	long int gcd(long int a, long int b) {
		if(!a) return b;
		return gcd(b % a, a);
	}

	long int gcdExtended(long int a, long int b, long int *x, long int *y) {
		if (!a) {
			*x = 0;
			*y = 1;
			return b;
		}
		long int x1, y1;
		long int gcd = gcdExtended(b % a, a, &x1, &y1);
		*x = y1 - (b / a) * x1;
		*y = x1;

		return gcd;
	}

	void keygen(long int n) {
		//compute E
		do this->E = getRand(2, phi(n));
		while(gcd(this->E, phi(n)) != 1);
	
		//compute d
		long int x, y;
		gcdExtended(this->E, phi(n), &x, &y);
		this->D = x;
		while(this->D <= 0) this->D = x + phi(n);

		cout<<"A's public key is (N = "<<n<<", E = "<<this->E<<")"<<endl;
		cout<<"A's private key is D = "<<this->D<<endl;
	}

	long int ModExp(long int x, unsigned long int y) {
		long int res = 1;
		x = x % this->N;
		while (y > 0) {
			if (y & 1) res = (res*x) % this->N;
			y = y>>1;
			x = (x*x) % this->N;
		}
		return res;
	}

	public:
	RSA(long int p, long int q) {
		this->N = p * q;
		keygen(this->N);
	}

	long int encrypt(long int m) {
		return ModExp(m, this->E);
	}

	long int decrypt(long int c) {
		return ModExp(c, this->D);
	}
};

int main() {
	int p, q;
	cout<<"Enter prime p: ";
	cin>>p;
	cout<<"Enter prime q: ";
	cin>>q;
	cout<<"Generating key.."<<endl;
	RSA R(p, q);
	long int m;
	cout<<"You are B."<<endl;
	cout<<"Enter your message: ";
	cin>>m;
	long int c = R.encrypt(m);
	cout<<"Your Ciphertext: "<<c<<endl;
	cout<<"Plaintext (At A's end): "<<R.decrypt(c)<<endl;
}
