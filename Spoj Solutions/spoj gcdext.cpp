#include <iostream>
#include <stdio.h>
#include <math.h>
#define MAX 4000001
using namespace std;
typedef long long int ll;
ll phi[MAX];
void phi_function()
{
	phi[1] = 1;
	for(int i=2; i<=MAX; ++i)
	{
	    if(phi[i]==0)
	    {
	        phi[i]=i-1;
			for(int j=i+i; j<=MAX; j+=i)
			{
				if(phi[j]==0)   phi[j] = j;
                phi[j]= phi[j]/i * (i-1);
			}
	    }
	}
	//for( int i = 1; i <= 10; i++ ) cout << phi[i] << " ";
}
ll table[MAX];
void div()
{
    for(int i=1;i<MAX;i++)
    {
        for(int j=i+i;j<MAX;j=j+i)
        {
            table[j]+=(i*phi[j/i]);
        }
    }
    for(int i=2;i<MAX;i++) table[i]+=table[i-1];
}
int main()
{
    phi_function();
    //div();
    int n;
    while(scanf("%d",&n)==1)
    {
        if(n==0)    break;
        printf("%lld\n",table[n]);
    }
    return 0;
}
