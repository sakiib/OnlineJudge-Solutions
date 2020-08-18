#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll bin_dec(ll x)
{
    ll sum=0,i=0,a;

    while(x!=0){
        a=x%10;
        sum+=(a*(1<<i));
        x=x/10;
        i++;
    }
   // cout<<sum<<endl;
    return sum;
}
int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    ll t,tc,A[1001],B[10001];
    cin>>t;

    for(tc=1;tc<=t;tc++){

        scanf("%lld.%lld.%lld.%lld",&A[0],&A[1],&A[2],&A[3]);
        scanf("%lld.%lld.%lld.%lld",&B[0],&B[1],&B[2],&B[3]);

        B[0]=bin_dec(B[0]);
        B[1]=bin_dec(B[1]);
        B[2]=bin_dec(B[2]);
        B[3]=bin_dec(B[3]);

        if(A[0]==B[0]&&A[1]==B[1]&&A[2]==B[2]&&A[3]==B[3])
            printf("Case %lld: Yes\n",tc);
        else
            printf("Case %lld: No\n",tc);
    }
    return 0;
}
