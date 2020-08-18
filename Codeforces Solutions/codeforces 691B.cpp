#include<bits/stdc++.h>
using namespace std;
bool flag=true;
bool check(char a,char b)
{
    if(a=='o'&&b=='o') return true;
    if(a=='O'&&b=='O') return true;
    if(a=='x'&&b=='x') return true;
    if(a=='X'&&b=='X') return true;
    if(a=='q'&&b=='p') return true;
    if(a=='p'&&b=='q') return true;
    if(a=='b'&&b=='d') return true;
    if(a=='d'&&b=='b') return true;
    if(a=='v'&&b=='v') return true;
    if(a=='V'&&b=='V') return true;
    if(a=='w'&&b=='w') return true;
    if(a=='W'&&b=='W') return true;
    if(a=='A'&&b=='A') return true;
    if(a=='T'&&b=='T') return true;
    if(a=='I'&&b=='I') return true;
    if(a=='M'&&b=='M') return true;
    if(a=='U'&&b=='U') return true;
    if(a=='H'&&b=='H') return true;
    if(a=='Y'&&b=='Y') return true;
    else return false;
}
int main()
{
    string str;
    cin>>str;
    int l;
    l=str.size();
    for(int i=0;i<l/2+1;i++){
        if(check(str[i],str[l-1-i])) continue;
        else{
            flag=false; break;
        }
    }
    if(flag==false) cout<<"NIE"<<endl;
    else cout<<"TAK"<<endl;
    return 0;
}
