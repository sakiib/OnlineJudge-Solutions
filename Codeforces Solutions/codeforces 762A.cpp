#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<string>
#define pi acos(-1)
#define mod 1000000007
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef long long int ll;
using namespace std;

int main(){
	ll n,i,k,count=0,q=0ll,a[32000];

	scanf("%I64d%I64d",&n,&k);

	for(i=1;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			a[q]=i;
			q++;
		if(n/i!=i)
            count=count+2;
		else if (n/i==i)
		 count=count+1;
		}
	}


	if(count<k)
	  printf("-1\n");
	else if(k<=count/2)
        printf("%I64d\n",a[k-1]);
	else if(k>count/2)
	   printf("%I64d\n",n/a[count-k]);
    return 0;
}


