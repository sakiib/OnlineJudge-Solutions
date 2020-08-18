#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector< pair<ll,ll> >myvec;

int main()
{
    ll n,l,r,left=0,right=0,beauty,index=0,check;
    ll sur,sul;

    cin>>n;

    for(int i=0;i<n;i++){

        cin>>l>>r;
        left+=l; right+=r;
        myvec.push_back({l,r});
    }
   /* for(int i=0;i<n;i++){

        cout<<myvec[i].first<< " " <<myvec[i].second<<endl;
    }*/
    beauty=abs(left-right);

    for(int i=0;i<n;i++){

        sul=left;sur=right;
        sul-=myvec[i].first;
        sul+=myvec[i].second;
        sur-=myvec[i].second;
        sur+=myvec[i].first;
        check=abs(sul-sur);

        if(check>beauty){
            index=i+1;
            beauty=check;
        }
    }
    cout<<index<<endl;
    return 0;
}
