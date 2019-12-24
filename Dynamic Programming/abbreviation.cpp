#include <bits/stdc++.h>

using namespace std;

// Complete the abbreviation function below.
string abbreviation(string a, string b) {
      int n,m;

    n=a.length();
    m=b.length();
    int d[n+1][m+1];
    for(int j=0;j<=m;j++){
        if(j==0)
            d[0][j]=1;
        else d[0][j]=0;
    }

    int count=0;

    for(int k=1;k<=n;k++){
        int i=k-1;
        if(a[i]>=65&&a[i]<=90||count==1){
            count=1;
            d[k][0]=0;
        }else d[k][0]=1; 
    }

    for(int k=1;k<=n;k++){
        int i=k-1;
        for(int l=1;l<=m;l++){
            int j=l-1;
            if(a[i]==b[j]){
                d[k][l]=d[k-1][l-1];
                continue;
            }
            else {
                if(toupper(a[i])==b[j]){
                    d[k][l]=d[k-1][l-1]|d[k-1][l];
                    continue;
                }
            }
            if(a[i]>=65&&a[i]<=90){
                d[k][l]=0;
                continue;
            }
            else{
             d[k][l]=d[k-1][l];
             continue; 
            }
        }
    }

       if(d[n][m]) return "YES";
       else return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
