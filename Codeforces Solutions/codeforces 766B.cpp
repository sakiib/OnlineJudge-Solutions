#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
const double eps = 1e-6;
const int SIZE = 100000005;
const int Size = 100005;
const int MOD = 1000000007;
const double PI = 2*acos(0.0);
const long long INF = 214738360000;
typedef long long int LL;
typedef unsigned long long int LLU;
LL upper(LL target);
LL n,ara[1000001];
int main()
{
    LL i,sum=0,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    sort(ara,ara+n);
    for(i=0;i<n-2;i++)
    {
        if(ara[i]+ara[i+1]>ara[i+2])
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    /*for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
          sum+=upper(ara[i]+ara[j]-1)-j-1;
        }
    }
    if(sum==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;*/
    return 0;
}

LL upper(LL target)
{
    LL low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=high-(high-low)/2;
        if(ara[mid]==target) return (mid+1);
        else if(ara[mid]<target) low=mid+1;
        else high=mid-1;
    }
    return low;
}




