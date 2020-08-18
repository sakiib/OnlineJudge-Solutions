#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    int ara[10010];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    int cnt=0;
    int i=1,sum=0;
    while(i<=n) {
        if(ara[i]+sum<=m) {
            sum+=ara[i]; i++;
        }
        else {
            cnt++; sum=0;
        }
    }
    if(sum<=m) cnt++;
    cout<<cnt<<endl;
}
