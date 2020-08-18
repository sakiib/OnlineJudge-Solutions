#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int d1,m1,y1;
        scanf("%d/%d/%d",&d1,&m1,&y1);
        int d2,m2,y2;
        scanf("%d/%d/%d",&d2,&m2,&y2);
        if(d1<d2) m2++;
        if(m1<m2) y2++;
        int tot=(y1-y2);
        if(tot<0) printf("Case #%d: Invalid birth date\n",tc);
        else if(tot>130) printf("Case #%d: Check birth date\n",tc);
        else printf("Case #%d: %d\n",tc,tot);
    }
    return 0;
}
