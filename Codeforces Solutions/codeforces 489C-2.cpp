#include<bits/stdc++.h>
using namespace std;

bool possible(int s,int val) {
    if(s*9>=val) return true;
    else return false;
}
int main(int argc,char const *argv[]) {
    int len,sum;
    cin>>len>>sum;
    if(len*9<sum||(sum==0&&len>1)) {
        cout<<"-1 -1"<<endl; return 0;
    }
    if(len==1&&sum==0) {
        cout<<"0 0"<<endl; return 0;
    }
    int val=sum;
    string mx="";
    for(int i=0;i<len;i++) {
        for(int j=9;j>=0;j--) {
           if(j<=val) {
            mx+=(j+'0');
            val-=j;
            break;
           }
        }
    }
    //cout<<mx<<endl;
    int num=sum;
    bool done=false;
    string mn="";
    for(int i=0;i<len;i++) {
        if(!done) {
            for(int j=1;j<=9;j++) {
                if(possible(len-i-1,num-j)&&j<=num) {
                    mn+=(j+'0');
                    num-=j;
                    done=true;
                    break;
                }
            }
            if(done) break;
        }
    }
    //cout<<mn<<endl;
    for(int i=1;i<=len-1;i++) {
        for(int j=0;j<=9;j++) {
            if(possible(len-i-1,num-j)&&j<=num) {
                mn+=(j+'0');
                num-=j;
                break;
            }
        }
    }
    cout<<mn<<" "<<mx<<endl;
    return 0;
}
