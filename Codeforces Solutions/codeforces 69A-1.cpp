#include<bits/stdc++.h>
using namespace std;

struct point{
    int x,y,z;
}A[10000];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i].x>>A[i].y>>A[i].z;
    }
    int a=0,b=0,c=0;
    for(int i=0;i<n;i++){
        a+=A[i].x;
        b+=A[i].y;
        c+=A[i].z;
    }
   // cout<<a<< " "<<b<< " "<<c;
   (a==0&&b==0&&c==0)? puts("YES"):puts("NO");
   return 0;
}
