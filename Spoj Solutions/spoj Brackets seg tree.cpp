#include<bits/stdc++.h>
using namespace std;

char str[30005];

struct segment {
    int open,close,match;
}tree[4*30005];

void build(int node,int b,int e) {
    if(b==e) {
        if(str[b]=='(') tree[node].open=1;
        else tree[node].close=1;
        tree[node].match=0;
        return;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].match=min(tree[left].open,tree[right].close);
    tree[node].open=tree[left].open+tree[right].open-tree[node].match;
    tree[node].close=tree[left].close+tree[right].close-tree[node].match;
}
void update(int node,int b,int e,int pos) {
    if(pos>e||pos<b) return;
    if(b==e&&b==pos) {
        if(str[b]=='(') {
            str[b]=')';
            tree[node].open--;
            tree[node].close++;
        }
        else {
            str[b]='(';
            tree[node].open++;
            tree[node].close--;
        }
        return;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    update(left,b,mid,pos);
    update(right,mid+1,e,pos);
    tree[node].match=min(tree[left].open,tree[right].close);
    tree[node].open=tree[left].open+tree[right].open-tree[node].match;
    tree[node].close=tree[left].close+tree[right].close-tree[node].match;
}
int main(int argc,char const *argv[]) {
    int n,tc=1;
    while(scanf("%d",&n)!=EOF ) {
    scanf("%s",str);
    int len=strlen(str);
    build(1,0,len-1);
    int q;
    scanf("%d",&q);
    printf("Test %d:\n",tc++);
    while(q--) {
        int op;
        scanf("%d",&op);
        if(op==0) {
            if(tree[1].open==0&&tree[1].close==0) printf("YES\n");
            else printf("NO\n");
        }
        else {
            update(1,0,len-1,op-1);
        }
      }
      memset(tree,0,sizeof(tree));
    }
    return 0;
}
