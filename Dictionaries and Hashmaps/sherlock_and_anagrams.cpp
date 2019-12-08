#include<bits/stdc++.h>

using namespace std;

unordered_map<char, int> primes_map;
void init_primes();

int sherlockAndAnagrams(string s) {
    
    int n;
    long key;
    int result;
    const char* s_chars;
    unordered_map<long,int> map;
    
    result = 0;
    n = s.size();
    init_primes();
    s_chars = s.c_str();
    
    for (int len = 1; len <= n; len++) {    
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            key = 1;
            for (int k = i; k <= j; k++) {
                key = (primes_map[ s_chars[k] ]*key) %1000000007;
            }
            map[key]+=1;
        }
    }
    
    
    for(unordered_map<long,int>::iterator it = map.begin(); it !=map.end(); ++it){
        int val = it->second;
        if(val >= 2){
            result += (val*(val-1))/2;
        }
    }
    
    return result;
 
}
// ======== HElPER =========
void init_primes(){
    primes_map['a']= 2;
    primes_map['b']= 3;
    primes_map['c']= 5;
    primes_map['d']= 7;
    primes_map['e']= 11;
    primes_map['f']= 13;
    primes_map['g']= 17;
    primes_map['h']= 19;
    primes_map['i']= 23;
    primes_map['j']= 29;
    primes_map['k']= 31;
    primes_map['l']= 37;
    primes_map['m']= 41;
    primes_map['n']= 43;
    primes_map['o']= 47;
    primes_map['p']= 53;
    primes_map['q']= 59;
    primes_map['r']= 61;
    primes_map['s']= 67;
    primes_map['t']= 71;
    primes_map['u']= 73;
    primes_map['v']= 79;
    primes_map['w']= 83;
    primes_map['x']= 89;
    primes_map['y']= 97;
    primes_map['z']= 101;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}