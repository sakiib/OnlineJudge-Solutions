#include<bits/stdc++.h>
using namespace std;

int n;
int A,B,C;

int main(int argc,char const *argv[]) {
    cin>>n;
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=n;j++) {
            int num;
            cin>>num;
            if(i==1) A+=num;
            if(i==2) B+=num;
            if(i==3) C+=num;
        }
        n--;
    }
    cerr<<A<<" "<<B<<" "<<C<<endl;
    cout<<A-B<<endl<<B-C<<endl;
    return 0;
}
