#include<iostream>
using namespace std;
int adj[12][12]={{0,1,0,0,0,0,0,0,0,0,0,0},
				  {0,0,1,0,0,0,0,0,0,0,0,0},
				  {0,0,0,1,0,0,0,0,0,0,0,0},
				  {0,0,0,0,1,0,0,0,0,0,0,0},
				  {0,0,0,0,0,1,0,0,0,0,0,0},
				  {0,0,0,0,0,0,1,0,0,0,0,0},
				  {0,0,0,0,0,0,0,1,0,0,0,0},
				  {0,0,0,0,0,0,0,0,1,0,0,0},
				  {0,0,0,0,0,0,0,0,0,1,0,0},
				  {0,0,0,0,0,0,0,0,0,0,1,0},
				  {0,0,0,0,0,0,0,0,0,0,0,1},
				  {1,0,0,0,0,0,0,0,0,0,0,0}};

int traverse(int start, int sender, int receiver) {
	cout<<"<"<<start<<", "<<sender<<", "<<receiver<<">"<<endl;
	if(start==receiver) return 0;
	for(int j=0;j<12;j++) if(adj[receiver][j]) return traverse(start,receiver,j);
}

int initiate(int start) {
	for(int j=0;j<12;j++) if(adj[start][j]) if(!traverse(start,start,j)) return 0;
	return 1;
}

int main() {
	if(!initiate(1)) cout<<"Cycle detected";
	else cout<<"No cycle detected";
}
