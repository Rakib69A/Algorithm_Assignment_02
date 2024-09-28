#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
bool vis[N][N];
int dis[N][N];
pair<int,int> parent[N][N];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char graph[N][N];
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}

void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first, b = par.second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false && graph[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
                parent[ci][cj] = {a,b};
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    int si, sj;
    int di, dj;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] == 'R'){
                si = i;
                sj = j;
            }
            else if(graph[i][j] == 'D'){
                di = i;
                dj = j;
            }
        }
    }
    // cout<<si<<" "<<sj<<endl;
    // cout<<di<<" "<<dj<<endl;
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    memset(parent, -1, sizeof(parent));
    bfs(si, sj);
    pair<int,int> x = {di,dj};
  
    while(x.first != -1 && x.second != -1){
        if(graph[x.first][x.second] != 'R' && graph[x.first][x.second] != 'D')
            graph[x.first][x.second] = 'X';
        x = parent[x.first][x.second];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<graph[i][j];
        }
        cout<<endl;
    }
    return 0;
}