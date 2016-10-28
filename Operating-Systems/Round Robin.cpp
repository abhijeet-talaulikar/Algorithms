#include<iostream>
using namespace std;
struct process{char name;int at,bt,tt,rt;int completed;int wtt;} p[10];
int n,i,j;
void sortByArrival(){
	struct process temp;
	for(i=0;i<n-1;i++) for(j=i+1;j<n;j++) if(p[i].at>p[j].at){temp=p[i];p[i]=p[j];p[j]=temp;}
}

int main(){
	int time=0,sum_bt=0,tq,sw=0;
	char c;
	cout<<"Enter no of processes:";
 	cin>>n;
 	for(i=0,c='A';i<n;i++,c++){
		 p[i].name=c;
		 cout<<"\nEnter the arrival time of process "<<p[i].name<<": ";
		 cin>>p[i].at;
		 cout<<"\nEnter the burst time of process "<<p[i].name<<": ";
		 cin>>p[i].bt;
		 p[i].rt=p[i].bt;
		 p[i].completed=0;
		 sum_bt+=p[i].bt;
	}
	cout<<"\nEnter the time quantum:";
	cin>>tq;
	sortByArrival();
	cout<<"Execution order: ";
	for(i=0,time=0;time<sum_bt;){
		if(!p[i].completed && p[i].at<=time) {
			if(p[i].rt<=tq){
				time+=p[i].rt;
				p[i].completed=1;
				p[i].rt=0;
				cout<<" "<<p[i].name<<" ";
				p[i].tt=time-p[i].at;
				p[i].wtt=p[i].tt-p[i].bt;
			} else {
				time+=tq;
				p[i].rt-=tq;
				cout<<" "<<p[i].name<<" ";
			}
		}
		i=(i+1)%(n+1);
	}
	cout<<"\nName\tArrival Time\tBurst Time\tTA Time\t  Waiting Time";
	for(i=0;i<n;i++){
		cout<<"\n"<<p[i].name<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].tt<<"\t\t"<<p[i].wtt;
		sw+=p[i].wtt;
		if(i==(n-1)) cout<<"\nAvg Waiting time:"<<sw/n<<"\n";
	}
}
