#include<bits/stdc++.h>
using namespace std;

int parent[100005];
bool found;

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
    if(u!=v) parent[u]=v;
}
bool query(int a,int b) {
    int u=Find(a);
    int v=Find(b);
    if(u==v) return true;
    else return false;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    scanf("\n");
    for(int tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        makeset(n);
        cin.ignore();
        int suc=0,un=0;
        for(int i=1; ;i++) {
            string str; int a,b;
            char c;
            if(!getline(cin,str) || str.empty()) break;
            sscanf(str.c_str(),"%c %d %d",&c,&a,&b);

            switch(c) {
                found=false;
                case 'c' : Union(a,b);
                break;
                case 'q' : found=query(a,b);
                if(found) suc++;
                else un++;
            }
        }
        printf("%d,%d\n",suc,un);
        if(tc!=t) printf("\n");
    }
    return 0;
}
