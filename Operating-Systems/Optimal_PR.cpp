#include<iostream>
using namespace std;

int page_sequence[10]={7,0,1,2,0,3,4,3,7,1};
int main_memory[3];

int page_fault(int page) {
	int i;
	for(i=0;i<3;i++) if(main_memory[i]==page) return 0;
	return 1;
}

int main() {
	int i,j,k,a[3];
	for(i=0;i<3;i++) main_memory[i]=page_sequence[i];
	for(i=0;i<3;i++) cout<<main_memory[i]<<endl;
	cout<<endl;
	for(i=3;i<10;) {
		if(page_fault(page_sequence[i])) {
			a[0]=a[1]=a[2]=NULL;
			for(k=0;k<3;k++) {
				for(j=i+1;j<10;j++) {
					if(page_sequence[j]==main_memory[k]) {
						a[k]=j;
						break;
					}
				}
			}
			k=0;
			for(j=0;j<3;j++) if(a[j]>a[k]) k=j;
			for(j=0;j<3;j++) if(a[j]==NULL) {
				k=j;
				break;
			}
			main_memory[k]=page_sequence[i];
			for(j=0;j<3;j++) cout<<main_memory[j]<<endl;
			cout<<endl;
		}
		i++;
	}
}
