#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    if(n==1||n==2) {
        cout<<-1<<endl;
        return 0;
    }
    for(int i=n;i>=1;i--) {
        cout<<i<< " ";
    }
    return 0;
}
