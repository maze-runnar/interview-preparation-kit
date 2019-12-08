#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
const char NULL_CHAR = '\0';

string twoStrings(string s1, string s2) {
    int n;
    int m;
    const char* char_array1;
    const char* char_array2;
    unordered_map<char, char> map;

    n = s1.size();
    m = s2.size();
    char_array1 =  s1.c_str();
    char_array2 =  s2.c_str();
    
    for(int i = 0; i < n-1; i++)
        map[ char_array1[i] ] = char_array1[i+1];        
    
    for(int i = 0; i < m; i++)
        if(map[ char_array2[i] ] != NULL_CHAR)
            return "YES";
    
    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}