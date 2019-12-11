#include <bits/stdc++.h>

using namespace std;

const char A = 'A';
const char B = 'B';

int alternatingCharacters(string s) {
    int count;
    int s_len;
    const char* s_chars;
    
    count =0;
    s_len= s.length();
    s_chars= s.c_str();
    
    for(int i = 0; i < s_len-1; i++){
        if(s_chars[i] == A && s_chars[i+1] != B)
            count++;
        else if(s_chars[i] == B && s_chars[i+1] != A)
            count++;
    }
    
    return count;
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
        if(s.length()>0){
            int result = alternatingCharacters(s);
            fout << result << "\n";
        }
    }

    fout.close();

    return 0;
}