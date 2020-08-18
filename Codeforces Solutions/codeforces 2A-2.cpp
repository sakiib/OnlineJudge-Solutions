#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    map<string,int> M,N;
    vector<pair<string,int> > keep;
    while(n--) {
        string str;
        int sc;
        cin>>str;
        cin>>sc;
        M[str]+=sc;
        keep.push_back(make_pair(str,sc));
    }
    int mx=0;
    map<string,int> :: iterator it;
    for(it=M.begin();it!=M.end();it++) {
        mx=max(mx,it->second);
    }
    /*cerr<<"Mx :"<<mx<<endl;
    for(it=M.begin();it!=M.end();it++) {
        cout<<it->first<< " " <<it->second<<endl;
    }*/
    vector<string> V;
    for(it=M.begin();it!=M.end();it++) {
        if(it->second==mx) {
            V.push_back(it->first);
        }
    }
    /*for(int i=0;i<V.size();i++) {
        cout<<V[i]<<endl;
    }*/
    for(int i=0;i<keep.size();i++){
        N[keep[i].first]+=keep[i].second;
        if(N[keep[i].first]>=mx&&M[keep[i].first]==mx) {
            cout<<keep[i].first<<endl;
            return 0;
        }
    }
    return 0;
}
