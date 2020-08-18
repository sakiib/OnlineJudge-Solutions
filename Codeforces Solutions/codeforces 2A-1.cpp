#include<bits/stdc++.h>
using namespace std;

map<string,int> mp;
map<string,int> t;
int main()
{
    int n,p[100001],mx=-1000000000;
    cin>>n;
    string str[1000];

    for(int i=0;i<n;i++){
        cin>>str[i]>>p[i];
        mp[str[i]]+=p[i];
    }

    map<string,int> :: iterator it;

    for(it=mp.begin();it!=mp.end();it++){
       mx=max(mx,it->second);
    }
   // cout<<mx<<endl;
    for(int i=0;i<n;i++){
        t[str[i]]+=p[i];
        if(t[str[i]]>=mx){
            cout<<str[i]<<endl;
            return 0;
        }
    }
    return 0;
}
