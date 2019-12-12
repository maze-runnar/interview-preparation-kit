#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long maximumSum(vector<long> a, long m) {
    
    int n = a.size();
    long prefix =0;
    
    long maximum = 0;
    
    set<long> prefixes;

    for(int i = 0; i < n; i++){
        prefix  = (prefix + a[i])%m;
        maximum = max(maximum, prefix);
        
        auto it = prefixes.lower_bound(prefix+1);
        if(it!=prefixes.end()){
            maximum = max(maximum,prefix -(*it)+m);
        }
        prefixes.insert(prefix);
    }
    
    return ( maximum );
}

int main()
{
    int i, q;
    long n, m;

    cin >> q;
    
    while(q>0){
        cin >> n;
        cin >> m;
        
        vector<long> a(n);
        
        for( i = 0; i< n; i++)
            cin >> a[i];
        
        cout << maximumSum(a, m) <<endl;
        
        q--;
    }
    
}