#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,string> M;

int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int a,b;
        string name;
        scanf("%d%d",&a,&b);
        cin>>name;
        M[make_pair(a,b)]=name;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(!M.count(make_pair(a,b))) cout<<"(puzzled)"<<endl;
        else cout<<M[make_pair(a,b)]<<endl;
    }
    return 0;
}
