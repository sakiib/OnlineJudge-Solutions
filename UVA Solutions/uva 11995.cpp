#include<bits/stdc++.h>
using namespace std;

stack<int> S;
queue<int> Q;
priority_queue<int> P;

void reset() {
    while(!S.empty()) S.pop();
    while(!Q.empty()) Q.pop();
    while(!P.empty()) P.pop();
}
int main(int argc,char const *argv[]) {
    int n;
    while(scanf("%d",&n)!=EOF) {
        int s=1, q=1, p=1;
        int op, val;
        reset();
        for(int i=1;i<=n;i++) {
            scanf("%d",&op);
            if(op==1) {
                scanf("%d",&val);
                S.push(val);
                Q.push(val);
                P.push(val);
            }
            else if(op==2) {
                scanf("%d",&val);
                if(S.empty()||S.top()!=val) s=0;
                else S.pop();
                if(Q.empty()||Q.front()!=val) q=0;
                else Q.pop();
                if(P.empty()||P.top()!=val) p=0;
                else P.pop();
            }
        }
        if(s+q+p>1) printf("not sure\n");
        else if(s+q+p==0) printf("impossible\n");
        else if(s==1) printf("stack\n");
        else if(p==1) printf("priority queue\n");
        else printf("queue\n");
    }
    return 0;
}
