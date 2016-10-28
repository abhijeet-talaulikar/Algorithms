#include<iostream>
using namespace std;

int a[17]={16,4,10,14,7,9,3,2,8,1,13,12,19,5,25,21,6},i,j,temp;

void SelectionSort(int a[],int n) {
	for(i=n-1;i>=0;i--) {
		for(j=i-1;j>=0;j--) {
			if(a[i]<a[j]) {
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		for(int i=0;i<17;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
}

int main() {
	SelectionSort(a,17);
}
