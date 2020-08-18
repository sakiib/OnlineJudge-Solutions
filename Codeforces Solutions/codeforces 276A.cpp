#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(int argc,char const *argv[]) {
    ll n,k,ans=0,mx=-9999999999999999999999;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int t,f;
        cin>>f>>t;
        if(t>k){
            ans=f-(t-k);
        }
        else{
            ans=f;
        }
        mx=max(mx,ans);
    }
    cout<<mx<<endl;
    return 0;
}
