#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    map<string, string> conversion;
    string temp, second,str,first;
    getline(cin, temp);//space shoho niya nisi//
    while (temp != "")
    {
        stringstream ss(temp);//stringstream na korle ekta string hishabe niye nibe//
        ss >> first >>second;//stringstream kore duita word temp & 2nd ta second e assign korlam//
        conversion[second] = first;//second tar jonno first ta map korlam//
        getline(cin, temp);
    }
    while (cin >> str)
    {
        map<string, string>::iterator it = conversion.find(str);//Finding a string

        if (it == conversion.end())//find iterate until end if(map.find(str)==map.end()the not found//
            cout << "eh\n";
        else
            cout << it->second << '\n';
            //cout << conversion[str1]<<endl;//Eitao hobe//
    }
   return 0;
}
