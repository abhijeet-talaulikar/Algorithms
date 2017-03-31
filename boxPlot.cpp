#include<iostream>
#include <cmath>
using namespace std;

#define N 17

double median(double *arr, int a, int b) {
	int n = b-a+1;
	if(n % 2) return arr[a + (int)ceil( (double)n / 2.0 ) - 1];
	return (arr[a + n/2 - 1] + arr[a + n/2 + 1 - 1]) / 2;
}

int main() {
	double a[N] = {2,31,3,8,4,17,5,14,20,7,18,11,9,23,15,12,16};
	double q1, q2, q3;
	//sort
	for(int i = 0;i < N;i++) {
		for(int j = i;j < N;j++) {
			if(a[i] > a[j]) {
				double temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	
	cout<<"Sample : ";
	for(int i = 0;i < N;i++) cout<<a[i]<<" ";
	cout<<endl;
	
	q2 = median(a, 0, N-1);
	
	int i = 0;
	while(a[i] < q2) i++;
	i--;
	q1 = median(a, 0, 7);
	
	i = N-1;
	while(a[i] > q2) i--;
	i++;
	q3 = median(a, 9, 16);
	
	cout<<"Min: "<<a[0]<<endl;
	
	cout<<"Q1: "<<q1<<endl;
	
	cout<<"Q2: "<<q2<<endl;
	
	cout<<"Q3: "<<q3<<endl;
	
	cout<<"Max: "<<a[N-1]<<endl;
}
