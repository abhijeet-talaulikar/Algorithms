#include<iostream>
using namespace std;

int page_sequence[10]={7,0,1,2,0,3,4,3,7,1};
int main_memory[3];
int FIFO_age[3];

int page_fault(int page) {
	int i;
	for(i=0;i<3;i++) if(main_memory[i]==page) return 0;
	return 1;
}

int main() {
	int i,j,max;
	for(i=0;i<3;i++) {
		main_memory[i]=page_sequence[i];
		FIFO_age[i]=1;
	}
	for(i=0;i<3;i++) cout<<main_memory[i]<<endl;
	cout<<endl;
	for(i=3;i<10;) {
		for(j=0;j<3;j++) FIFO_age[j]++;
		if(page_fault(page_sequence[i])) {
			max=0;
			for(j=1;j<3;j++) if(FIFO_age[j]>FIFO_age[max]) max=j;
			main_memory[max]=page_sequence[i];
			FIFO_age[max]=0;
			for(j=0;j<3;j++) cout<<main_memory[j]<<endl;
			cout<<endl;
		}
		i++;
	}
}
