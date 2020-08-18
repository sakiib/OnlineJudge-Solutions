#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
string s[1010];
int sco[1010];
map<string,int> mp;
map<string,int> t;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>s[i]>>sco[i];
        mp[s[i]]+=sco[i];
    }
    int maxn=-1;

    for(int i=0;i<n;++i)
        maxn=max(maxn,mp[s[i]]);

    for(int i=0;i<n;++i)
    {
        t[s[i]]+=sco[i];
        if(mp[s[i]]>=maxn && t[s[i]]>=maxn)
        {
            cout<<s[i]<<endl;
            break;
        }
    }
    return 0;
}
