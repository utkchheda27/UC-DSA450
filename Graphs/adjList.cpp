
#include <bits/stdc++.h>
#define ll long long int
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define vec(T) vector<T>
#define p(T1,T2) pair<T1,T2>
#define f first
#define s second
#define mod 998244353
#define MOD 1000000007
using namespace std;

const int N=1e3+10;

vector<pair<int,int> > graph_list[N];//array of vectors
//to store weighted undirected graph we will store pairs for corresponding 
//vertex in array

int main()
{
fastio;
//list used when N>10^5,matrix doesnt work there
// in adjacency list ,no.of list = no.of vertices
//in each list we will store a node and its corresponding connections
//space complexity:O(V+E)

int n,m;//n is vertices, m is edges
cin>>n>>m;
for(int i=0;i<m;i++){
    int v1,v2,wt;
    cin>>v1>>v2>>wt;
    graph_list[v1].push_back({v2,wt});
    graph_list[v2].push_back({v1,wt});
    //pair.first gives connected node,pair.second gives weight

}

//to check if two edges connected or not
// for(int child:graph_list[i]){
//     if(child==j){
//         child.first is ur connected node
//         child.second is ur weight
//     }
// }
return 0;

//DRAWBACK:to access if vertex connected and corresponding weight
//          we need to use loop hence O(N)
}