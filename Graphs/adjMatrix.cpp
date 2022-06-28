#include<bits/stdc++.h>
using namespace std;

const int N=1e3+10;//if limit given then better declare globally
int graph_matrix[N][N];//globally declared hebce initialized with 0


int main(){
    int n,m; //n is no.of vertices,m is no.of edges
    cin>>n>>m;
    //1 based indexing hence n+1 and m+1
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        //for a weighted undirected graph instead of one store weight
        graph_matrix[v1][v2]=1;
        graph_matrix[v2][v1]=1;//did this coz if nothing mentioned then undirected graph
    }

//to check if vertices are connected or not
    // if(graph_matrix[i][j]==1){
    //     //connected
    // }

    //DRAWBACK: adjacencymatrix takes O(N^2)space..quite expensive
    //          if N=10^6 ,using matrix cant do..maximum continuous allocation limit it 10^7           

    //ADVANTAGE: are i,j connected?
    //           or i,j ka weight?
    //           matrix gives these answers in O(1)
    return 0;
}