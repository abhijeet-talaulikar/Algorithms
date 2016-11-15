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

class DSA {
	long int a;
	public:
	long int p, q, alpha, y;
	DSA() {
		Keygen();
	}
	void Keygen() {
		long int temp, sec = pow(2, 10);
		//generate q
		while(1) {
			temp = getRand(2, sec) + sec;
			if(SolovayStrassen(temp, sec)) {
				this->q = temp;
				break;
			}
		}
		cout<<"q = "<<this->q<<endl;
		//choose t
		int t = getRand(1, 8);
		//generate p
		int i = q + 1;
		while(1) {
			if(SolovayStrassen(i, sec) && ((i - 1) % this->q == 0)) {
				this->p = i;
				break;
			}
			i++;
		}
		cout<<"p = "<<this->p<<endl;
		//generate alpha
		for(long int g = 2;g <= this->p - 1;g++) {
			long int d1, d2;
			if(ExtGCD(g, this->p, &d1, &d2) == 1) {
				this->alpha = ModExp(g, (this->p - 1) / this->q, this->p);
				if(this->alpha != 1) break;
			}
		}
		this->a = getRand(1, this->q - 1);
		this->y = ModExp(this->alpha, this->a, this->p);
		cout<<"alpha = "<<this->alpha<<endl;
		cout<<"y = "<<this->y<<endl;
		cout<<"a = "<<this->a<<endl;
	}
	void Sign(long int m, long int *r, long int *s) {
		long int k = getRand(1, this->q - 1);
		long int r1 = ModExp(this->alpha, k, this->p) % this->q;
		long int k_inv = ModExp(k, this->q - 2, this->q);
		long int s1 = (k_inv * (m + this->a * r1)) % this->q;
		*r = r1;
		*s = s1;
	}
	long int Verify(long int m, long int r, long int s) {
		if(r <= 0 || r >= this->q) return 0;
		if(s <= 0 || s >= this->q) return 0;
		long int w = ModExp(s, this->q - 2, this->q);
		long int u1 = (w * m) % this->q;
		long int u2 = (r * w) % this->q;
		long int v = (ModExp(this->alpha, u1, this->p) * ModExp(this->y, u2, this->p)) % this->p;
		v %= this->q;
		return (v == r);
	}
};

int main() {
	DSA D;
	long int m, r, s;
	cout<<"Enter challenge message: ";
	cin>>m;
	D.Sign(m, &r, &s);
	cout<<"Signature = ("<<r<<", "<<s<<")"<<endl;
	cout<<"Verified = "<<D.Verify(m, r, s)<<endl;
}
