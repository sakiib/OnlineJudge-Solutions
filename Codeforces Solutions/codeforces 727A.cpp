#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
LL n,t;
bool check=false;
vector<int> ans;

void rec(LL x){
    //if(x>t) return;
    ans.push_back(x);
    if(x==t) {
        printf("YES\n");
        cout<<(int)(ans.size())<<endl;
        for(auto x:ans) {
            cout<<x<<" ";
        } exit(0);
    }
    if(x<t) {
    rec(x*2);
    rec(10*x+1);
    }
    ans.pop_back(); //last jeta chilo oita fele dibe//
}
int main(int argc,char const *argv[]) {
    scanf("%lld%lld",&n,&t);
    rec(n);
    printf("NO\n");
    return 0;
}
