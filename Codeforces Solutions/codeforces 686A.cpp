#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(int argc,char const *argv[]) {
    LL people,ice,num,dist=0;
    char ch;
    cin>>people>>ice;
    while(people--){
        cin>>ch>>num;
        if(ch=='+'){
            ice+=num;
        }
        else if(ch=='-'){
            if(ice<num){
                dist++;
            }
            else if(ice>=num){
                ice-=num;
            }
        }
    }
    cout<<ice<< " " <<dist<<endl;
    return 0;
}
