#include<iostream>
using namespace std;

int a[18]={0,16,4,10,14,7,9,3,2,8,1,13,12,19,5,25,21,6},l,r,largest,temp;
void Heapify(int a[], int i, int n) {
	l=2*i;
	r=l+1;
	if(l<=n && a[i]<a[l]) {
		temp=a[i];
		a[i]=a[l];
		a[l]=temp;
	}
	if(r<=n && a[i]<a[r]) {
		temp=a[i];
		a[i]=a[r];
		a[r]=temp;
	}
	if(i<n) Heapify(a,i+1,n);
}

void BuildHeap(int a[], int n) {
	for(int i=n;i>=1;i--) Heapify(a,i,n);
}

void HeapSort(int a[], int n) {
	BuildHeap(a,n);
	for(int i=n;i>=2;i--) {
		temp=a[i];
		a[i]=a[1];
		a[1]=temp;
		Heapify(a,1,i-1);
	}
}

int main() {
	HeapSort(a,17);
	for(int i=1;i<=17;i++) cout<<a[i]<<" ";
	cout<<endl;
}
