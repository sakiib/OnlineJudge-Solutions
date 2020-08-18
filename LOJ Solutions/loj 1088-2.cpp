#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<bitset>

#define N 100100
#define Q 50050
#define sf scanf
#define pf printf

using namespace std;

typedef long long LL;

LL ar[N];

int lowerBound(LL itm , int sz)
{
    int lo=0, hi=sz, mid;

    while(lo <= hi)
    {
        mid = (lo + hi) / 2;

        if(ar[mid] == itm) hi=mid-1;
        else if(ar[mid] > itm) hi = mid-1;
        else if(ar[mid] < itm) lo = mid+1;
    }

    return lo;
}

int uperBound(LL itm, int sz)
{
    int lo=0, hi=sz, mid;

    while(lo <= hi)
    {
        mid = (lo + hi) / 2;

        if(ar[mid] == itm) lo=mid+1;
        else if(ar[mid] < itm) lo=mid+1;
        else if(ar[mid] > itm) hi=mid-1;
    }

    return lo;
}

int main()
{
    int t , tc=0;
    sf("%d",&t);
    while(t--)
    {
        int i,n,p;
        sf("%d %d",&n,&p);

        for(i=0;i<n;i++)
        {
            sf("%lld",&ar[i]);
        }

        pf("Case %d:\n", ++tc);

        while(p--)
        {
            int low, up;
            LL x,y;
            sf("%lld %lld",&x,&y);

            low = lowerBound(x,n-1);//cout<<low << " " << endl;
            up = uperBound(y,n-1);//cout<<up<<" "<<endl;;
            pf("%d\n",up-low);
        }
    }

    return 0;
}
