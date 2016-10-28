#include<iostream>
using namespace std;
int main() {
	int p[7] = {10,20,25,5,15,15,20};
	int tt[7];
	int adj[7][7] = {
		{0,1,1,0,0,0,0},
		{0,0,0,1,1,0,0},
		{0,0,0,0,0,0,1},
		{0,0,0,0,0,1,0},
		{0,0,0,0,0,1,0},
		{0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0}
	};
	int i,j,max;
	for(j=0;j<7;j++) {
		max=0;
		for(i=0;i<7;i++) if(adj[i][j]) if(tt[i]>max) max = tt[i];
		tt[j]=max+p[j];
	}
	cout<<"Total completion time = "<<tt[6]<<endl;
}
