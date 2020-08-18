#include<bits/stdc++.h>
using namespace std;

int mx=-1e6;
int mn=1e6;
int ans=0;

int main(){
    int n;
    cin>>n;
    int ara[100005];
    for(int i=0;i<n;i++){
        cin>>ara[i];
        mx=max(mx,ara[i]);
        mn=min(mn,ara[i]);
    }
    if(mx==ara[0]&&mn==ara[n-1]){
        cout<<0<<endl;
        return 0;
    }
    bool a=false;
    for(int i=0;i<n;i++){
        if(mx==ara[i]){
           int j=i;
           a=true;
           while(j!=0){
             swap(ara[j],ara[j-1]);
             j--;
             ans++;
           }
        }
        if(a) break;
    }
    /*for(int i=0;i<n;i++){
        cout<<ara[i]<< " ";
    }*/
    bool f=false;
    for(int i=n-1;i>=0;i--){
        if(ara[i]==mn){
           int j=i;
           f=true;
           while(j!=n-1){
             swap(ara[j],ara[j+1]);
             j++; ans++;
           }
        }
        if(f) break;
    }
    /*for(int i=0;i<n;i++){
        cout<<ara[i]<< " ";
    }*/
    cout<<ans<<endl;
    return 0;
}
