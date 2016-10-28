#include<iostream>
using namespace std;

int n;

struct process {
	char name;
	int at;
	int bt;
	int tt;
	int rt;
	int completed;
	int wt;
} p[10];

int current;

int SRJ(int time) {

	if(p[current].completed) {
		int min,i;
		for(i=0;i<n;i++) if(!p[i].completed) min=i;
		for(i=0;i<n;i++) {
			if(p[i].completed) continue;
			if(p[i].rt<p[min].rt) min=i;
		}
		current=min;
		return 1;
	}

	int temp=current;
	for(int i=1;i<n;i++) if(p[i].rt<p[current].rt && p[i].at<=time && !p[i].completed) current=i;
	if(temp==current) return 0;
	else return 1;
}

void sortByArrival(){
	struct process temp;
	for(int i=0;i<n-1;i++) for(int j=i+1;j<n;j++) if(p[i].at>p[j].at){temp=p[i];p[i]=p[j];p[j]=temp;}
}

int main() {
	int i,k,time,sum_bt=0;
	char c;
	cout<<"Enter number of processes:";
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
		 p[i].wt=0;
	}
	sortByArrival();
	current=0;
	k=1;
	cout<<"Execution order: ";
	for(time=p[0].at;time<sum_bt+p[0].at;) {

		for(i=0;i<n;i++) if(i!=current && time>=p[i].at && !p[i].completed) p[i].wt++;

		if(k) cout<<p[current].name<<" ";
		p[current].rt--;
		time++;
		if(!p[current].rt) {
			p[current].completed=1;
			p[current].tt=time-p[current].at;
		}
		k=SRJ(time);
	}
	cout<<endl;
	cout<<"Process\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time"<<endl;
	for(i=0;i<n;i++) cout<<p[i].name<<"\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].tt<<"\t\t"<<p[i].wt<<endl;
	cout<<endl;
}
