#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    set<int> P,V;
    map<int,int> M;
    for(int i=1;i<=n;i++) {
        int val;
        cin>>val;
        M[val]++;
    }
    if(M.size()!=2) {
        cout<<"NO"<<endl;
        return 0;
    }
    map<int,int> :: iterator it1,it2;
    it1=M.begin(); it2=M.begin();
    it2++;
    if(it1->second==it2->second) {
        cout<<"YES"<<endl;
        cout<<it1->first<<" "<<it2->first<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
