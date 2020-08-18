#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ara1[200010];
ll up_find(ll num,ll x)
{
    ll low=0,high=x,mid;
    while(low<=high){
        mid=(high+low)/2;
        if(ara1[mid]==num) low=mid+1;
        else if(ara1[mid]<num) low=mid+1;
        else if(ara1[mid]>num) high=mid-1;
    }
    return low;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll m,n,num,ans;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>ara1[i];
    }
    sort(ara1,ara1+m);
    while(n--){
        cin>>num;
       // ans=upper_bound(ara1,ara1+m,num)-ara1;
        ans=up_find(num,m-1);
        cout<<ans<< " ";
    }
    cout<<endl;
    return 0;
}
