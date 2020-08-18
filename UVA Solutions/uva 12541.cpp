#include<bits/stdc++.h>
using namespace std;

struct info {
    string name;
    int day,month,year;
    info () {}
    info(string s,int d,int m,int y) {
        name=s, day=d, month=m, year=y;
    }
    bool operator < (const info &q) const {
        if(year==q.year) return (month<q.month);
        else if(month==q.month) return (day<q.day);
        return (year<q.year);
    }
};

int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    vector<info> V;
    string str;
    int d,m,y;
    for(int i=1;i<=n;i++) {
        cin>>str>>d>>m>>y;
        V.push_back(info(str,d,m,y));
    }
    sort(V.begin(),V.end());
    int k=V.size()-1;
    cout<<V[k].name<<endl;
    cout<<V[0].name<<endl;
    return 0;
}
