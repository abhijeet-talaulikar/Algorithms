#include<iostream>
using namespace std;
#define SIZE 3
class Job {
	public:
		int index;
		int burst_time;
		int arrival_time;
};

Job q[SIZE];
int head = 0;
int tail = -1;

void enqueue(Job a) {
	q[++tail] = a;
}

Job dequeue() {
	return q[head++];
}

int main() {
	Job j1, j2, j3;
	
	j1.index = 1;
	j1.burst_time = 24;
	j1.arrival_time = 0;
	
	j2.index = 2;
	j2.burst_time = 3;
	j2.arrival_time = 0;
	
	j3.index = 3;
	j3.burst_time = 3;
	j3.arrival_time = 0;

	enqueue(j1);
	enqueue(j2);
	enqueue(j3);
	
	int i,j;
	for(i=0;i<SIZE;i++) {
		Job current_job = dequeue();
		cout<<"Process "<<current_job.index<<" got executed for "<<current_job.burst_time<<" seconds."<<endl;
	}
	
	int total_waiting_time=0;
	for(i=0;i<SIZE;i++) {
		int waiting_time = 0;
		for(j=0;j<i;j++) {
			waiting_time +=  q[j].burst_time;
		}
		waiting_time -= q[i].arrival_time;
		total_waiting_time += waiting_time;
	}
	
	int awt = total_waiting_time/3;
	cout<<"Average Weighting Time: "<<awt<<endl;
	
	int avg_tt=0;
	for(i=0;i<SIZE;i++) {
		avg_tt += q[i].burst_time;
	}
	avg_tt /= 3;
	avg_tt += awt;
	cout<<"Average Turnaround Time: "<<avg_tt<<endl;
}
