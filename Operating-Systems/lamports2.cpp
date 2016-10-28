#include<iostream>
using namespace std;
int i,k,machines[2][10],processes[2][6];
void setup_machines() {
	for(i=1;i-1<10;i++) machines[0][i-1]=machines[1][i-1]=i;
}
void setup_processes() {
	for(i=0;i<6;i++) {
		processes[0][i]=machines[0][i];
		processes[1][i]=machines[1][i];
	}
}

void send_message(int sender,int receiver,int time_sent,int time_received) {
	for(i=0;i<6;i++) if(processes[receiver][i]==time_received) k=i;
	if(time_sent>=processes[receiver][k]) {
		machines[receiver][k]=time_sent+1;
		processes[receiver][k]=time_sent+1;
		for(i=k+1;i<6;i++) {
			machines[receiver][i]++;
			processes[receiver][i]++;
		}
	}
}

int main() {
	setup_machines();
	setup_processes();
	cout<<"Initial Timestamps of statements in the process:\n";
	cout<<"Process 0: ";
	for(i=0;i<6;i++) cout<<processes[0][i]<<" ";
	cout<<endl<<"Process 1: ";
	for(i=0;i<6;i++) cout<<processes[1][i]<<" ";
	
	send_message(1,0,1,3);
	send_message(0,1,2,2);
	send_message(1,0,6,6);
	
	cout<<"\n\nFinal Timestamps of statements in the process:\n";
	cout<<"Process 0: ";
	for(i=0;i<6;i++) cout<<processes[0][i]<<" ";
	cout<<"\nProcess 1: ";
	for(i=0;i<6;i++) cout<<processes[1][i]<<" ";
}
