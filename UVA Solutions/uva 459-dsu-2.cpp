#include<bits/stdc++.h>
using namespace std;

int par[100];

void makeset(int n) {
    for(int i=1;i<=n;i++) par[i]=i;
}
int Find(int x) {
    return (par[x]==x)? x : par[x]=Find(par[x]);
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
        string str;
        cin>>str;
        int tot=str[0]-'A'+1;
        makeset(tot);
        string s;
        cin.ignore();
        while(getline(cin,s)&&s[0]) {
            int u=s[0]-'A'+1;
            int v=s[1]-'A'+1;
            int x=Find(u);
            int y=Find(v);
            if(x!=y) {
                tot--;
                par[x]=y;
            }
        }
        printf("%d\n",tot);
        if(t!=0) printf("\n");
    }
    return 0;
}
