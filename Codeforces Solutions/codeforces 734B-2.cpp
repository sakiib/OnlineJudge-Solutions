#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll n_2,n_3,n_5,n_6,sum=0;

    cin>>n_2>>n_3>>n_5>>n_6;

    while(n_2>0&&n_5>0&&n_6>0){

        sum+=256;
        n_2--;n_5--;n_6--;
    }

    //cout<<sum<<endl;
    //cout<<n_2<<" "<<n_5<<" "<<n_6<<endl;

    while(n_2>0&&n_3>0)
    {
        sum+=32;
        n_2--;n_3--;
    }
    cout<<sum<<endl;

    return 0;
}
