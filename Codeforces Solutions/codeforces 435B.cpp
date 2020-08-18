#include<iostream>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin>>str;
    int t;
    cin>>t;
    if(t==0||str.size()==1) {
        cout<<str<<endl; return 0;
    }
    int ind=-1;
    for(int i=0;i<=str.length()-1;i++){
        ind=-1;
        char cur=str[i];
        if(t<=0) break;
        for(int j=i+1;j<str.length();j++) {
           if(str[j]>cur&&(j-i)<=t) {
             cur=str[j];
             ind=j;
           }
        }
        if(ind!=-1) {
            for(int k=ind;k>i;k--) {
                swap(str[k],str[k-1]);
            }
            t-=(ind-i);
        }
    }
    cout<<str<<endl;
    return 0;
}
