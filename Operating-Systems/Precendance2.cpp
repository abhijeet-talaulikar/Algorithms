#include<iostream>
using namespace std;
int main() {
	int p[6] = {2,3,4,4,2,3};
	int tt[6];
	int wt[6][2];
	int adj[6][6] = {
		{0,5,4,0,0,0},
		{0,0,0,4,3,0},
		{0,0,0,0,3,2},
		{0,0,0,0,0,5},
		{0,0,0,0,0,5},
		{0,0,0,0,0,0}
	};
	int i,j,max;
	for(j=0;j<6;j++) {
		max=0;
		for(i=0;i<6;i++) if(adj[i][j]) if((tt[i]+adj[i][j])>max) max = tt[i]+adj[i][j];
		tt[j]=max+p[j];
		wt[j][0]=j;
		wt[j][1]=tt[j]-p[j];
	}

	for(i=0;i<5;i++) for(j=i+1;j<6;j++) {
		int temp[2];
		if(wt[i][1]>wt[j][1]) {
			temp[0]=wt[j][0];
			temp[1]=wt[j][1];
			wt[j][0]=wt[i][0];
			wt[j][1]=wt[i][1];
			wt[i][0]=temp[0];
			wt[i][1]=temp[1];
		}
	}
	cout<<"Order of execution: ";
	for(i=0;i<6;i++) cout<<wt[i][0]+1<<" ";
	cout<<endl;
	cout<<"Process\tTurnaround Time\tWaiting Time"<<endl;
	for(i=0;i<6;i++) cout<<i+1<<"\t\t"<<tt[i]<<"\t"<<tt[i]-p[i]<<endl;
	cout<<"Total completion time = "<<tt[5]<<endl;
}
