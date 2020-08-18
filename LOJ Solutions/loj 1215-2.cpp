#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL LCM(LL x,LL y) {
    LL g=__gcd(x,y);
    LL l=x/g*y;
    return l;
}

vector<LL> prime;
vector<bool> isprime(10000010,true);
map<LL,LL> factA,factB;

void sieve() {
    isprime[0]=false,isprime[1]=false;
    prime.push_back(2);
    for(LL i=4;i<=10000010;i+=2) {
        isprime[i]=false;
    }
    LL sq=sqrt(10000010);
    for(LL i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(LL j=i*i;j<=10000010;j+=2*i) {
        isprime[j]=false;
         }
       }
    }
    for(LL i=3;i<=10000010;i+=2) {
        if(isprime[i]) prime.push_back(i);
    }
}
void prime_fact(LL lcm) {
    for(int i=0;i<prime.size()&&prime[i]*prime[i]<=lcm;i++) {
        if(lcm%prime[i]==0) {
            while(lcm%prime[i]==0) {
                factA[prime[i]]++;
                lcm/=prime[i];
            }
        }
    }
    if(lcm>1) factA[lcm]++;
    /*for(auto x:factA) {
        printf("here : %lld %lld \n",x.first,x.second);
    }*/
}
int main(int argc,char const *argv[]) {
    sieve();
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        LL a,b,l;
        scanf("%lld%lld%lld",&a,&b,&l);
        LL lcm=LCM(a,b);
        if(l%lcm!=0) {
            printf("Case %d: impossible\n",tc);
            continue;
        }
        prime_fact(lcm);
        LL ans=1;
        LL temp=l;
        for(int i=0;i<prime.size()&&prime[i]*prime[i]<=l;i++) {
            if(l%prime[i]==0) {
                while(l%prime[i]==0) {
                    l/=prime[i];
                    factB[prime[i]]++;
                }
                LL p=max(factA[prime[i]],factB[prime[i]]);
                LL b=prime[i];
                for(int j=1;j<=p;j++) {
                    ans*=b;
                }
                //cerr<<"---- : "<<ans<<endl;
            }
        }
        if(l>1) {
            factB[l]++;
            LL p=max(factA[l],factB[l]);
                LL b=l;
                for(int j=1;j<=p;j++) {
                    ans*=b;
                }
                //cerr<<"=== : "<<ans<<endl;
        }
        printf("ans : %lld\n",ans);

        factA.clear(); factB.clear();
    }
    return 0;
}
