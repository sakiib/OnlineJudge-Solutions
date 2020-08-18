#include<iostream>
#include<stack>
#include<cstdio>
#include<string.h>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    int t,l;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        getline(cin,str);
        l=str.size();
        stack<char>checker;
        for(int i=0;i<l;i++)
        {
            if(!checker.empty()&&str[i]==')'&&checker.top()=='(')
            {
                 checker.pop();
            }
            else if(!checker.empty()&&str[i]==']'&&checker.top()=='[')
            {
                checker.pop();
            }
            else
                checker.push(str[i]);

        }
       /*while(!checker.empty())
        {
            printf("Pop the top: %c\n",checker.top());
            checker.pop();
        }*/
        if(checker.empty())
            printf("Yes\n");

        else
            printf("No\n");
    }
    return 0;
}
