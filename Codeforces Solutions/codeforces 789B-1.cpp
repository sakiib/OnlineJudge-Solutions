#include<bits/stdc++.h>
#include<stdio.h>
typedef long long int ll;
typedef unsigned long long int llu;
using namespace std;
stack<int>mysti;
stack<char>mystc;
vector<ll>myvec;
map<string,int>mymapsi;
map<string,string>mymapss;
map<int,int>mymapii;
map<ll,ll>mymapll;
int main()
{
    long long b,q,l,m,ans=0,x;
	cin>>b>>q>>l>>m;
	while(m--)
	{
	    cin>>x;
		mymapll[x]=1;
	}
	for(int i=0;i<1000;i++)
	{
		if(abs(b)>l)
			break;
		if(!mymapll[b])
        ans++;

		b*=q;
	}
	if(ans<500)
    cout<<ans;
	else
    cout<<"inf";

  return 0;
}



