#include<bits/stdc++.h>
using namespace std;

int main(int agrc,char const *argv[]) {
    string str;
    cin>>str;
    int ans=0,i,j;
    for(i=0;i<str.size(); ) {
        if(str[i]=='C') {
            int cnt=0;
            while(str[i]=='C') {
                i++;
                cnt++;
                if(cnt>=5) break;
            }
            ans++;
        }
        if(str[i]=='P') {
           int cn=0;
           while(str[i]=='P') {
               i++;
               cn++;
               if(cn>=5) break;
           }
           ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
