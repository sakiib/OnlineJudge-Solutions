#include<bits/stdc++.h>
using namespace std;

int coin[]={50,25,10,5,1};
int ans[100010];

void calc() {
    ans[0]=1;
    for(int i=0;i<5;i++) {
        for(int j=coin[i];j<=8000;j++) {
            ans[j]+=ans[j-coin[i]];
        }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    calc();
    while(scanf("%d",&n)!=EOF) {
        cout<<ans[n]<<endl;
    }
    return 0;
}
