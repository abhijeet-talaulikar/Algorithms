#include<iostream>
using namespace std;

int process_pages=6;
int page_map_table[6]={3,7,11,9,5,4};
int frame_size=200;
int main_memory=2200;

int physical_address(int logical_address) {
	return (page_map_table[logical_address]-1)*frame_size;
}

int main() {
	cout<<"PROCESS:\n";
	for(int i=0;i<6;i++) cout<<"Page "<<i<<" is placed inside frame ("<<physical_address(i)<<","<<physical_address(i)+frame_size<<")\n";
}
