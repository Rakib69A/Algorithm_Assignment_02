#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int sz[N];
void dsu_init(int n){
    for(int i=1;i<=n;i++){
        parent[i] = -1;
        sz[i] = 1;
    }
}
int dsu_find(int node){
    if(parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void dsu_union_by_size(int node1, int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(sz[leaderA] > sz[leaderB]){
        parent[leaderB] = leaderA;
        sz[leaderA] += sz[leaderB];
    }
    else if(sz[leaderA] < sz[leaderB]){
        parent[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];
    }
    else{
        parent[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_init(n);
    int cnt=0;
    while(e--){
        int a,b;
        cin>>a>>b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if(leaderA == leaderB){
            cnt++;
        }
        else{
            dsu_union_by_size(a,b);
        }
    }
    cout<<cnt<<endl;
    return 0;
}