#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

map<ll,ll>mymap;
ll power[100001];

void power_gen()
{
    power[0]=1;
    for(int i=1;i<=32;i++){
        power[i]=power[i-1]*2;
    }
    /*
    for(int i=1;i<=32;i++){
        cout<<power[i]<<" ";
    }
   */
}

int main()
{
    ios_base::sync_with_stdio(false);

    power_gen();

    ll n,num,sum=0;
    cin>>n;
    while(n--){
        cin>>num;
        for(int i=1;i<=32;i++){
            sum+=mymap[power[i]-num];
        }
        mymap[num]++;
    }

    cout<<sum<<endl;
    return 0;
}
