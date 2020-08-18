#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll n,ara[100001];
    cin>>n;

    vector<ll> P,N;

    for(int i=1;i<=n;i++){
        cin>>ara[i];

        if(ara[i]<0) N.push_back(ara[i]);
        else P.push_back(ara[i]);
    }

    if(N.size()==0){

        ll mn=ara[0]=ara[n+1]=200000000000;

        for(int i=1;i<=n;i++){

            ll mn=20000000000000;

            mn=min(abs(ara[i]-ara[i-1]),abs(ara[i]-ara[i+1]));
            ll mx=max(abs(ara[i]-ara[1]),abs(ara[i]-ara[n]));

            cout<<mn<< " "<<mx<<endl;
        }
        return 0;
    }
    if(P.size()==0){

        ara[0]=ara[n+1]=200000000000;

        for(int i=1;i<=n;i++){

            ll mn=min(abs(ara[i]-ara[i-1]),abs(ara[i]-ara[i+1]));
            ll mx=max(abs(ara[i]-ara[1]),abs(ara[i]-ara[n]));
            cout<<mn<< " "<<mx<<endl;
        }
        return 0;

    }
    else{

        ara[0]=ara[n+1]=20000000000000;
        for(int i=1;i<=n;i++){

            ll mn=min(abs(ara[i]-ara[i-1]),abs(ara[i]-ara[i+1]));
            ll mx=max(abs(ara[i]-ara[1]),abs(ara[i]-ara[n]));
            cout<<mn<< " "<<mx<<endl;
        }
        return 0;
    }

  return 0;
}
