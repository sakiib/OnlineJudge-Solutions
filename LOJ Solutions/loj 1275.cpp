#include<bits/stdc++.h>
using namespace std;
int ara[20000005];
int main()
{
    int t,tc,N,C,T,P,ans;
    cin>>t;
    for(tc=1;tc<=t;tc++){
        T=0;
        cin>>N>>C;
        ara[0]=T*(C-T*N);
        for(int i=1;i<=1000;i++){
            ara[i]=i*(C-i*N);
            cout<<ans<< " ";

        }
        for(int i=0;i<=1000;i++){
            if(ara[i]>=ara[i+1]){
                ans=i;
                break;
            }
        }
       printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}

