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
int main()
{
  ll n,m,k,ans=1,cnt=1;
  cin >> n >> m >> k;
	m-=n;
	while(m>0)
    {
		if(k+ans<=n)
		{
		    cnt++;
        }
		if(k-ans>=1)
		{
		    cnt++;
        }
		m-=cnt;
		ans++;
	}
	  cout<<ans;
      return 0;
}


