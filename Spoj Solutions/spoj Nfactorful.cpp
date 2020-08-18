#include<bits/stdc++.h>
using namespace std;
int ans[1000010]={0};
void primefact(int num) {
    int temp=num;
    int cnt=0;
    if(num%2==0) cnt++;
    while(num%2==0) {
        num=num/2;
    }
    for(int i=3;i<=sqrt(num);i+=2) {
        if(num%i==0) {
            cnt++;
        }
        while(num%i==0) {
            num=num/i;
        }
    }
    if(num>1) cnt++;
    ans[num]=cnt;
}
void calc() {
    for(int i=1;i<=1000000;i++) {
        primefact(i);
    }
}
int main(int argc,char const *argv[]) {
    int t;
    calc();
    cin>>t;
    while(t--) {
        int a,b,n;
        cin>>a>>b>>n;
        int res=0;
        for(int i=a;i<=b;i++) {
            if(ans[i]==n) res++;
        }
        cout<<res<<endl;
    }
    return 0;
}
