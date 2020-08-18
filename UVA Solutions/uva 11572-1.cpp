#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        set<int> S;
        queue<int> Q;
        int n;
        scanf("%d",&n);
        int l=0,r=0,mx=0;
        for(int i=1;i<=n;i++) {
            int val;
            scanf("%d",&val);
            if(S.find(val)==S.end()) { //age ashe nai
                r++;
                mx=max(mx,r-l);
                S.insert(val);
                Q.push(val);
            }
            else {
                while(true) {
                    l++;
                    int f=Q.front();
                    if(val==f) {
                        Q.pop(); break;
                    }
                    else {
                        S.erase(f);
                        Q.pop();
                    }
                }
                r++;
                Q.push(val);
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
