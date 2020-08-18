#include<bits/stdc++.h>
using namespace std;

int solve_1(string &str){
    int cnt=0;
    for(int i=0;i<str.size(); ){
        if(str[i]=='D'){
            cnt++;
            while(str[i]=='D'){
                i++;
            }
        }
        else i++;
    }

    return cnt;
}
int solve_2(string &str){
    int cnt2=0;
    for(int i=0;i<str.size(); ){
        if(str[i]=='U'){
            cnt2++;
            while(str[i]=='U'){

                i++;
            }
        }
        else i++;
    }

    return cnt2;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        cout<<min(solve_1(str),solve_2(str))<<endl;
    }
    return 0;
}
