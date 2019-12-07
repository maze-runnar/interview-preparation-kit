#include <bits/stdc++.h>

using namespace std;

int tx[8] = {-1,-1,-1,0,1,1,1,0};
int ty[8] = {-1,0,1,1,1,0,-1,-1};

// Complete the maxRegion function below.
int dfs(vector<vector<int>> & grid, int x, int y)
{
    if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size())return 0;
    if(grid[x][y]==2 || grid[x][y]==0)return 0;

    grid[x][y] = 2;
    int ans = 0;
    for(int i=0;i<8;i++)
    {
        int x1 = x+tx[i];
        int y1 = y+ty[i];

        ans+=dfs(grid,x1,y1);
    }

    return ans+1;
}


int maxRegion(vector<vector<int>> grid) {

    int ans = 0;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[0].size();j++)
        {
            int current = 0;
            if(grid[i][j]==1)
            {
                current = dfs(grid,i,j);
            }
            
            ans = max(ans,current);
        }
    }

    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}
