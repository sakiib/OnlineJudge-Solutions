#include<bits/stdc++.h>
using namespace std;

int ara[100005];
int tree[4*100005];

void build(int node,int b,int e) {
    if(b==e) {
        tree[node]=ara[b];
        return;
    }
    int left=2*node; int right=left+1; int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);

}
int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    build(1,1,n);
    for(int i=1;i<=10;i++) {
        cout<<i<<" "<<tree[i]<<endl;
    }
}
