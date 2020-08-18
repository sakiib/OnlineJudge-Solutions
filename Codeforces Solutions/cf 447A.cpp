#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(int argc,char const *argv[]) {
    string str;
    cin>>str;
    int ans=0;
    for(int i=0;i<str.size();i++) {
        for(int j=i+1;j<str.size();j++) {
            for(int k=j+1;k<str.size();k++) {
                if(str[i]=='Q'&&str[j]=='A'&&str[k]=='Q') ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
