#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll n,ara[100001];

ll upper_search(ll low,ll high,ll res)
{
    ll mid;
    while(low<=high){
        mid=(high+low)/2;
        if(ara[mid]==res) return (mid+1);
        else if(ara[mid]<res) low=mid+1;
        else high=mid-1;
    }
    return low;
}

int main()
{
    ll i,t,taka,count=0,ans;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    sort(ara,ara+n);
    cin>>t;

    while(t--){
        count=0;
        cin>>taka;
        ans=upper_search(0,n-1,taka);
        //ans=upper_bound(ara,ara+n,taka)-ara;
        cout<<ans<<endl;
    }
    return 0;
}


