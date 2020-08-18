#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
    int i,a[1000],b[1000];
    string str;
	cin>>str;
	for(i=0;i<str.size();i++)
	{
		if(str[i]=='!') a[i%4]++;
		else b[str[i]]=i%4;
	}
	printf("%d %d %d %d\n",a[b['R']],a[b['B']],a[b['Y']],a[b['G']]);
	return 0;
}
