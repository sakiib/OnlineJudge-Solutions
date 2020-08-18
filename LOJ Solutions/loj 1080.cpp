#include<bits/stdc++.h>
using namespace std;

char str[100005];
int tree[100005*4];

void Update(int Node,int b,int e,int i,int j) {
    if(i>e||j<b) return;
    if(b>=i&&e<=j) {
        tree[Node]++;
        return;
    }
    int Left=2*Node;
    int Right=2*Node+1;
    int mid=(b+e)/2;
    Update(Left,b,mid,i,j);
    Update(Right,mid+1,e,i,j);
    return;
}
int Query(int Node,int b,int e,int x) {
    if(x>e||x<b) return 0;
    if(b==e) {return tree[Node];}
    int Left=2*Node;
    int Right=2*Node+1;
    int mid=(b+e)/2;
    int p1=Query(Left,b,mid,x);
    int p2=Query(Right,mid+1,e,x);
    return (p1+p2)+tree[Node];
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        for(int i=1;i<=350005;i++) {
            tree[i]=0;
        }
        scanf("%s",str);
        int n=strlen(str)+1;
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",tc);
        while(q--) {
            char s;
            scanf(" %c",&s);
            if(s=='I') {
                int l,r;
                scanf("%d%d",&l,&r);
                Update(1,1,n,l,r);
                for(int i=1;i<=20;i++) {
                    cout<<tree[i]<<" ";
                }
                cout<<endl;
            } else if(s=='Q') {
                int x;
                scanf("%d",&x);
                int k=Query(1,1,n,x);
                if(k%2==0) {
                    printf("%c\n",str[x-1]);
                } else {
                    if(str[x-1]=='1') printf("0\n");
                    else printf("1\n");
                }
            }
        }
    }
    return 0;
}
