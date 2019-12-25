#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;
#include<map>


int main() {
    map<char,char>lol;
    lol[')']='(';
    lol[']']='[';
    lol['}']='{';
    int t;
    cin >> t;
    while(t--)
        {
        string s;
        stack<char>st;
        cin >> s;
        int flag=0;
        for(int i=0;s[i]!='\0';i++)
            {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else{
                if(!st.empty() and lol[s[i]]==st.top())
                 st.pop();
                else
                {
                    flag=1;
                    break;
                }
            }
        }
        
        if(!flag and st.empty())
        cout << "YES" << endl;
        else
        cout << "NO " << endl;
    }
    return 0;
}
