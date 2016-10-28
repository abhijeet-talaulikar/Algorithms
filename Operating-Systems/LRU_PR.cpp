#include<iostream>
using namespace std;

int page_sequence[10]={7,0,1,2,0,3,4,3,7,1};
int main_memory[3];
int recency[3];

int page_fault(int page) {
	int i;
	for(i=0;i<3;i++) if(main_memory[i]==page) return 0;
	return 1;
}

int main() {
	int i,j,k;
	for(i=0;i<3;i++) {
		main_memory[i]=page_sequence[i];
		recency[i]=1;
	}
	for(i=0;i<3;i++) cout<<main_memory[i]<<endl;
	cout<<endl;
	for(i=3;i<10;) {
		for(j=0;j<3;j++) recency[j]++;
		if(page_fault(page_sequence[i])) {
			k=0;
			for(j=1;j<3;j++) if(recency[j]>recency[k]) k=j;
			main_memory[k]=page_sequence[i];
			recency[k]=0;
			for(j=0;j<3;j++) cout<<main_memory[j]<<endl;
			cout<<endl;
		} else {
			for(j=0;j<3;j++) if(main_memory[j]==page_sequence[i]) k=j;
			recency[k]=0;
		}
		i++;
	}
}
