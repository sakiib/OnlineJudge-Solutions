#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll a,b,c,d,k,start,finish,ans=0;
    cin>>a>>b>>c>>d>>k;
    start=max(a,c);
    finish=min(b,d);
    if(start>finish){
        cout<<0<<endl;
        return 0;
    }
    if(k>=start&&k<=finish){
        cout<<finish-start<<endl;
        return 0;
    }
    else{
        cout<<finish-start+1<<endl;
        return 0;
    }
    return 0;
}
