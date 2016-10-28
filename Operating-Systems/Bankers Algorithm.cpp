#include<iostream>
using namespace std;

int Allocation[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}},
    Max[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}},
    Available[3]={3,3,2},
    Need[5][3];
void initialize_needs() {
    int i,j;
    for(i=0;i<5;i++) for(j=0;j<3;j++) Need[i][j]=Max[i][j]-Allocation[i][j];
}
int safe() {
    int i,j,k,c,d,flag,Work[3],Finish[5];
    for(i=0;i<5;i++) Finish[i]=0;
    for(i=0;i<3;i++) Work[i]=Available[i];
    for(i=0,k=0,d=0;k!=5&&d<10;i=(i+1)%5,d++) {
        flag=1;
        for(j=0;j<3;j++) if(Need[i][j]>Work[j]) flag=0;
        if(flag && !Finish[i]) {
	    k++;
            Finish[i]=1;
            for(j=0;j<3;j++) {Work[j]+=Allocation[i][j];Need[i][j]=0;}
            cout<<"\n\nStep "<<k<<": Process "<<i<<" executed"<<endl;
            cout<<"\nAvailable: "<<endl;
            for(j=0;j<3;j++) cout<<Work[j]<<" ";
	    cout<<"\nReleased: "<<endl;
            for(j=0;j<3;j++) cout<<Allocation[i][j]<<" ";
	    cout<<"\nNeed: "<<endl;
            for(c=0;c<5;c++) {for(j=0;j<3;j++) cout<<Need[c][j]<<" ";cout<<endl;}
        }
    }
    if(5-k) {cout<<endl<<5-k<<" processes were unfinished\n";return 0;}
    else return 1;
}
int bankers(int process,int A,int B,int C) {
    int Request[3]={A,B,C},flag=1,i;
    for(i=0;i<3;i++) if(Request[i]>Need[process][i]) flag=0;
    if(flag) for(i=0;i<3;i++) if(Request[i]>Available[i]) flag=0;
    if(flag) {
	for(i=0;i<3;i++) {
		Available[i]-=Request[i];
		Allocation[process][i]+=Request[i];
		Need[process][i]-=Request[i];
	}
    }
    if(!safe()) {
        for(i=0;i<3;i++) {
		Available[i]+=Request[i];
		Allocation[process][i]-=Request[i];
		Need[process][i]+=Request[i];
	}
        return 0;
    } else return 1;
}
int request_resources(int process,int A,int B,int C) {
    return bankers(process,A,B,C);
}
int main() {
    int i,j;
    initialize_needs();
    if(!request_resources(0,0,0,0)) cout<<"Therefore, Allocation unsuccessful\n";
    else cout<<"Allocation successful\n";
}
