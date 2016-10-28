#include<iostream>
using namespace std;
#define SIZE 3
int process[SIZE] = {1,0,1};
int request_times[SIZE][SIZE];
void broadcast_request(int p, int time) {
	int i;
	for(i=0;i<SIZE;i++) {
		request_times[i][p] = time;
	}
}
int main() {
	broadcast_request(0,15);
	broadcast_request(2,12);
	broadcast_request(1,20);
	int i,k=0,min=request_times[0][0];
	for(i=1;i<SIZE;i++) {
		if(request_times[0][i] && request_times[0][i]<min) {
			min=request_times[0][i];
			k=i;
		}
	}
	cout<<"Process "<<k<<" will enter CS"<<endl;
}
