#include <bits/stdc++.h>

using namespace std;

int makeAnagram(string a, string b) {
    int sol; 
    int a_len; 
    int b_len; 
    const char* a_chars;
    const char* b_chars;
    map<char, int> wordCount1;
    
    sol=0;
    a_len = a.length();
    b_len = b.length(); 
    a_chars = a.c_str();
    b_chars = b.c_str(); 
    
    for (int i=0; i < a_len; i++)
        wordCount1[a_chars[i]]+=1;
    
    for (int i=0; i < b_len; i++)
        wordCount1[b_chars[i]]-=1;
    
    for (auto it : wordCount1)
        sol += abs(wordCount1[it.first]);
    
    return sol;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}