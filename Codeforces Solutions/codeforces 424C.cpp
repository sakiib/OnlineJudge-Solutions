#include<bits/stdc++.h>
using namespace std;

struct data {
    int pop;
    double dist;
    data(){}
    data(double dist,int pop) {
        this->pop=pop;
        this->dist=dist;
    }
    bool operator<(const data &q) const {
        return (dist<q.dist);
    }
};

vector<data> V;
double get_dist(int x,int y) {
    double d=sqrt(x*x*1.0+y*y*1.0);
    return d;
}
int main(int argc,char const *argv[]) {
    int n,s;
    cin>>n>>s;
    for(int i=1;i<=n;i++) {
        int x,y,pop;
        cin>>x>>y>>pop;
        double l=get_dist(x,y);
        V.push_back(data(l,pop));
    }
    sort(V.begin(),V.end());
    /*for(int i=0;i<V.size();i++) {
        cout<<V[i].dist<<" "<<V[i].pop<<endl;
    }*/
    if(s>=1000000) {
        cout<<setprecision(7)<<fixed<<0.0<<endl;
        return 0;
    }
    bool found=false;
    double ans=0.0;
    for(int i=0;i<V.size();i++) {
        s+=V[i].pop;
        if(s>=1000000) {
            ans=V[i].dist;
            found=true;
            break;
        }
    }
    if(!found) cout<<-1<<endl;
    else cout<<setprecision(7)<<fixed<<(ans)<<endl;
    return 0;
}
