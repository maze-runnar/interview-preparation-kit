#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> c(n),d(n);
    for(int c_i = 0;c_i < n;c_i++){
       cin >> c[c_i];
    }
    d[0]=0;
    d[1]=c[1]*10000+1;
    for(int i=2;i<n;i++)
        d[i]=min(d[i-1],d[i-2])+1+10000*c[i];
    cout<<d[n-1]<<"\n";
    return 0;
}

