#include<bits/stdc++.h>
using namespace std;

int mid,ret;
int solve(int val,int *ara,int low,int high) {

    while(low<=high) {
        mid=(low+high)/2;
        if(ara[mid]<val) {
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    return low;
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    ara[0]=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        ara[i]+=ara[i-1];
    }
    for(int i=1;i<=n;i++) {
        cerr<<ara[i]<< " ";
    }
    int query,val;
    cin>>query;
    while(query--) {
        cin>>val;
        cout<<solve(val,ara,1,n)<<endl;
    }
    return 0;
}
