#include<iostream>
using namespace std;

int a[17]={16,4,10,14,7,9,3,2,8,1,13,12,19,5,25,21,6},i,j,temp;

void SelectionSort(int a[],int n) {
	for(i=0;i<n;i++) {
		for(j=0;j<n-1;j++) {
			if(a[j]>a[j+1]) {
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		for(int i=0;i<17;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
}

int main() {
	SelectionSort(a,17);
}
