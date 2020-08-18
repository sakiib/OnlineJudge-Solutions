#include<bits/stdc++.h>
using namespace std;

int parent[100];

void makeset(int n) {
    for(int i=1;i<=n;i++) {
        parent[i]=i;
    }
}
int Find(int x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a);
    int v=Find(b);
    if(u==v) return;
    parent[u]=v;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
        string str;
        cin>>str;
        int c=str[0]-'A'+1;
        makeset(c);
        string s;
        cin.ignore();
        int tot=c;
        while(getline(cin,s)&&s[0]) {
            int a=s[0]-'A'+1;
            int b=s[1]-'A'+1;
            if(Find(a)!=Find(b)) {
                tot--;
                Union(a,b);
            }
        }
        printf("%d\n",tot);
        if(t!=0) printf("\n");
    }
    return 0;
}
