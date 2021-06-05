#include <bits/stdc++.h>
using namespace std;


int bfs(int n,int src,int dest,int dist[],int parent[],bool visited[],map <int,list<int>> adj){
	queue <int> q;

	visited[src]=true;
	dist[src]=0;
	parent[src] = -1;
	q.push(src);

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto x:adj[u]){
			if(!visited[x]){
				dist[x] = dist[u] + 1;
				visited[x] = true;
				parent[x] = u;
				q.push(x);
				
				if(x==dest)
				return dist[dest];
			    
			}
		
		}
	}
	//for(int i=0;i<n;i++) cout<<dist[i]<<" ";
	return 1;

}





int main(){
//input
	int n,e;
	cin>>n>>e;
	map <int,list<int>> adj;
	for(int i=0;i<e;i++) 
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int src, dest;
	cin>>src>>dest;
//bfs function

	int dist[n] = {0};
	int parent[n] = {0};
	bool visited[n] = {0};

    int min_dist = bfs(n,src,dest,dist,parent,visited,adj);
    cout<<"The path length is:"<<min_dist<<endl;
//for the path

    stack<int> path;
    int x = dest;
    while(parent[x]!=-1){
        path.push(x);
        x = parent[x];
    }
    path.push(src);
    cout<<"The path is"<<endl;
    while(!path.empty()){
        cout<<path.top()<<" ";
        path.pop();
    }
    
    
	return 0;
}









