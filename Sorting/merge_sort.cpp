#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long merge(vector<int>* arr, int leftBegin, int middle, int rightEnd){
    int i, j, k;

    int n1, n2;
   
    long count =0;
    
    n1 = middle-leftBegin+1;
    n2 = rightEnd - middle; 
    
    vector<int> leftArr (n1);
    vector<int> rightArr(n2);
    
    for (int i = 0; i < n1; i++) 
        leftArr[i]= (*arr)[i+leftBegin];
    for (int j = 0; j < n2; j++) 
        rightArr[j]= (*arr)[j+middle+1];
    
    i = 0;
    j = 0;
    k = leftBegin;
    
    while( i < n1 && j <n2){
        if(leftArr[i] <= rightArr[j]){
            (*arr)[k] = leftArr[i];
            i++;
           
        }else{
            (*arr)[k] = rightArr[j];
            j++;
            count = count+ (n1-i);
        }        
        k++;
    }
    
    while(i < n1){
        (*arr)[k] = leftArr[i];
        i++;
        k++;
    }
    
    while(j < n2){
        (*arr)[k] = rightArr[j];
        j++;
        k++;
    }
    return count;
}

long countInversions_rec(vector<int> *arr, int leftBegin, int rightEnd){
    long inversions = 0;
    if(leftBegin >= rightEnd){
        return 0;
    }
    int mid = floor( (leftBegin + rightEnd) /2 );
    inversions  = countInversions_rec(arr, leftBegin, mid);
    inversions += countInversions_rec(arr, mid+1, rightEnd);
    
    return inversions + merge(arr, leftBegin, mid, rightEnd);

}

long countInversions(vector<int> *arr) {
    int n = ( arr->size() );
    return countInversions_rec(arr, 0, n-1);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
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

        long result = countInversions(&arr);
        
        

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