#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    while(cin>>str&&str!="."){
        map<char,int>mp;
        int mx=0;
        for(int i=0;i<str.size();i++){
            mp[str[i]]++;
        }
        map<char,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            mx=max(mx,it->second);
        }
        cout<<mx<<endl;
    }
    return 0;
}
