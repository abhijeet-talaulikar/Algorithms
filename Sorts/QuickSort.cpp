#include<iostream>
using namespace std;

int a[17]={16,4,10,14,7,9,3,2,8,1,13,12,19,5,25,21,6},i,j,temp;

int Partition(int a[],int l,int r) {
	int x=a[r];
	int i=(l-1);
	for(int j=l;j<r;j++) {
		for(int k=0;k<17;k++) cout<<a[k]<<" ";cout<<"; i = "<<i<<" ";cout<<"; j = "<<j<<" ";cout<<endl;
		if(a[j]<=x) {
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return (i+1);
}

void QuickSort(int a[],int l,int r) {
	if(l<r) {
		int p=Partition(a,l,r);
		QuickSort(a,l,p-1);
		QuickSort(a,p+1,r);
	}
}

int main() {
	QuickSort(a,0,16);
	for(int i=0;i<17;i++) cout<<a[i]<<" ";cout<<endl;
}
