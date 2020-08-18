#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<string>
#define pi acos(-1)
#define mod 10000007

using namespace std;
int main()
{

	char s[1232];
	int c[100]={0};
	int i;
	int l[1289];
	scanf("%s",s);
	int n=strlen(s);
	for(i=0;i<n;i++)
	{
		if(s[i]=='!')
		{
			c[i%4]++;
		}
		else
		{
			l[s[i]]=i%4;
		}
	}
	printf("%d %d %d %d\n",c[l['R']],c[l['B']],c[l['Y']],c[l['G']]);

    return 0;
}



