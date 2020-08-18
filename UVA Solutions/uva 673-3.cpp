#include<bits/stdc++.h>
using namespace std;

int main(int arc,char const *argv[])
{
    int t,l;
    string str;
    cin>>t;
    getchar();
    while(t--)
    {
        stack<char>mystack;
        getline(cin,str);
        l=str.size();
        for(int i=0;i<l;i++)
        {

             if(!mystack.empty()&&str[i]==')')
            {
                if(mystack.top()=='(')
                    mystack.pop();
            }
            else if(!mystack.empty()&&str[i]==']')
            {
                if(mystack.top()=='[')
                    mystack.pop();
            }
            else
                mystack.push(str[i]);

        }
        if(mystack.empty())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
