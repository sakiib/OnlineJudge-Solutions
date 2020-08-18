#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,ara[100001],grass=0;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    mp[0]++;
    for(int i=0;i<str.size();i++){
        if(str[i]=='>'&&grass==i){
            grass=grass+ara[i];
            if(grass>=str.size()){
                cout<<"FINITE"<<endl;
                return 0;
            }
           else mp[grass]++;
        }
        else if(str[i]=='<'&&grass==i){
            grass=grass-ara[i];
            if(grass<0){
                cout<<"FINITE"<<endl;
                return 0;
            }
            else mp[grass]++;
        }
    }
    if(str[grass]=='<'){
        grass=grass-ara[grass];
        if(grass<0){
            cout<<"FINITE"<<endl;
            return 0;
        }
        else mp[grass]++;
    }
    else if(str[grass]=='>'){
        grass=grass+ara[grass];
        if(grass>=str.size()){
            cout<<"FINITE"<<endl;
            return 0;
        }
        mp[grass]++;
    }
    map<int,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        if(it->second>=2){
            cout<<"INFINITE"<<endl;
            return 0;
        }
    }
    cout<<"FINITE"<<endl;
    return 0;
}
