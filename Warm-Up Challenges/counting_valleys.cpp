#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    char steps[n];
    for(int i=0;i<n;i++){
        cin>>steps[i];
    }
    int level=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(steps[i]=='U')
            level++;
        else if(steps[i]=='D')
            level--;
        if(level==0 && steps[i]=='U')
            count++;
    }
    cout<<count;
    return 0;
}
