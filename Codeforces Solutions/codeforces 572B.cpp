#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,s;
    cin>>n>>s;

    vector<pair<int,int> > B,S;
    map<int,bool> by,se;
    map<int,int> buy,sell;
    while(n--) {
        char ch;
        int x,q;
        cin>>ch>>x>>q;
        if(ch=='B') buy[x]+=q;
        else sell[x]+=q;
    }
    for(int i=100000,r=s;i>=0&&r!=0;i--) {
        if(buy[i]>0) B.push_back({i,buy[i]}),r--;
    }
    for(int i=0,r=s;i<=100000&&r!=0;i++) {
        if(sell[i]>0) S.push_back({i,sell[i]}),r--;
    }
    reverse(S.begin(),S.end());
    for(auto &x: S) {
        cout<<"S"<< " "<< x.first<< " " <<x.second<<endl;
    }
    for(auto &x: B) {
        cout<<"B"<< " "<< x.first<< " " <<x.second<<endl;
    }
    return 0;
}
