#include<bits/stdc++.h>
using namespace std;

int r,c;
int mx,my,cx,cy,dx,dy;

int kx[]={1,-1,0,0};
int ky[]={0,0,1,-1};
int ax[]={1,-1,-1,1};
int ay[]={1,-1,1,-1};

bool both_dia() {
    if(abs(mx-cx)==abs(my-cy)&&abs(mx-dx)==abs(my-dy)&&abs(cx-dx)==abs(cy-dy))
        return true;
    else return false;
}
bool out() {
    for(int i=0;i<4;i++) {
        int nx=mx+kx[i];
        int ny=my+ky[i];
        if(nx<=0||ny<=0||nx>r||ny>c) return true;
    } return false;
}
int main(int argc,char const *argv[]) {
    cin>>r>>c;
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++) {
        cin>>mx>>my>>cx>>cy>>dx>>dy;
        if((mx==cx&&my==cy)||(mx==dx&&my==dy)) cout<<"NO"<<endl;
        else if(out()) {
            //cerr<<"out"<<endl;
            cout<<"YES"<<endl;
        }
        else if(both_dia()) {
            //cerr<<"dia"<<endl;
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    return 0;
}
