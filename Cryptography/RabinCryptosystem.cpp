#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
using namespace std;

class Rabin {
	long int N, P, Q, a, b;
	public:
	Rabin() {
		KeyGen();
	}

	int solveCongruence(int c, int a, int n) {
		int i = 0;
		while(1) if((c * (i++)) % n == 1) return i-1;
		return 0;
	}
	
	Rabin(long int P, long int Q) {
		KeyGen(P, Q);
	}

	long int getRand(int min = 0, int max = 0) {
		srand (time(NULL));
		int num = rand() % max;
		if(num < min) return num + min;
		else return num;
	}

	long int prime(long int n) {
		if(n == 1) return 0;
		if(n == 2) return 1;
		for(int i = 2;i <= floor(sqrt(n));i++) if(n % i == 0) return 0;
		return 1;
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

	
	void KeyGen(long int P = 0, long int Q = 0) {
		if(P && Q) {
			this->P = P;
			this->Q = Q;
			this->N = P * Q;
		} else {
			cout<<"Generating random primes.."<<endl;
			long int r;
			while(1) {
				r = getRand(2000, 5000);
				if(prime(r) && r % 4 == 3) {
					this->P = r;
					break;
				}
			}
			while(1) {
				r = getRand(2000, 5000);
				if(r != this->P && prime(r) && r % 4 == 3) {
					this->Q = r;
					break;
				}
			}
			this->N = this->P * this->Q;
		}
		cout<<"P = "<<this->P<<", Q = "<<this->Q<<", N = "<<this->N<<endl;

		//run extended gcd
		long int a, b;
		gcdExtended(this->P, this->Q, &a, &b);
		this->a = a;
		this->b = b;
	}

	long int Encrypt(long int m) {
		long int c = (m * m) % this->N;
		return c;
	}

	void Decrypt(long int c) {
		long int r, s, x, y, i;
		for(i = 1, r = 1;i <= (this->P+1)/4;i++)  r = (r * c) % this->N;
		for(i = 1, s = 1;i <= (this->Q+1)/4;i++)  s = (s * c) % this->N;
		x = (this->a * this->P * s + this->b * this->Q * r) % this->N;
		y = (this->a * this->P * s - this->b * this->Q * r) % this->N;
		cout<<"Square roots of ciphertext: "<<endl;
		cout<<x<<endl;
		cout<<solveCongruence(x, this->N - 1, this->N)<<endl;
		cout<<y<<endl;
		cout<<solveCongruence(y, this->N - 1, this->N)<<endl;
	}
};

int main() {
	long int m, c, p;
	Rabin R;
	cout<<"Enter message: ";
	cin>>m;
	cout<<"Message: "<<m<<endl;
	c = R.Encrypt(m);
	cout<<"Ciphertext: "<<c<<endl;
	R.Decrypt(c);
}
