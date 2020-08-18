#include<bits/stdc++.h>
using namespace std;

int a,b,k;
vector<int> isprime(1000010,1);

void sieve() {
    isprime[0]=0,isprime[1]=0;
    for(int i=4;i<=1000010;i+=2) {
        isprime[i]=0;
    }
    int sq=sqrt(1000010);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
        for(int j=i*i;j<=1000010;j+=2*i) {
        isprime[j]=0;
         }
       }
    }
    for(int i=1;i<=1000005;i++) {
        isprime[i]+=isprime[i-1];
    }
    //cout<<isprime[2]<<" "<<isprime[3]<<endl;
}
bool check(int m,int k) {
    for(int i=a;i<=(b-m+1);i++) {
        if(isprime[m+i-1]-isprime[i-1]<k)
        return false;
    }
    return true;
}
int bin_search(int lo,int hi,int k) {
    int l=lo,h=hi;
    int mid;
    int ret=-1;
    while(l<=h) {
        mid=(l+h)>>1;
        if(check(mid,k)) {
            ret=mid;
            h=mid-1;
        } else l=mid+1;
    }
    return ret;
}
int main(int argc,char const *argv[]) {
    sieve();
    cin>>a>>b>>k;
    int ans=bin_search(1,b-a+1,k);
    cout<<ans<<endl;
    return 0;
}
