#include<iostream>
#include<cmath>
using namespace std;
#define symbols 2 //Assume 0 and 1

//NFA configuration
#define num_NFA 3 //Assume A,B,C

/*
Sample NFA:
The set of strings beginning with 0 and ending with 1

Conceptual Transition Table:
State	0	1
A	{B}	{}
B	{B}	{B,C}
C	{}	{}

Boolean Transition Table:
State	0	1
A	{0,1,0}	{0,0,0}
B	{0,1,0}	{0,1,1}
C	{0,0,0}	{0,0,0}
*/

int tt_NFA[num_NFA][symbols][num_NFA] = {
{{0,1,0},{0,0,0}},
{{0,1,0},{0,1,1}},
{{0,0,0},{0,0,0}}
};
//end NFA

//DFA trackers
int num_DFA=0; //this will keep a count of the accessible states encountered
int max_DFA=pow(2,num_NFA); //max 2^num_NFA states in the resulting DFA
int states_DFA[8][num_NFA]; //each state is a subset of max num_NFA states
int tt_DFA[8][symbols][num_NFA];
//end DFA

int encountered(int state[]) {
	int i,j,k;
	for(i=0;i<max_DFA;i++) {
		k=0;
		for(j=0;j<num_NFA;j++) if(states_DFA[i][j]==state[j]) k++;
		if(k==num_NFA) return 1;
	}
	return 0;
}

int* get_transition(int index,int state[], int x) {
	int i,j,k;
	static int new_state[num_NFA];
	for(i=0;i<num_NFA;i++) if(state[i]) for(j=0;j<num_NFA;j++) if(tt_NFA[i][x][j]) new_state[j]=1;
	for(k=0;k<num_NFA;k++) tt_DFA[index][x][k]=new_state[k];
	return new_state;
}

void traverse_DFA(int state[]) {
	int j;
	if(!encountered(state)) {
		++num_DFA;
		for(j=0;j<num_NFA;j++) states_DFA[num_DFA][j]=state[j];
		//traverse recursively through its transitions at different symbols
		for(j=0;j<symbols;j++) traverse_DFA(get_transition(num_DFA,state,j));
	}
}

void nfa2dfa() {
	int i,j,start_state[num_NFA]={1,0,0};
	for(j=0;j<num_NFA;j++) states_DFA[0][j]=0; //Trap state
	traverse_DFA(start_state);
	cout<<endl<<num_DFA<<" accessible states(and a trap state) in the DFA given below:\n";
	for(i=0;i<=num_DFA;i++) {
		char c='A';
		cout<<"{";
		for(j=0;j<num_NFA;j++) if(states_DFA[i][j]) cout<<(char)(c+j);
		cout<<"}";
		cout<<endl;
	}
}

int main() {
	int i,j,k;
	cout<<"NFA:\n";
	char c,q='A';
	cout<<"State\t0\t1"<<endl;
	for(i=0;i<num_NFA;i++) {
		cout<<(char)(q+i)<<"\t";
		for(j=0,c='A';j<symbols;j++) {
			cout<<"{";
			for(k=0;k<num_NFA;k++) if(tt_NFA[i][j][k]) cout<<(char)(c+k);
			cout<<"}\t";
		}
		cout<<endl;
	}
	nfa2dfa();
	cout<<"\nDFA:\n";
	cout<<"State\t0\t1"<<endl;
	for(i=0;i<=num_DFA;i++) {
		cout<<"{";
		for(k=0;k<num_NFA;k++) if(states_DFA[i][k]) cout<<(char)(c+k);
		cout<<"}";
		cout<<"\t";
		for(j=0,c='A';j<symbols;j++) {
			cout<<"{";
			for(k=0;k<num_NFA;k++) if(tt_DFA[i][j][k]) cout<<(char)(c+k);
			cout<<"}\t";
		}
		cout<<endl;
	}
}
