#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    string col="ROYGBIV";
    string s1="G"; string s2="GB"; string s3="YGB";
    string s4="YGBI"; string s5="OYGBI"; string s6="OYGBIV";
    int t=n/7;
    int k=n%7;
    for(int i=1;i<=t;i++) {
        cout<<col;
    }
    switch(k) {
        case 1: cout<<s1<<endl;
                break;
        case 2: cout<<s2<<endl;
                break;
        case 3: cout<<s3<<endl;
                break;
        case 4: cout<<s4<<endl;
                break;
        case 5: cout<<s5<<endl;
                break;
        case 6: cout<<s6<<endl;
                break;
        default:
                break;
    }
    return 0;
}
