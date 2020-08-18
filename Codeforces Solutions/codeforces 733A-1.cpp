#include<bits/stdc++.h>

using namespace std;

vector<int>mv;
bool flag=true;

int main()
{
    int maxs=0,j=-1;
    string str;

    cin>>str;
    str+='A';
    //cout<<str<<endl;
    if((str.size()==1)&&(str=="A"||str=="E"||str=="I"
    ||str=="O"||str=="U"||str=="Y")){

        cout<<1<<endl;return 0;
    }

    else if(str.size()==1){

        cout<<2<<endl;return 0;
    }

    // mv.push_back(0);

    for(int i=0;i<str.size();i++){

        if(str[i]=='A'||str[i]=='E'||str[i]=='I'
        ||str[i]=='O'||str[i]=='U'||str[i]=='Y'){

            //flag=false;mv.push_back(i);
            maxs=max(maxs,i-j);
            j=i;
        }

    }
  /*
     mv.push_back(0);

    if(flag==true){
        cout<<str.size()+1<<endl;
        return 0;
    }

    for(int i=0;i<mv.size()-1;i++){

        maxs=max(maxs,abs(mv[i+1]-mv[i]));
    }
*/
    cout<<maxs<<endl;

    return 0;

}
