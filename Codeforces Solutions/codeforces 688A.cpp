#include<bits/stdc++.h>
using namespace std;
bool win=false;
vector<int>v;
int main()
{
    int opp,days,ans=0,maxs=-1;
    cin>>opp>>days;
    string str;
    while(days--){
        cin>>str;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0'){
               ans++; win=true; break;
            }
        }
        if(!win){
            v.push_back(ans);
            ans=0;
        }
        win=false;
    }
    v.push_back(ans);
    for(int i=0;i<v.size();i++){
        maxs=max(maxs,v[i]);
    }
    cout<<maxs<<endl;
    return 0;
}
