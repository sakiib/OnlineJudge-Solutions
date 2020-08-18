#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int ara[10];
    int sum=0;
    int cnt[1000]={0};
    for(int i=1;i<=5;i++) {
        cin>>ara[i];
        cnt[ara[i]]++;
        sum+=ara[i];
    }
    int mx=0;
    for(int i=1;i<=5;i++) {
        if(cnt[ara[i]]>=2) {
            if(cnt[ara[i]]>3) cnt[ara[i]]=3;
            mx=max(mx,cnt[ara[i]]*ara[i]);
        }
    }
    cout<<sum-mx<<endl;
    return 0;
}
