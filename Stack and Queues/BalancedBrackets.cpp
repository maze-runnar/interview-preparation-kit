#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tc;
    string s;
    string::iterator it;
    
    map<char, char> p;
    p['{'] = '}';
    p['['] = ']';
    p['('] = ')';
    cin>>tc;
    
    while(tc) {
        cin>>s;
        //cout<<"string"<<s<<endl;
        int i = 0;
        stack<char> st;
        for (it=s.begin(); it!=s.end(); it++) {
            //cout<<s[i];
            if(s[i] == '{' || s[i] == '[' || s[i] == '(') {
                //cout<<"push"<<endl;
                st.push(s[i]);
                i++;
            }
            else if(!st.empty()){
                char c = st.top();
                //cout<<"pop"<<c<<endl;
                if(p[c] == s[i]) {
                    st.pop();
                    i++;
                }
                else {
                    break;
                }
            } else {
                break;
            }
        }
        if(st.empty() && it == s.end()) {
                cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        //cout<<endl;
        tc--;
    }
    return 0;
}
