#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long arrayManipulation(int n, vector<vector<int>> queries) {
    
    long max=0;
    long val=0;
    vector<long> values(n, 0);
    long qsize = queries.size();
    vector<int> query;
    long a;
    long b;
    long k;

    for(int i=0; i<qsize; i++){
        query = queries[i];
        a = query[0];
        b = query[1];
        k = query[2];
        values[a-1]+=k;
        if(b<n) values[b]-=k;
    }
    for(int j=0; j<n; j++){
        val+=values[j];
        if(val > max) max = val;
    }
    return max;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

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
