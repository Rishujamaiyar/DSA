#include <bits/stdc++.h>
using namespace std;
#define inf 999

int graph[100][100];


int min_index(bool visited[],int dist[],int n){
    int min=inf;
    int min_val;
    for(int i=0;i<n;i++){
        if(visited[i]==false)
            if(min >= dist[i]){
                min = dist[i];
                min_val = i;
            }
    }
    return min_val;
}


void func(int src,int n){
    int dist[n] ;
    for(int i=0;i<n;i++) dist[i]=inf;
    bool visited[n] = {0};
    dist[src] = 0;
   
    
    for(int i=0;i<n-1;i++){
      
        int u = min_index(visited,dist,n); 
        visited[u] = true;
    
        for(int a=0;a<n;a++){
            if(graph[a][u]!=0 && !visited[a] && dist[u] != inf && dist[a]>dist[u]+graph[a][u])
            dist[a]=dist[u]+graph[a][u];
            }
        }
    
    cout<<"distances from source"<<endl;
    for(int i=0;i<n;i++) cout<<dist[i]<<endl;
    
}






int main(){
//taking input
	int n;
	cin>>n;
	//vector<vector<int>> graph;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}
	int src;
	cin>>src;
//dijikstra

func(src,n);


}