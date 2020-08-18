#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    stack<char> S;
    int ans=0;
    int cnt[100010];
    int mx=0;
    for(int i=0;i<str.size();i++) {
        if(str[i]=='(') S.push('(');
        else if(str[i]==')') {
            if(!S.empty()) {
                if(S.top()=='(') S.pop(),ans+=2;
            }
        }
        if(!S.empty()&&S.top()==')') {
            mx=max(mx,ans);
            ans=0;
            cnt[mx]++;
        }
    }
    if(mx==0) printf("0 1\n");
    else printf("%d %d\n",mx,cnt[mx]);
    return 0;
}
