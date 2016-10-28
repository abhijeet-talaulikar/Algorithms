#include<iostream>
#include<string.h>
using namespace std;

int main() {
   string input; //maximum string of length 10 can be entered
   int num_DFA,num_symbols,inputlength,nofinalstates,startstate,count=0,p,q;
   cout<<"Enter the string you want to test "<<endl;
   cin>>input;
   cout<<"Enter the number of states "<<endl;
   cin>>num_DFA;
   char states[num_DFA];
   cout<<"Use distinct letters to represent the states "<<endl;
   for(int i=0;i<=(num_DFA-1);i++) {
   	cout<<"enter "<<i+1<<"th state"<<endl;
   	cin>>states[i];
   }
   cout<<"Enter the number of symbols "<<endl;
   cin>>num_symbols;
   char symbols[num_symbols];
   for(int i=0;i<=(num_symbols-1);i++) {
   	cout<<"Enter "<<i+1<<"th symbol"<<endl;
   	cin>>symbols[i];
   }
   char tt_DFA[num_DFA][num_symbols];
   for(int i=0;i<num_DFA;i++) {
   	for(int j=0;j<num_symbols;j++) {
   		cout<<"Enter the transition of "<<states[i]<<" on "<<symbols[j]<<endl;
   		cin>>tt_DFA[i][j];
	   }
   }
   
   cout<<"Enter the start state "<<endl;
   cin>>startstate;
   cout<<"Enter the number of final states "<<endl;
   cin>>nofinalstates;
   char finalstates[nofinalstates];
   for(int i=0;i<nofinalstates;i++) {
   	cout<<"Enter "<<i+1<<" th final state "<<endl;
   	cin>>finalstates[i];
   }
   
   inputlength=input.length();
   
   for(int i=0;i<=(inputlength-1);i++) {
   	     for(int j=0;j<=(num_DFA-1);j++) {
   		if(states[j]==startstate){
   			p=j;
   			break;
		}
	   }
	   
	   for(int j=0;j<=(num_symbols-1);j++){
	   	if(input[i]==symbols[j]){
	   		q=j;
	   		break;
		}
	   }
       	   startstate=tt_DFA[p][q]; //after transition the symbol which we get is made temporary start state 		
   }
   for(int i=0;i<nofinalstates;i++) {
	   if(startstate==finalstates[i]) { 
	   	cout<<"String entered is accepted."<<endl;
	   	count++;
	   }  
   }
   if(!count) {
   	cout<<"String entered is rejected"<<endl;
   }
   return 0; 
}
