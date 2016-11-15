#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
using namespace std;

long int getRand(long int min, long int max) {
	srand(time(NULL));
	int r = rand();
	if((r % max) < min) return (r % max) + min;
	return r % max;
}

long ModExp(long int x, long int y, long int n) {
	long int res = 1;
	x = x % n;
	while(y > 0) {
		if(y & 1) res = (res * x) % n;
		y = y>>1;
		x = (x * x) % n;
	}
	return res;
}

long int Jacobi(long int a, long int n) {
	if(!a) return 0;
	if(a == 1) return 1;
	long int e = 0, a1 = a, n1, s;
	while(a1 % 2 == 0) {
		a1 /= 2;
		e++;
	}
	if(e % 2 == 0) s = 1;
	else if(n % 8 == 1 || n % 8 == 7) s = 1;
	else if(n % 8 == 3 || n % 8 == 5) s = -1;
	if(n % 4 == 3 && a1 % 4 == 3) s = 0-s;
	n1 = n % a1;
	if(a1 == 1) return s;
	else return s * Jacobi(n1, a1);
}

int SolovayStrassen(long int n, long int t) {
	t += 10000;
	if(n == 1) return 0;
	if(n == 2) return 1;
	long int a, r, s;
	for(long int i = 0;i < t;i++) {
		a = getRand(2, n - 2);
		r = ModExp(a, (n - 1) / 2, n);
		if(r != 1 && r != n - 1) return 0;
		s = Jacobi(a, n);
		if(r % n == s) return 0;
	}
	return 1;
}

long int ExtGCD(long int a, long int b, long int *x, long int *y) {
	if(!a) {
		*x = 0;
		*y = 1;
		return b;
	}
	long int x1, y1;
	long int gcd = ExtGCD(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}

class RSA {
	long int p, q, d, phi;
	public:
	long int n, e;
	RSA() {
		Keygen();
	}
	void Keygen() {
		long int temp, sec = 1000, d2, d3;
		//generate first large prime p
		while(1) {
			temp = getRand(2, sec) + sec;
			if(SolovayStrassen(temp, sec)) {
				this->p = temp;
				break;
			}
		}
		//generate second large prime
		while(1) {
			temp = getRand(2, sec) + sec;
			if(SolovayStrassen(temp, sec) && temp != this->p) {
				this->q = temp;
				break;
			}
		}
		this->n = p * q;
		this->phi = (p - 1) * (q - 1);
		cout<<"p = "<<p<<endl;
		cout<<"q = "<<q<<endl;
		cout<<"n = "<<n<<endl;
		//generate e
		while(1) {
			temp = getRand(2, phi);
			if(ExtGCD(temp, phi, &d2, &d3) == 1) {
				this->e = temp;
				break;
			}
		}
		//generate d
		long d1;
		ExtGCD(this->e, 0 - this->phi, &this->d, &d1); //thus, d is set
		//while(this->d < 0) this->d += this->phi;
		cout<<"e = "<<this->e<<endl;
		cout<<"d = "<<this->d<<endl;
	}
	long int Encrypt(long int m) {
		return ModExp(m, this->e, this->n);
	}
	long int Decrypt(long int c) {
		return ModExp(c, this->d, this->n);
	}
};

int main() {
	long int m, c;
	RSA R;
	cout<<"Enter message (less than p & q): ";
	cin>>m;
	c = R.Encrypt(m);
	cout<<"Ciphertext = "<<c<<endl;
	cout<<"Plaintext = "<<R.Decrypt(c)<<endl;
}
