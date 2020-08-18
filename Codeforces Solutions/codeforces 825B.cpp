#include<bits/stdc++.h>
using namespace std;

char ara[20][20];

bool right(int a,int b) {
    int x=0,y=0;
    if(b+4<=10) {
        for(int i=0;i<=4;i++) {
            if(ara[a][b+i]=='X') x++;
            if(ara[a][b+i]=='.') y++;
            if(ara[a][b+i]=='O') return false;
        }
        if(x==4&&y==1) return true;
        return false;
    }
    return false;
}
bool left(int a,int b) {
    int x=0,y=0;
    if(b-4>=1) {
        for(int i=0;i<=4;i++) {
            if(ara[a][b-i]=='X') x++;
            if(ara[a][b-i]=='.') y++;
            if(ara[a][b-i]=='O') return false;
        }
        if(x==4&&y==1) return true;
        return false;
    }
    return false;
}
bool up(int a,int b) {
    int x=0,y=0;
    if(b-4>=1) {
        for(int i=0;i<=4;i++) {
            if(ara[a][b-i]=='X') x++;
            if(ara[a][b-i]=='.') y++;
            if(ara[a][b-i]=='O') return false;
        }
        if(x==4&&y==1) return true;
        return false;
    }
    return false;
}
bool down(int a,int b) {
    int x=0,y=0;
    if(a+4<=10) {
        for(int i=0;i<=4;i++) {
            if(ara[a+i][b]=='X') x++;
            if(ara[a+i][b]=='.') y++;
            if(ara[a+i][b]=='O') return false;
        }
        if(x==4&&y==1) return true;
        return false;
    }
    return false;
}
bool right_diaup(int a,int b) {
    int x=0,y=0;
    if(a-4>=1&&b+4<=10) {
        for(int i=0;i<=4;i++) {
            if(ara[a-i][b+i]=='X') x++;
            if(ara[a-i][b+i]=='.') y++;
            if(ara[a-i][b+i]=='O') return false;
        }
        if(x==4&&y==1) return true;
        return false;
    }
    return false;
}
bool left_diaup(int a,int b) {
    int x=0,y=0;
    if(a-4>=1&&b-4>=1) {
        for(int i=0;i<=4;i++) {
            if(ara[a-i][b-i]=='X') x++;
            if(ara[a-i][b-i]=='.') y++;
            if(ara[a-i][b-i]=='O') return false;
        }
        if(x==4&&y==1) return true;
        return false;
    }
    return false;
}
bool right_diadown(int a,int b) {
    int x=0,y=0;
    if(a+4<=10&&b+4<=10) {
        for(int i=0;i<=5;i++) {
            if(ara[a+i][b+i]=='X') x++;
            if(ara[a+i][b+i]=='.') y++;
            if(ara[a+i][b+i]=='O') return false;
        }
        if(x==4&&y==1) return true;
        return false;
    }
    return false;
}
bool left_diadown(int a,int b) {
    int x=0,y=0;
    if(a+4<=10&&b-4>=1) {
        for(int i=0;i<=4;i++) {
            if(ara[a+i][b-i]=='X') x++;
            if(ara[a+i][b-i]=='.') y++;
            if(ara[a+i][b-i]=='O') return false;
        }
        if(x==4&&y==1) return true;
        return false;
    }
    return false;
}
void solve(int a,int b) {
    if(right(a,b)) {
            cerr<<"right";
        cout<<"YES"<<endl; exit(0);
    }
    if(left(a,b)) {
        cerr<<a<< " "<<b<<endl;
        cerr<<"left"<<endl;;
        cout<<"YES"<<endl; exit(0);
    }
    if(up(a,b)) {
        cerr<<"up";
        cout<<"YES"<<endl; exit(0);
    }
    if(down(a,b)) {
        cerr<<"down";
        cout<<"YES"<<endl; exit(0);
    }
    if(right_diaup(a,b)) {
        cerr<<"right dia up";
        cout<<"YES"<<endl; exit(0);
    }
    if(left_diaup(a,b)) {
        cerr<<"left dia up";
        cout<<"YES"<<endl; exit(0);
    }
    if(right_diadown(a,b)) {
        cerr<<"right dia down";
        cout<<"YES"<<endl; exit(0);
    }
    if(left_diadown(a,b)) {
        cerr<<"left dia down";
        cout<<"YES"<<endl; exit(0);
    }
    return ;
}
int main(int argc,char const *argv[]) {

    for(int i=1;i<=10;i++) {
        for(int j=1;j<=10;j++) {
            cin>>ara[i][j];
        }
    }
    for(int i=1;i<=10;i++) {
        for(int j=1;j<=10;j++) {
            if(ara[i][j]!='O') solve(i,j);
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
