#include<bits/stdc++.h>
using namespace std;
int a[1000]={0};
int main()
{
    int n,k,ara[100005],ans=0,one=0,two=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    for(int i=0;i<k;i++){
            one=0,two=0;
        for(int j=i;j<n;j+=k){
            if(ara[j]==1) one++;
            else two++;
        }
        ans+=min(one,two);
    }
    cout<<ans;
    return 0;
}
