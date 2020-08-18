#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(false);
    ll total;
    ll row,time_round,time_move,side=0;
    char ch;
    cin>>row>>ch;
    time_round=(row-1)/4*16;//4 rows are compleated in 16 sec cycle//
    time_move=(row-1)%2*7;//after each cycle they reach odd position
    // moving from that position takes 7 secs//
   // cout<<time_round<< " " <<time_move;
    if(ch=='f') side=1;
    else if(ch=='e') side=2;
    else if(ch=='d') side=3;
    else if(ch=='a') side=4;
    else if(ch=='b') side=5;
    else if(ch=='c') side=6;
    total=time_round+time_move+side;
    cout<<total;
    return 0;
}
