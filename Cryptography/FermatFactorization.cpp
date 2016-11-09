#include<iostream>
#include<cmath>
using namespace std;

int isPerfectSquare(long int n) {
	for(long int i = 0;i < n / 2;i++) if(i * i == n) return 1;
	return 0;
}

void FermatFactor(long int n) {
	long int a = ceil(sqrt(n));
	long int b2 = a * a - n;
	while(!isPerfectSquare(b2)) {
		a = a + 1;
		b2 = a * a - n;
	}
	cout<<a - sqrt(b2)<<" "<<a + sqrt(b2)<<endl;
}

int main() {
	long int n;
	cout<<"Enter number: ";
	cin>>n;
	cout<<"Prime factors are: ";
	FermatFactor(n);
}
