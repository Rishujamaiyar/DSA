#include <bits/stdc++.h>
using namespace std;

int path;
map<int,list<int>> adj;


void dfs(int s,int d){
	if(s==d)
		path++;
	else{
		for(auto x:adj[s])
			dfs(x,d);
	}
}


int main(){
	int a;
	cin>>a;
	while(a--){
	int n,e;
	cin>>n>>e;
	adj.clear();
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	int s,d;
	cin>>s>>d;
	path=0;
	dfs(s,d);

	cout<<path<<endl;
	}
    return 0; 

}