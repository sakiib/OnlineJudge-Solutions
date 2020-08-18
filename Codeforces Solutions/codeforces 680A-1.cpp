#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main()
{
    int n=5,num,ans,mn=0,sum=0;
    while(n--){
        cin>>num;
        sum+=num;
        mp[num]++;
    }
    map<int,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        if(it->second>=2){
            if(it->second>3) it->second=3;
            ans=it->first*it->second;
            mn=max(ans,mn);
        }
    }
    cout<<sum-mn;
    return 0;
}
