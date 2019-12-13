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
    int arr[101]={0};
    for(int i=0;i<n;i++){		//input from the user
        int x;
        cin>>x;
        arr[x]++;
        
    }
    int count=0;		
    for(int i=0;i<101;i++){
        count=count+arr[i]/2;
    }
    cout<<count<<endl;		//output
    return 0;
}
