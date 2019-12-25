#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class MyQueue {
  
    public:
        stack<int> st1, st2;   
        void push(int x) {
                   
            st1.push(x);
        }

        void pop() {
            if(st2.empty())
             {
                  while(!st1.empty()) 
                    {
                    st2.push(st1.top());
                    st1.pop();
                    }
            }
            
            st2.pop();
            
        }

        int front() {
         if(st2.empty())
             {
              while(!st1.empty()) 
              {
                  st2.push(st1.top());
                  st1.pop();}
            }
            return st2.top();
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
   
    return 0;
}
