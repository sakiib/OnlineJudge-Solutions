#include<bits/stdc++.h>
using namespace std;

int parent[100005];

void makeset(int n) {
    for(int i=1;i<=n;i++) {
        parent[i]=i;
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int n,e;
        makeset(n);
        scanf("%d%d",&n,&e);
        int ans=0;
        for(int i=1;i<=e;i++) {
           int op,a,b;
           scanf("%d",&op);
           if(op==1) {
            scanf("%d%d",&a,&b);
            if(a>n||b>b) {
                ans++; continue;
            }
            else {

            }
           }
           else {

           }
        }
    }
    return 0;
}
