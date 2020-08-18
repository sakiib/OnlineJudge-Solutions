#include<bits/stdc++.h>
using namespace std;

int ara[10000100]={0};
int cnt[10000100]={0};
bool used[10000100];
int val[10000100]={0};

int main(int argc,char const *argv[]) {

    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
        cnt[ara[i]]++;
    }
    for(int i=2;i<=10000000;i++) {
        if(!used[i]) {
            for(int j=i;j<=10000000;j+=i) {
                val[i]+=cnt[j];
                used[j]=true;
            }
        }
    }
    /*for(int i=2;i<=10;i++) {
        cout<<val[i]<<" ";
    }*/
    for(int i=2;i<=10000000;i++) {
        val[i]+=val[i-1];
    }
    /*for(int i=2;i<=20;i++) {
        cout<<val[i]<<" ";
    }*/
    int q;
    scanf("%d",&q);
    while(q--) {
        int l,r;
        scanf("%d%d",&l,&r);
        l=min(l,10000000);
        r=min(r,10000000);
        printf("%d\n",val[r]-val[l-1]);
    }
    return 0;
}
