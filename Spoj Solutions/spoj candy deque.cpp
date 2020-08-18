#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);

    for(int tc=1;tc<=t;tc++) {
        int n,k;
        scanf("%d%d",&n,&k);
        deque<int> Q;
        int mx=0;
        for(int i=1;i<=n;i++) {
            int val;
            scanf("%d",&val);
            Q.push_back(val);
            if((int)Q.size()==k) {
                deque<int> :: iterator it;
                it=max_element(Q.begin(),Q.end());
                mx=*it;
                printf("%d ",mx);
                Q.pop_front();
            }
        } printf("\n");
    }
    return 0;
}
