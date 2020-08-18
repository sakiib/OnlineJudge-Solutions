/********************************
*       Sakib Al-Amin           *
*   North South University      *
********************************/
#include<bits/stdc++.h>
using namespace std;
#define endl               '\n'
#define F                  first
#define S                  second
#define SQ(x)              ((x)*(x))
#define CU(x)              (x)*(x)*(x)
#define pb                 push_back
#define mp                 make_pair
#define N                  puts("NO");
#define Y                  puts("YES");
#define dll                long double
#define ll                 long long int
#define llu                unsigned long long int
#define gcd(x,y)           __gcd((x),(y))
#define lcm(x,y)           (x)/__gcd((x),(y))*(y)
#define precs(x)           setprecision(x)<<fixed
#define mx3(a,b,c)         max(a,max(b,c))
#define mn3(a,b,c)         min(a,min(b,c))
#define mx4(a,b,c,d)       max(a,mx3(b,c,d))
#define mn4(a,b,c,d)       min(a,mn3(b,c,d))
#define mx5(a,b,c,d,e)     max(a,mx4(b,c,d,e))
#define mn5(a,b,c,d,e)     min(a,mn4(b,c,d,e))
#define mxe(a,n)           (*max_element(a,a+n))
#define mne(a,n)           (*min_element(a,a+n))
#define sum(a,n)           (accumulate(a,a+n,0))
#define CLR(a)             memset(a,0,sizeof(a))
#define SET(a)             memset(a,-1,sizeof(a))
#define all(a)             (a.begin(),a.end())
#define rall(a)            (a.rbegin(),a.rend())
#define Found(a,b)         (a.find(b)!=a.end())
#define Founds(x,y)        (x.find(y)!=string::npos)
#define UB(a,key)          upper_bound(a.begin(),a.end(),key)-a.begin()
#define LB(a,key)          lower_bound(a.begin(),a.end(),key)-a.begin()
#define p_q(smaller)       priority_queue<int,vector<int>,greater<int> >
#define Fastread           ios_base :: sync_with_stdio(false); cin.tie(0)
//#######################################################################
const ll INF = 1LL*(1e15);
const ll MOD = 1LL*(1e9+7);
const int Size = 100010;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const double PII = 2*acos(0.0);
//#######################################################################
inline bool isp(int x) {
    if(x<2) return false;  int sq=sqrt(x);
    for(int i=2;i<=sq;i++) {if(x%i==0) return false;} return true;
}
inline bool leap_year(int x) {
    if(((x%4==0)&&(x%100!=0))||(x%400==0)) return true; return false;
}
inline int power(int x,int y) {
    int ret=1; for(int i=1;i<=y;i++) { ret*=x; }  return ret;
}
inline int st_int(string &str) {
    int num; stringstream st(str); st>>num; return num;
}
inline string int_st(int num) {
    string res; stringstream convert; convert<<num; res=convert.str();
    return res;
}
//########################################################################
vector<bool> isprime(1000010,true);
vector<int> prime;
void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(int i=4;i<=1000010;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(1000010);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=1000010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(int i=3;i<=1000010;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
    /*for(auto &x: prime) {
        cout<<x<< " ";
    }*/
}
//##########################################################
//#######################Let's Code#########################
//##########################################################


int main(int argc,char const *argv[]) {
    Fastread;

}


