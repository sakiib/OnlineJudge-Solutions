#include<bits/stdc++.h>
using namespace std;
char str[100][100];
vector<int> B;
vector<int> W;
bool no_black=false;
bool no_white=false;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            cin>>str[i][j];
        }
    }
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(str[i][j]=='B'){
                for(int k=i+1;k<=8;k++){
                    if(str[k][j]!='B'&&str[k][j]!='W'){
                        no_black=true;
                    }
                    else{
                        no_black=false;
                        break;
                    }
                }
                if(no_black) B.push_back(8-i);
                no_black=false;
            }
        }
    }
  /*  for(int i=0;i<B.size();i++){
        cout<<B[i]<< " ";
    }
    cout<<endl;*/
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            if(str[i][j]=='W'){
                for(int k=i-1;k>=1;k--){
                    if(str[k][j]!='B'&&str[k][j]!='W'){
                        no_white=true;
                    }
                    else{
                        no_white=false;
                        break;
                    }
                }
                if(no_white) W.push_back(i-1);
                no_white=false;
            }
        }
    }
  /*  for(int i=0;i<W.size();i++){
        cout<<W[i]<< " ";
    }
    cout<<endl;*/
    sort(W.begin(),W.end());
    sort(B.begin(),B.end());
   // cout<<min(W[0],B[0]);
    if(B[0]<W[0]) puts("B");
    else puts("A");
    return 0;
}
