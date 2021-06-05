#include <bits/stdc++.h>
using namespace std;

class Graph{
	int V;
    unordered_map <int ,list<int>> adj;

	void dfs_util(int x,bool visited[]){
		visited[x]=true;
		cout<<x<<" ";

        for(auto i:adj[x]){
			if(visited[i]==false)
				dfs_util(i,visited);
		}

	};
public:
    
	Graph(int V){
			this->V = V;
	};
	void add_edge(int u,int v){
		adj[u].push_back(v);
	};
	void dfs(int start){
		bool visited[V]={false};
		dfs_util(start,visited);
	};
};



int main(){
	  Graph g(4); 
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 1) \n"; 
    g.dfs(1); 
  
    return 0; 

}