#include<bits/stdc++.h>
using namespace std;

int power(int x,int y) {
    int ret=1;
    for(int i=1;i<=y;i++) {
        ret*=x;
    }
    return ret;
}
int st_in(string &str) {
    int ans=0;
    //reverse(str.begin(),str.end());
    for(int i=str.size()-1,j=0;i>=0;i--,j++) {
        ans+=(str[i]-'0')*power(10,j);
    }
    //cerr<<"ans :"<<ans<<endl;
    return ans;
}
void NO() {
    cout<<-1<<endl;
    exit(0);
}
int b_len(int b) {
    int cnt=0;
    while(b!=0) {
        b=b/10;
        cnt++;
    }
    return cnt;
}
int main(int argc,char const *argv[]) {
    string a;
    int b,n;
    cin>>a;
    cin>>b>>n;
    /*if(a.size()+n<b_len(b)) {
        NO();
    }*/
    while(n--) {
        string temp=a;
        bool done=false;
        //cerr<<"temp :"<<temp<<endl;
        for(int i=0;i<=9;i++) {
            a+=(i+'0');
            //cerr<<"A: "<<a<<endl;
            if(st_in(a)%b==0) {
                done=true;
                break;
            }
            else a=temp;
        }
        if(done) {
            while(n--) {
                a+='0';
            }
            cout<<a<<endl;
            exit(0);
        }
        if(!done) NO();
    }
    cout<<a<<endl;
    return 0;
}
