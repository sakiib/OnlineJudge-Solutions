#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int a,b,k;
    cin>>a>>b>>k;
    int mn_l=1;
    int mx_l=(b-a+1);
    int mn_x=a;
    int mx_x=(b-mx_l+1);
    cout<<mn_l<<" "<<mx_l<<" "<<mn_x<<" "<<mx_x<<endl;
    return 0;
}
