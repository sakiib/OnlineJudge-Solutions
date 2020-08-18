#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const  int inf = 1e9;
const  LL INF = 1e18;
const  int N = 100005;
const  int MOD = 1e9+7;
const  double EPS = 1e-6;
const  double PI = acos(-1.0);

#define FOR1(i,a,b)     for(int i=a; i<=b ;i++)
#define FOR0(i,a)       for(int i=0; i<a ;i++)
#define CLR(a,n)        FOR0(i,n) a[i].clear()
#define MEM(a,x)        memset(a, x ,sizeof(a))

#define scanI(a)        scanf("%d",&a)
#define scanI2(a,b)     scanI(a), scanI(b)
#define scanI3(a,b,c)   scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)

#define scanL(a)        scanf("%lld",&a)
#define scanL2(a,b)     scanL(a), scanL(b)
#define scanL3(a,b,c)   scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)

#define Read            freopen("input.txt", "r" ,stdin)
#define Write           freopen("output.txt", "w" ,stdout)


vector<pair<int,string> > taxi,pizza,girl;

map<string,int> M;

struct data {
    string name;
    int idx;

    bool operator<(const data &q) const {
        if(idx!=q.idx) return (idx<q.idx);
    }
};

int t=0,p=0,g=0;

void process(string s) {
    string str="";
    str+=s.substr(0,2)+s.substr(3,2)+s.substr(6,2);
    if(str[0]==str[1]&&str[1]==str[2]&&str[2]==str[3]&&
       str[3]==str[4]&&str[4]==str[5]) {
        t++; return;
    }
    for(int i=0;i<str.size()-1;i++) {
        if(str[i]>str[i+1]) continue;
        else {
            g++; return;
        }
    }
    p++;
}
int main(int argc,char const *argv[]) {
    int n; cin>>n;
    for(int i=1;i<=n;i++) {
        int k; cin>>k;
        string str; cin>>str;
        M[str]=i;
        p=0,t=0,g=0;
        for(int j=1;j<=k;j++) {
            string s;
            cin>>s;
            process(s);
        }
        pizza.push_back({p,str});
        taxi.push_back({t,str});
        girl.push_back({g,str});
    }
    sort(pizza.rbegin(),pizza.rend());
    sort(taxi.rbegin(),taxi.rend());
    sort(girl.rbegin(),girl.rend());

    vector<data> pi,tax,gi;

    int mxtaxi=taxi[0].first;
    for(int i=0;i<taxi.size();i++) {
        if(taxi[i].first==mxtaxi)
        tax.push_back({taxi[i].second,M[taxi[i].second]});
        else break;
    }
    int mxpizza=pizza[0].first;

    for(int i=0;i<pizza.size();i++) {
        if(pizza[i].first==mxpizza)
        pi.push_back({pizza[i].second,M[pizza[i].second]});
        else break;
    }
    int mxgirl=girl[0].first;

    for(int i=0;i<girl.size();i++) {
        if(girl[i].first==mxgirl)
        gi.push_back({girl[i].second,M[girl[i].second]});
        else break;
    }
    cout<<"If you want to call a taxi, you should call: ";
    sort(tax.begin(),tax.end());
    for(int i=0;i<tax.size();i++) {
        if(i==0) cout<<tax[i].name;
        else cout<<", "<<tax[i].name;
    }
    cout<<"."<<endl;

    sort(pi.begin(),pi.end());
    cout<<"If you want to order a pizza, you should call: ";
     for(int i=0;i<pi.size();i++) {
        if(i==0) cout<<pi[i].name;
        else cout<<", "<<pi[i].name;
    }
    cout<<"."<<endl;

    sort(gi.begin(),gi.end());
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
    for(int i=0;i<gi.size();i++) {
        if(i==0) cout<<gi[i].name;
        else cout<<", "<<gi[i].name;
    }
    cout<<"."<<endl;
    return 0;
}



