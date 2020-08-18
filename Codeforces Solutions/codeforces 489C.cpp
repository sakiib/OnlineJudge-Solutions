#include<bits/stdc++.h>
using namespace std;
int s,sum;
bool possible(int pos,int val) {

}
int main(int argc,char const *argv[]) {
    cin>>s>>sum;
    string ans="";
    for(int i=1;i<=s;i++) {
        ans+='0';
    }
    for(int i=0;i<s;i++) {
        for(int j=0;j<9;j++) {
            if(possible(i,j)) {

            }
        }
    }
    return 0;
}
