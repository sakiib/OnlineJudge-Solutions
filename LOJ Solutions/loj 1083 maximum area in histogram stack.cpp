#include<bits/stdc++.h>
using namespace std;

int ara[100010];

int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) {
            scanf("%d",&ara[i]);
        }
        stack<int> S;
        int mx=0;
        int top;
        int area_top;
        int i=0;
        while(i<n) {
            if(S.empty()||(ara[S.top()]<=ara[i])) {
                S.push(i++);
            }
            else {
                top=S.top();
                S.pop();
                if(S.empty()) {
                    area_top=ara[top]*i;
                }
                else {
                    area_top=ara[top]*(i-S.top()-1);
                }
                mx=max(mx,area_top);
            }
        }
        while(!S.empty()) {
            top=S.top();
            S.pop();
            if(S.empty()) {
                area_top=ara[top]*i;
            }
            else {
                area_top=ara[top]*(i-S.top()-1);
            }
            mx=max(mx,area_top);
        }
        printf("Case %d: %d\n",tc,mx);
    }
    return 0;
}
