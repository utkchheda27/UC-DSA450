
#include<bits/stdc++.h>
#define ll long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vec(T) vector<T>
#define p(T1,T2) pair<T1,T2>
#define f first
#define s second
#define mod 998244353
#define MOD 1000000007
using namespace std;

const int N=1e5+10;
vector<int>g[N];//list representation of graph  

bool vis[N]; //global array for isVisited for vertex
//by default global array initialized with 0
void DFS(int vertex){
    //
    if(vis[vertex])return;
    cout<<vertex<<"\n";
    vis[vertex]=true;
    for(int child : g[vertex]){
    //2
    cout<<"Parent "<<vertex<<" ,Child "<<child<<"\n";
    //3
        DFS(child);
    
    }
}

int main()
{
fastio;
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){
    int v1,v2;
    cin>>v1>>v2;
    //given undirected graph hence mark both way distances
    g[v1].push_back(v2);
    g[v2].push_back(v1);
}
DFS(1);
return 0;
    
    

}