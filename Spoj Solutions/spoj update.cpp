#include<bits/stdc++.h>
using namespace std;

const int N=100;
int ara[N],BIT[N];

void Update(int idx,int val) {
    while(idx<=N) {
        BIT[idx]+=val;
        idx+=(idx & -idx);
    }
}
int Query(int idx) {
    int sum=0;
    while(idx>0) {
        sum+=BIT[idx];
        idx-=(idx & -idx);
    }
    return sum;
}
int main(int argc,char const *argv[]) {
    for(int i=1;i<=5;i++) {
        scanf("%d",&ara[i]);
        Update(i,ara[i]); // Point Update
    }
    printf("%d %d %d %d %d\n",Query(1),Query(2),Query(3),Query(4),Query(5));
    //index a=1 to b=3 range 5 add kora holo
    //Range Update
    Update(1,5); // update(a,val)
    Update(4,-5); // update(b+1,-val)
    printf("%d %d %d %d %d\n",Query(1),Query(2),Query(3),Query(4),Query(5));
    return 0;
}

