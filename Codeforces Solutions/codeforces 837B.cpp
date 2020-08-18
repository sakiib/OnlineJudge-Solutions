#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin>>n>>m;
    char str[105][105];
    for(int i=0;i<n;i++) {
        cin>>str[i];
    }
    bool pashe=true;
    int k=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char temp=str[k][0];
            if(str[i][j]!=temp) {
                pashe=false;
                //cout<<"up";
                break;
            }
        }
        k++;
        if(!pashe) break;
    }
    bool niche=true;
    int l=0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            char temp=str[0][l];
            if(str[j][i]!=temp) {
                niche=false;
                //cerr<<"down";
                break;
            }
        }
        l++;
        if(!niche) break;
    }
    /*if(pashe||niche) {
        cout<<"May be"<<endl;
        return 0;
    }*/
    bool red=false; bool blue=false; bool green=false;
    bool r_done=false; bool g_done=false; bool b_done=false;
    int b=0,r=0,g=0;
    if(pashe) {
        for(int i=0;i<n;i++) {
            if(str[i][0]=='R'&&!r_done) {
                red=true; r++;
                if(green) g_done=true;
                if(blue) b_done=true;
            }
            else if(str[i][0]=='G'&&!g_done) {
                green=true; g++;
                if(red) r_done=true;
                if(blue) b_done=true;
            }
            else if(str[i][0]=='B'&&!b_done) {
                blue=true; b++;
                if(red) r_done=true;
                if(green) g_done=true;
            }
        }
        //cerr<<b<< " "<<g<< " "<<r<<endl;
        int tot=n/3;
        if(b==tot&&g==tot&&r==tot&&(b+g+r==n)) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    red=false, green=false, blue=false;
    r_done=false, g_done=false, b_done=false;
    b=0,g=0,r=0;
    if(niche) {
        for(int i=0;i<m;i++) {
            if(str[0][i]=='R'&&!r_done) {
                red=true; r++;
                if(green) g_done=true;
                if(blue) b_done=true;
            }
            else if(str[0][i]=='G'&&!g_done) {
                green=true; g++;
                if(red) r_done=true;
                if(blue) b_done=true;
            }
            else if(str[0][i]=='B'&&!b_done) {
                blue=true; b++;
                if(red) r_done=true;
                if(green) g_done=true;
            }
        }
        int tot=m/3;
        if(b==tot&&g==tot&&r==tot&&(b+g+r==m)) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
