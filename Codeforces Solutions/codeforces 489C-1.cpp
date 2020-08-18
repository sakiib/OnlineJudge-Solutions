#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int len,sum;
    cin>>len>>sum;
    string mx="";
    int temp=sum;
    int f=sum;
    if(len>1&&sum==0) {
        cout<<"-1"<< " " <<"-1"<<endl;
        return 0;
    }
    while(true) {//for max num calculation
        for(char i='9';i>='0';i--) {
            if(sum>=(i-'0')) {
                sum-=(i-'0');
                mx+=i;
                break;
            }
        }
        if(mx.size()==len||sum==0) break;
    }
    while(mx.size()<len) mx+='0';
    //cout<<mx<<endl;
    int res=0;
    for(int i=0;i<mx.size();i++) {
        res+=(mx[i]-'0');
    }
    if(res!=temp) {
        mx="-1";
        cout<<mx<< " "<<mx<<endl;
        return 0;
    }
    //cout<<mx<<endl;
    string mn="";
    while(true) {
        for(char i='0';i<='9';i++) {
            if(mn.size()==0&&i=='0') continue;
            if(temp>=(i-'0')) {
                temp-=(i-'0');
                mn+=i;
                break;
            }
        }
        if(mn.size()==len||temp==0) break;
    }
    int re=0;
    for(int i=0;i<mn.size();i++) {
        res+=(mn[i]-'0');
    }
    if(re==f) {
        cout<<mn<< " " <<mx<<endl;
        return 0;
    }
    if(re!=f) {
        for(int i=mn.size()-1;i>=0;i--) {
            re-=(mn[i]-'0');
            int need=f-res;
            if(need<=9) {
                mn[i]=(need+'0');
                re+=need;
                break;
            }
            else {
                mn[i]='9';
                re+='9';
            }
        }
    }
    cout<<mn<< " " <<mx<<endl;
    return 0;
}
