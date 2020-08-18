#include<bits/stdc++.h>
using namespace std;

int r,c;
string str[20];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int nx,int ny) {
    return (nx>=0&&ny>=0&&nx<r&&ny<c&&str[nx][ny]=='P');
}
bool possible(int x,int y) {
    for(int i=0;i<4;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(valid(nx,ny)) {
            str[nx][ny]='X';
            return true;
        }
    }
}
int main(int argc,char const *argv[]) {
    cin>>r>>c;
    for(int i=0;i<r;i++) {
        cin>>str[i];
    }
    int ans=0;
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(str[i][j]=='W') {
                if(possible(i,j)) {
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
