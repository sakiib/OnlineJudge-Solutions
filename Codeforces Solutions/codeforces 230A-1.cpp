#include<bits/stdc++.h>
using namespace std;

struct data {
    int st,bo;
    data(){}
    data(int st,int bo) {
        this->st=st;
        this->bo=bo;
    }
    bool operator<(const data &q) const {
        if(st==q.st) return (bo>q.bo);
        else return (st<q.st);
    }
};

vector<data> V;

int main(int argc,char const *argv[]) {
    int s,n;
    cin>>s>>n;
    for(int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        V.push_back(data(x,y));
    }
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++) {
        if(s>V[i].st){
            s+=V[i].bo;
        }
        else {
            cout<<"NO"<<endl;
            return 0;
        }
    } cout<<"YES"<<endl;
    return 0;
}
