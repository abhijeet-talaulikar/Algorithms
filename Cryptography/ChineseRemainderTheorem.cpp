#include<iostream>
using namespace std;

int solveCongruence(int c, int a, int n) {
	int i = 0;
	while(1) if((c * (i++)) % n == 1) return i-1;
	return 0;
}

int main() {
	int num, N = 1, X = 0;
	cout<<"Enter number of linear congruences: ";
	cin>>num;
	int a[num], n[num], x[num];
	cout<<"\nEnter values of the a's: ";
	for(int i = 0;i < num;i++) cin>>a[i];
	cout<<"\nEnter values of the n's: ";
	for(int i = 0;i < num;i++) cin>>n[i];
	for(int i = 0;i < num;i++) N *= n[i];
	for(int i = 0;i < num;i++) x[i] = solveCongruence(N / n[i], 1, n[i]);
	for(int i = 0;i < num;i++) X += (a[i] * x[i] * N / n[i]);
	X %= N;
	cout<<"\nSolution is "<<X<<" mod "<<N<<endl;
}
