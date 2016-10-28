#include<iostream>
using namespace std;

int num_jobs=6;
int jobs_size[6]={212,15,125,175,20,125};
int jobs_burst[6]={15,12,5,20,12,15};
int jobs_active[6];
int j; //next process index

//main memory
int num_partitions=5;
int partitions[5][4] ={
{91,302,0,NULL},
{303,320,0,NULL},
{321,375,0,NULL},
{376,450,0,NULL},
{451,526,0,NULL},
};
//end main memory

int sum_bt() {
	int i,sum=0;
	for(i=0;i<num_jobs;i++) sum+=jobs_burst[i];
	return sum;
}

int first_fit(int j) {
	for(int i=0;i<num_partitions;i++) if((partitions[i][1]-partitions[i][0]-jobs_size[j]+1)>=0 && !partitions[i][2]) return i;
	return num_partitions+1;
}

int main() {
	int i,k,z,time,progress=0;
	cout<<"MFT: ";
	int sum_burst=sum_bt();
	for(time=0;time<=sum_burst;time++) {
		z=0;
		for(i=0;i<num_jobs;i++) {
			if(jobs_active[i]) jobs_burst[i]--;
			if(jobs_burst[i]==0) {
				if(jobs_active[i]) {
					cout<<"\n\nTime: "<<time<<endl;
					cout<<"J"<<i<<" completed at "<<time<<"s\n";
				}
				for(k=0;k<num_partitions;k++) {
					if(partitions[k][3]==i) {
						partitions[k][2]=0;
						partitions[k][3]=NULL;
						jobs_active[i]=0;
						break;
					}
				}
			}
		}
		for(j=progress;j<num_jobs;) {
			i=first_fit(j);
			if(i!=num_partitions+1) {
				partitions[i][2]=1;
				partitions[i][3]=j;
				if(!z) cout<<"\n\nTime: "<<time<<endl;
				cout<<"J"<<j<<" has occupied partition ["<<partitions[i][0]<<","<<partitions[i][1]<<"]\n";
				z++;
				jobs_active[j]=1;
				j++;
				progress=j;
			} else break;
		}
	}
}
