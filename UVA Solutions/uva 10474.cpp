#include<bits/stdc++.h>
using namespace std;

const int N=10005;
int ara[N];

int Binary_Search(int val,int n) {
    int lo=1,hi=n;
    int pos=-1;
    while(lo<=hi) {
        int mid=(lo+hi)>>1;
        if(ara[mid]>=val) {
            if(ara[mid]==val) pos=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }
    return pos;
}
int main(int argc,char const *argv[]) {
    int n,q;
    int tc=1;

    while(scanf("%d%d",&n,&q)) {
        if(n==0&&q==0) break;

        for(int i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
        }
        sort(ara+1,ara+n+1);
        printf("CASE# %d:\n",tc++);
        while(q--) {
            int val;
            scanf("%d",&val);
            int pos=Binary_Search(val,n);
            if(pos==-1) printf("%d not found\n",val);
            else printf("%d found at %d\n",val,pos);
        }
    }
    return 0;
}
