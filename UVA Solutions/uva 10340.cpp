#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    string a,b;
    while(cin>>a>>b) {
        int j=0;
        for(int i=0;i<b.size();i++) {
            if(a[j]==b[i]) {
                j++;
            }
        }
        if(j==a.size())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
