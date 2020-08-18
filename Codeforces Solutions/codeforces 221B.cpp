#include<bits/stdc++.h>
using namespace std;

vector<int> divi;
map<int,int> N,K;

void calc(int n) {
    int sq=sqrt(n);
    for(int i=1;i<=sq;i++) {
        if(n%i==0) {
            if(n/i!=i) {
                divi.push_back(n/i);
                divi.push_back(i);
            }
            else divi.push_back(i);
        }
    }
}
void digital(int n) {
    while(n) {
        int a=n%10;
        N[a]++;
        n/=10;
    }
}
bool check(int val) {
    while(val) {
        int a=val%10;
        K[a]++;
        val/=10;
    }
    for(int i=0;i<=9;i++) {
        if(N[i]>0&&K[i]>0) return true;
    }
    return false;
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    calc(n);
    digital(n);
    int ans=0;
    for(int i=0;i<divi.size();i++) {
        K.clear();
        if(check(divi[i])) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
