#include <bits/stdc++.h>
#define FOR(x, n) for(int x = 0; x < n; x++)

using namespace std;

vector<string> split_string(string);

long triplets(vector<int> a, vector<int> b, vector<int> c) {
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
 
    a.erase(unique(a.begin(),a.end()),a.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    c.erase(unique(c.begin(),c.end()),c.end());
    
    int i = 0, j = 0, k = 0;
    long sol = 0;
    
    while(i < b.size()){
        while(a[j]<=b[i] && j<a.size())
            j++;
        while(c[k]<=b[i] && k<c.size())
            k++;
        sol+= (long)j*k;
        i++;
    }
    return sol;
}

int main()
{
    int len_a, len_b, len_c;
    long temp;
    
    
    cin >> len_a;
    cin >> len_b;
    cin >> len_c;
    
    vector<int> arr_a(len_a);
    vector<int> arr_b(len_b);
    vector<int> arr_c(len_c);
    
   
    
    FOR(i, len_a)
        cin >> arr_a[i];
    
    FOR(i, len_b)
        cin >> arr_b[i];
    
    FOR(i, len_c)
        cin >> arr_c[i];
    
    
    
    long sol = triplets(arr_a, arr_b, arr_c);
    
    cout << sol << endl;
    
        
    return 0;
}