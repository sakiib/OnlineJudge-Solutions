#include<iostream>
#include<stack>
#include<cstring>
#include<string.h>

using namespace std;

int main()
{
    int l;
    stack<char>mystack;
    char str[1000];

    while(cin >> str)
    {
      l=strlen(str);
      for(int i=0;i<l;i++)
      {
          if(str[i]=='(')
            mystack.push(str[i]);
          else if(str[i]==')')
          {
              if(mystack.top()=='('&&!mystack.empty())
                cout << "Paisi" << " " << mystack.top() <<endl;
                mystack.pop();

          }

      }
      if(!mystack.empty())
        cout << "empty" << endl;
      else
        cout << "Full" << endl;

    }
    return 0;
}
