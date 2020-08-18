#include<bits/stdc++.h>
using namespace std;

int solve(int x,int cur) {
    //cout<<"x : "<<x<<endl;
    if(x<10) return 1+solve(x+1,cur+2);
    else return cur;
}
int main(int argc,char const *argv[]) {
     cout<<"ans : "<<solve(1,0)<<endl;
     return 0;
}
