#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int ara[N];
map<int,int> M;

struct segment {
    int sum,idx;
} tree[4*N];

void merge_node(int l,int r) {
    M[ara[l]]++; M[ara[r]]++;

}
void build(int node,int b,int e) {
    if(b==e) {
        tree[node].idx=b;
        if(ara[b]==1) tree[node].sum=1;
        else tree[node].sum=0;
        return;
    }
    int left=2*node; int right=2*node+1;
    int mid=(b+e)/2;
    build(left,b,mid); build(right,mid+1,e);
    //cout<<left<<" "<<b<<" "<<mid<<" "<<ara[b]<<" "<<ara[mid]<<endl;
    //cout<<right<<" "<<mid+1<<" "<<e<<" "<<ara[mid+1]<<" "<<ara[e]<<endl;
    merge_node(tree[left].idx,tree[right].idx);
    //tree[node].sum=tree[left].sum+tree[right].sum;
}
int main(int argc,char const *argv[]){
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    build(1,1,n);
    return 0;
}
