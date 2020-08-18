#include<bits/stdc++.h>
using namespace std;
int L[1000005],R[1000005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,ara[100005],mx=0,mn=2000000000;
    int x,y;
    memset(L,0,sizeof(L));
    memset(R,0,sizeof(R));
    cin>>n;
    map<int,int> M;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        M[ara[i]]++;
    }
    map<int,int> :: iterator it;
    for(it=M.begin();it!=M.end();it++){
        mx=max(mx,it->second);
    }
    //cout<<mx<<endl;
    for(int i=1;i<=n;i++){
        if(M[ara[i]]==mx&&!L[ara[i]]){
            L[ara[i]]=i;
        }
    }
    for(int i=n;i>=1;i--){
        if(M[ara[i]]==mx&&!R[ara[i]]){
            R[ara[i]]=i;
            if(R[ara[i]]-L[ara[i]]<mn){
                x=L[ara[i]];
                y=R[ara[i]];
                mn=R[ara[i]]-L[ara[i]];
            }
        }
    }
    cout<<x<<" "<<y<<endl;
    return 0;

}
