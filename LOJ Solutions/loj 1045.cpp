#include<bits/stdc++.h>
using namespace std;

double fact_digit[1000010];

void calc() {
    for(int i=1;i<=1000000;i++) {
        fact_digit[i]=log10(i)+fact_digit[i-1];
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    calc();
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n,b;
        scanf("%d%d",&n,&b);
        //cout<<floor(fact_digit[n])+1<<endl;
        int ans=floor(fact_digit[n]/(log10(b)))+1;
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
