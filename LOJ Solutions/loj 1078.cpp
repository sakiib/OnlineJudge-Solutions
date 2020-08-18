#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,tc,a,b;
    cin>>t;
    for(tc=1;tc<=t;tc++){
        cin>>a>>b;
        int ans=1;
        int c=b;
        int temp=10;
        while(b%a!=0){
            b=(b*temp+c)%a;
            ans++;
        }
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
