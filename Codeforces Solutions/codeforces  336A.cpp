#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int x,y;
    cin>>x>>y;
    if(x>0&&y>0) {
        cout<<0<<" "<<x+y<<" "<<x+y<<" "<<0<<endl;
    }
    else if(x<0&&y>0) {
        cout<<-(abs(x)+y)<<" "<<0<<" "<<0<<" "<<abs(x)+y<<endl;
    }
    else if(x>0&&y<0){
        cout<<0<<" "<<-(x+abs(y))<<" "<<x+abs(y)<<" "<<0<<endl;
    }
    else {
        cout<<-(abs(x)+abs(y))<<" "<<0<<" "<<0<<" "<<-(abs(x)+abs(y))<<endl;
    }
    return 0;
}
