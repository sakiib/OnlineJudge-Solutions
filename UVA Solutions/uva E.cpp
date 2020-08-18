#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> V(100000000);

bool check(ll num) {
    while(num!=0) {
        int x=num%10;
        if(x==4) return false;
        num=num/10;
    }
    return true;
}
int main(int argc,char const *argv[]) {
    int k=1;
    for(ll i=1;i<=100000;i++) {
        if(check(i)) V.push_back(i);
    }

}
