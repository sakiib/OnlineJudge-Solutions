#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int sol[100010],vest[100010];
    for(int i=1;i<=n;i++) {
        cin>>sol[i];
    }
    for(int i=1;i<=m;i++) {
        cin>>vest[i];
    }
    int i=1,j=1;
    vector<pair<int,int> > V;
    while(i<=n&&j<=m) {
        if(vest[j]<sol[i]-x) j++;
        else if(vest[j]>sol[i]+y) i++;
        else {
            V.push_back(make_pair(i,j));
            i++,j++;
        }
        cerr<<"Here"<<endl;
    }
    cout<<V.size()<<endl;
    for(auto &x: V) {
        cout<<x.first<< " " <<x.second<<endl;
    }
    return 0;
}
