#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int ara[]={6,2,5,5,4,5,6,3,7,6};

ll digit(ll number)
{
    ll ret=0;
    while(number!=0){
        ret+=ara[number%10];
        number=number/10;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll a,b,ans=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        ans+=digit(i);
    }
    cout<<ans<<endl;
    return 0;
}
