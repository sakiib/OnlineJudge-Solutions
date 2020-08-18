#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,tc;
    cin>>t;
    for(tc=1;tc<=t;tc++){
        string str;
        long long int x;
        long long int sum=0;
        cin>>str>>x;
        if(x<0) x*=(-1);
        for(int i=0;i<str.size();i++){
            if(str[i]=='-') continue;
            sum+=str[i]-'0';
            if(sum>=x) sum%=x;
            if(i!=str.size()&&sum<x) sum*=10;
            else if(i==str.size()&&sum>x) sum%=x;
        }
        if(sum==0) printf("Case %lld: divisible\n",tc);
        else printf("Case %lld: not divisible\n",tc);
    }
    return 0;

}
