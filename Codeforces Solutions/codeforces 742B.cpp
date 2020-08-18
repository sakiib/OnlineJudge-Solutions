#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ara[1000001]={0};
int main()
{
    ll n,x,num,i,j,sum=0;
    cin>>n>>x;
    while(n--)
    {
        cin>>num;
        sum+=ara[num^x];
        ara[num]++;
    }
    cout<<sum<<endl;
    return 0;
}
