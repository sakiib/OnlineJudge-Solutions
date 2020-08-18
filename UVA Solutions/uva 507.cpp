#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int val[N];

int main(int argc,char const *argv[]) {
    freopen( "input.txt" , "r" , stdin );
    freopen( "output.txt" , "w" , stdout );
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        int sum=0;
        int mx=0;
        int st=1,en=-1,temp=1;
        for(int i=1;i<n;i++) {
            scanf("%d",&val[i]);
            sum+=val[i];
            if(sum<0) sum=0,temp=i+1;
            if(sum>mx||(sum==mx&&i-temp>en-st)) {
                mx=sum;
                st=temp,en=i;
            }
        }
        if(mx==0) printf("Route %d has no nice parts\n",tc);
        else printf("The nicest part of route %d is between stops %d and %d\n",tc,st,en+1);
    }
    return 0;
}
