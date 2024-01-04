#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Mod 1000000007
#define pb push_back
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(a,b) for(int i=a;i<b;++i)
#define loop(x,n) for(int x=0;x<n;++x)
#define inf (1LL<<60)
#define all(x) (x).begin(),(x).end()
#define vvi vector<vector<int>>
#define vll vector<ll>
int speedUp = []
{std::ios::sync_with_stdio(0); std::cin.tie(0); return 0; }();

void findPathHelper(int r, int c, vector < vector < int >> & maze, int n, vector < string > & paths, string move,
    vector < vector < int >> & vis) {
    if (r == n - 1 && c == n - 1) {
      paths.push_back(move);
      return;
    }

    // downward
    if (r + 1 < n && !vis[r + 1][c] && maze[r + 1][c] == 1) {
      vis[r][c] = 1;
      findPathHelper(r + 1, c, maze, n, paths, move + 'D', vis);
      vis[r][c] = 0;
    }

    // left
    if (c - 1 >= 0 && !vis[r][c - 1] && maze[r][c - 1] == 1) {
      vis[r][c] = 1;
      findPathHelper(r, c - 1, maze, n, paths, move + 'L', vis);
      vis[r][c] = 0;
    }

    // right
    if (c + 1 < n && !vis[r][c + 1] && maze[r][c + 1] == 1) {
      vis[r][c] = 1;
      findPathHelper(r, c + 1, maze, n, paths, move + 'R', vis);
      vis[r][c] = 0;
    }

    // upward
    if (r - 1 >= 0 && !vis[r - 1][c] && maze[r - 1][c] == 1) {
      vis[r][c] = 1;
      findPathHelper(r - 1, c, maze, n, paths, move + 'U', vis);
      vis[r][c] = 0;
    }
}

vector<string> findPath(int n,vector<vector<int>>&maze){
    vector<string>paths;
    vector<vector<int>>vis(n,vector<int>(n));

    if(maze[0][0] == 1) findPathHelper(0, 0, maze, n, paths, "", vis);
    return paths;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>>maze(n,vector<int>(n));

    fr(0,n){
        for(int j=0;j<n;++j){
            cin>>maze[i][j];
            // 1 means path, 0 means obstacle
        }
    }

    vector<string>paths = findPath(n,maze);

    if(paths.size() == 0){
        cout<<"THERE IS NO POSSIBLE PATH FOR THE RAT"<<endl;
    }
    else{
        cout<<"THERE ARE "<<paths.size()<<" DIFFERENT PATHS :"<<endl;
        for(int i=0;i<paths.size();++i) cout<<paths[i]<<endl;
    }
    return;
}

int main(){
    int t=1;
    //cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}
