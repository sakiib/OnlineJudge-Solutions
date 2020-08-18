#include<bits/stdc++.h>
using namespace std;
vector<int>window;
vector<int>non;
vector<int>ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,pass,win_seat,w,no;
    cin>>n>>pass;
    win_seat=n*2;
    for(int i=1;i<=pass;i++){
        if(i<=win_seat) window.push_back(i);
        else non.push_back(i);
    }
   /* for(int i=0;i<window.size();i++){
        cout<<window[i]<< " ";
    }
    cout<<endl;
    for(int i=0;i<non.size();i++){
        cout<<non[i]<< " ";
    }
    cout<<endl;*/
    w=window.size();
    no=non.size();
    while(w<=no){
        window.push_back(0);
        w++;
    }
    while(no<=w){
        non.push_back(0);
        no++;
    }
   /* for(int i=0;i<window.size();i++){
        cout<<window[i]<< " ";
    }
    cout<<endl;
    for(int i=0;i<non.size();i++){
        cout<<non[i]<< " ";
    }
    cout<<endl;*/
    for(int i=0;i<window.size();i++){
        ans.push_back(non[i]);
        ans.push_back(window[i]);
    }

    for(int i=0;i<ans.size();i++){
        if(ans[i]!=0) cout<<ans[i]<< " ";
    }
    return 0;
}
