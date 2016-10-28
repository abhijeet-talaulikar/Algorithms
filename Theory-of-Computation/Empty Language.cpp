#include<iostream>
using namespace std;
int p,q,nostates;
int visited[10];
char startstate;
int nofinalstates;
char finalstates[10];
int adjacency[10][10];
char states[10];
int visitedfinalstates[10];
int countfinalstates=0;
void operation(int i) {
	for(int p=0;p<nofinalstates;p++) if(states[i]==finalstates[p]) visitedfinalstates[p]=1;
	for(int j=0;j<nostates;j++) {
		if(adjacency[i][j]==1 && i !=j && visited[j] !=1) {  //not taking the visited nodes again
			visited[j]=visited[j]+1;
			operation(j);
		}
	}	
}

int main() {   
	cout<<"enter the total number of states "<<endl;
	cin>>nostates;
	
	for(int i=0;i<nostates;i++) {
		cout<<"Enter the state "<<i+1<<endl;
		cin>>states[i];
	}
	cout<<"Enter the adjacency table of 0's and 1's (i.e 2 D matrix) according to the order of states that you have entered "<<endl;
	for(int i=0;i<nostates;i++) {
		for(int j=0;j<nostates;j++) {
			cout<<"does "<<states[i]<<" have transition to  "<<states[j]<<endl;
			cin>>adjacency[i][j];
		}
	}
	
	cout<<"Enter the start state "<<endl;
	cin>>startstate;
	cout<<"Enter total number of final states "<<endl;
	cin>>nofinalstates;
	for(int i=0;i<nofinalstates;i++) {
		cout<<"Enter final state number"<<i+1<<endl;
		cin>>finalstates[i];
	}
	
	for(int i=0;i<nostates;i++) {
		if(states[i]==startstate) {
			p=i;
			break;
		}
	}
	for(int i=0;i<nostates;i++) visited[i]=0; //initialising all visited elements to 0
	for(int i=0;i<nostates;i++) visitedfinalstates[i]=0;
	visited[p]=1;
	operation(p);
	for(int p=0;p<nofinalstates;p++) if(visitedfinalstates[p]==1) countfinalstates++;
	if(countfinalstates==nofinalstates) cout<<"Language is not empty"<<endl;
	else cout<<"Language is empty "<<endl;
	return 0;
}
