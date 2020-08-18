#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    if(n==1||m==1) {
        cout<<"Akshat"<<endl;
    }
    else if(n==m&&n%2==0) {
        cout<<"Malvika"<<endl;
    }
    else if(n==m&&n%2==1) {
        cout<<"Akshat"<<endl;
    }
    else {
        if(min(m,n)%2==1) {
            cout<<"Akshat"<<endl;
        }
        else cout<<"Malvika"<<endl;
    }
    return 0;
}
