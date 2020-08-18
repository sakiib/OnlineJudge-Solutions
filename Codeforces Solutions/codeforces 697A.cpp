#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll start,interval,eat,n;
    cin>>start>>interval>>eat;
    if(start==eat||interval==0){
        cout<<"YES"<<endl;
        return 0;
    }
    if(eat<start){
        cout<<"NO"<<endl;
        return 0;
    }

    if(eat<interval&&eat>start){
        cout<<"NO"<<endl;
        return 0;
    }
    else{
        ll a=start+interval;
        n=(eat-a)/interval+1;
        //cout<<n<<endl;
        //cout<<eat<<endl;
        //cout<<a+(n-1)*interval<<endl;
        if(((a+(n-1)*interval)==eat)||(a+(n-1)*interval)==eat-1)
        {
            cout<<"YES"<<endl; return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
