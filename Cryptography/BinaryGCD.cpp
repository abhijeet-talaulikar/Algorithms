#include<iostream>
#include<math.h>
using namespace std;

int gcd(long int a,long int b) {
    if(a<0)
        return gcd(0-a,b);
    else if(b<0)
        return gcd(a,0-b);   
    else if( (a<0) && (b<0))
        return gcd(0-a,0-b);
    else if(a==0)
        return b;
    else if(b==0)
        return a;
    else if(a==0 && b==0)
        return 0;
    else if( (a%2==0) && (b%2==0))  //both even
        return gcd(a>>1,b>>1)<<1;
    else if( (a%2==0) && (b%2==1))  //a->even,b->odd
        return gcd(a>>1,b);
    else if( (a%2==1) && (b%2==0))  //a->odd,b->even
        return gcd(a,b>>1);
    else if( (a%2==1) && (b%2==1))  //both odd
        {    if(a>=b)
                return gcd((a-b)>>1,b);
            else
                return gcd((b-a)>>1,a);
        }
    else if(a==b)
        return a;
   
}

int main(){    
    long int a,b;
    cout<<"Enter two integers:"<<endl;
    cin>>a;
    cin>>b;
    cout<<"GCD of given numbers:"<<gcd(a,b)<<endl;
    return 0;
}
