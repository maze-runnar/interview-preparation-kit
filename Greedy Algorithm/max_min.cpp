#include <bits/stdc++.h>

using namespace std;

static bool sortFn(int a, int b){return a < b;}
static int diff = INT_MAX;

int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end(), sortFn);
    
    for(int i = 0; i <= arr.size()-k; i++)
        diff = min(arr[i+k-1]-arr[i], diff);
    
    return diff;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}