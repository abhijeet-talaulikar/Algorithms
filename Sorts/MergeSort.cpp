#include<iostream>
using namespace std;

int a[17]={16,4,10,14,7,9,3,2,8,1,13,12,19,5,25,21,6},i,j,k,n1,n2;

void Merge(int a[],int l,int m,int r) {
	n1=m-l+1;
	n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++) L[i]=a[l+i];
	for(i=0;i<n2;i++) R[i]=a[m+i+1];
	i=j=0,k=l;
	while(i<n1 && j<n2) {
		if(L[i]<=R[j]) a[k++]=L[i++];
		else a[k++]=R[j++];
	}
	while(i<n1) a[k++]=L[i++];
	while(j<n2) a[k++]=R[j++];
}

void MergeSort(int a[],int l,int r) {
	if(l<r) {
		int m=l+(r-l)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,r);
		Merge(a,l,m,r);
	}
}

int main() {
	MergeSort(a,0,16);
	for(int i=0;i<17;i++) cout<<a[i]<<" ";
	cout<<endl;
}
