#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, len;
vector<string> mp(10), dict, ans(10);
string s;
bool isfind;

void init(){
    len = 0;
    s += ";";
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] == ';')
            ++ len;
    }
    dict.resize(len);
    string t = "";
    int idx = 0;
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] == ';'){
            dict[idx ++] = t;
            t = "";
        }else
            t += s[i];
    }
    isfind = false;
}

void dfs(int dep, vector<string> &tmp){
    if(dep >= len){
        ans = tmp;
        isfind = true;
        return ;
    }
    vector<string> newtmp;
    for(int i = 0; i < 10; ++ i){
        for(int j = 0; j < 10; ++ j){
            if(tmp[i][j] == '-' || tmp[i][j] == dict[dep][0]){
                bool canfind = true;
                int idx = 0;
                newtmp = tmp;
                for(idx = 0; idx < dict[dep].size(); ++ idx){
                    if(i + idx < 10 && (newtmp[i + idx][j] == '-' || newtmp[i + idx][j] == dict[dep][idx])){
                        newtmp[i + idx][j] = dict[dep][idx];
                    }else{
                        canfind = false;
                        break;
                    }
                } 
                if(canfind){
                    dfs(dep + 1, newtmp);
                }
                if(isfind)
                    return ;
                
                canfind = true;
                newtmp = tmp;
                for(idx = 0; idx < dict[dep].size(); ++ idx){
                    if(j + idx < 10 && (newtmp[i][j + idx] == '-' || newtmp[i][j + idx] == dict[dep][idx])){
                        newtmp[i][j + idx] = dict[dep][idx];
                    }else{
                        canfind = false;
                        break;
                    }
                }
                if(canfind){
                    dfs(dep + 1, newtmp);
                }
                if(isfind)
                    return ;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    for(int i = 0; i < 10; ++ i)
        cin>>mp[i];
    cin>>s;
    init();
    dfs(0, mp);
    for(int i = 0; i < 10; ++ i)
        cout<<ans[i]<<endl;
    return 0;
}
