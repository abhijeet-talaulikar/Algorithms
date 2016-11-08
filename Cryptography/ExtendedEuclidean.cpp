#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{	int a, b, r, d, x, y, q;
	int x1 = 0,x2 = 1,y1 = 1,y2 = 0;
	cout<<"Enter two positive integers:";
	cin>>a>>b;
	if(!b) {
		d = a;
		x = 1;
		y = 0;
		cout<<d<<endl;
		cout<<x<<endl;
		cout<<y<<endl;
	}
	else {
		while(b) {
			q = a / b;
			r = a - q * b;
			x = x2 - q * x1;
			y = y2 - q * y1;
			a = b;
			b = r;
			x2 = x1;
			x1 = x;
			y2 = y1;
			y1 = y;
		}
		d = a;
		x = x2;
		y = y2;
		cout<<"GCD = "<<d<<endl;
		cout<<"x = "<<x<<endl;
		cout<<"y = "<<y<<endl;
	}
}
