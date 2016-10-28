#include<iostream>
using namespace std;
int queue[5];
int MAX=5;
int front=-1;
int rear=-1;
int k=0;
void produce();
void consume();
  int main()
{
	int choice;
	while(1)
	{	
		cout<<"1.produce "<<endl;
		cout<<"2.consume "<<endl;
		cout<<"3.exit "<<endl;
		cout<<"enter your choice"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				produce();
				break;
			case 2:
			    consume();
				break;
		    case 3:
		    	exit(1);
		    default:
			    cout<<"invalid choce "<<endl;			
		}
	}
	return 0;	
}
 void produce()
  {
  	if(front==-1 && rear==-1) 
  	{
  		front=0;
  		rear=0;
  		queue[rear]=k;
  		cout<<"item produced is "<<queue[rear]<<endl;
  		k++;
  		return ;
	}
	if(front != -1 && rear!=(MAX-1 ) && (rear!=front-1))
	{
	 rear++;
	 queue[rear]=k;
	 cout<<"item produced is "<<queue[rear]<<endl;
	 k++;	
	 return ;
	}
	if(front !=0 && rear==(MAX-1))
	{
		rear=0;
		queue[rear]=k;
		cout<<"item produced is "<<queue[rear]<<endl;
		k++;
		return ;	
	}
	if((front==0 && rear==(MAX-1)) || rear==(front-1))
	{
		cout<<"the queue is full producer has to wait for the consumer "<<endl;
		return ;
	}
	
  }
  
  void consume()
  {
	if(front==rear && front!=-1 && rear!=-1)
	{
		cout<<"the item consumed is "<<queue[front]<<endl;
		front=-1;
		rear=-1;
		return ;
	}
	if(front==-1 && rear==-1)
	{
		cout<<"all items are over consumer has to wait for the producer the produce an item "<<endl;
		return ;
	}
	  if(front !=(MAX-1))
	{
		cout<<"item consumed is "<<queue[front]<<endl;
		front++;
		return ;
	}
	else
	{
		cout<<"item consumed is "<<queue[front]<<endl;
		front=0;
		return ;
	}
  }
  
  
  
