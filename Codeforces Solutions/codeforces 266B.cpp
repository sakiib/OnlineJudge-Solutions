#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    string str;
    cin>>str;
    while(q--){
        for(int i=0;i<str.size()-1;){
            if(str[i]=='B'&&str[i+1]=='G'){
                swap(str[i],str[i+1]);
                i+=2;
            }
            else i++;
        }
        //cout<<str<<endl;
    }
    cout<<str<<endl;
    return 0;
}
