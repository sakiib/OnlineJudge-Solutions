#include <bits/stdc++.h>
#include<stdio.h>
using namespace std ;
int main()
{
	int n;
	scanf("%d",&n);
	int i, temp, mx=1, freq[100001]={0}, ans=1, j;

	for(i=0;i<n;i++)
    {
		scanf("%d",&temp);
		freq[temp]++;
		if(temp>mx)
        {
			mx=temp;
		}
	}
	for(i=2; i<=mx; ++i)
    {
		temp=0;
		for(j=i; j<=mx; j+=i)
		{
			temp+=freq[j];
		}
		//cout<<temp<<endl;
		if(temp>ans) ans=temp;
	}

	printf("%d",ans);
	return 0;
}
