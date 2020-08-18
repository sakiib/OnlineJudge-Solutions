#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[10000];
    for(int i=0;i<n;i++) {
        cin>>ara[i];
    }
    int r=0,l=n-1;
    int x=0,y=0;
    int turn=1;
    while(r<=l) {
       if(turn&1) {
         if(ara[r]>ara[l]) {
            x+=ara[r]; r++;
         }
         else x+=ara[l],l--;
       }
       else {
         if(ara[r]>ara[l]) {
            y+=ara[r]; r++;
         }
         else y+=ara[l],l--;
       }
       turn++;
    }
    cout<<x<< " " <<y<<endl;
    return 0;
}
