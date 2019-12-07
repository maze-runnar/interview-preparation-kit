#include <bits/stdc++.h>
#include <algorithm>    

using namespace std;

vector<string> split_string(string);

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int minimumAbsoluteDifference(vector<int> arr) {
 
    int min, abs_diff;
    min = -1;
    
    sort(arr.begin(), arr.end(), myobject);
    
    for(int i = 0; i < arr.size()-1; i++){
        abs_diff = abs(arr[i] - arr[i+1]);
        if(min == -1){
            min = abs_diff;
        }else if(abs_diff < min){
            min = abs_diff;
        } 
    }
        
    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = minimumAbsoluteDifference(arr);

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