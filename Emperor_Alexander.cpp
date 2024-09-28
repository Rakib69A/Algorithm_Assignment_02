#include<bits/stdc++.h>
#define ll long long int
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
class Edge{
    public:
    int u,v,w;
    Edge(ll u, ll v, ll w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
bool cmp(Edge a, Edge b){
    return a.w < b.w;
}
int main()
{
    int n,e; cin>>n>>e;
    dsu_init(n);
    vector<Edge> edgeList;
    while(e--){
        ll u,v,w;
        cin>>u>>v>>w;
        edgeList.push_back(Edge(u,v,w));
    }
    sort(edgeList.begin(),edgeList.end(),cmp);
    ll totalCost = 0, bad = 0;
    for(Edge ed : edgeList){
        ll leaderU = dsu_find(ed.u);
        ll leaderV = dsu_find(ed.v);
        if(leaderU == leaderV){
            bad++;
        } 
        else{
            dsu_union_by_size(ed.u,ed.v);
            totalCost += ed.w;
        }
    }
    for(int i=2;i<=n;i++){
        int leaderA = dsu_find(1);
        int leaderB = dsu_find(i);
        if(leaderA != leaderB){
            totalCost = -1;
        }
    }
    if(totalCost == -1)
        cout<<"Not Possible"<<endl;
    else
        cout<<bad<<" "<<totalCost<<endl;
    return 0;
}