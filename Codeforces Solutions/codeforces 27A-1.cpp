#include<bits/stdc++.h>
using namespace std;
map<int,bool>mp;
int main()
{
    int n,ara[100001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
        mp[ara[i]]=true;
    }
    for(int i=1;i<=30000;i++){
        if(!mp[i]){
            cout<<i;
            return 0;
        }
    }
    return 0;
}
