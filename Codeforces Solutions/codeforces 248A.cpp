#include<bits/stdc++.h>
using namespace std;

struct door{
    int left,right;
}A[100010];
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int lo=0,lc=0,ro=0,rc=0;
    for(int i=0;i<n;i++) {
       cin>>A[i].left>>A[i].right;
       if(A[i].left==0) lo++; else lc++;
       if(A[i].right==0) ro++; else rc++;

    }
    cout<<min(lo,lc)+min(ro,rc)<<endl;
    return 0;
}
