#include <bits/stdc++.h>
using namespace std;


void func_util(stack <int> &s,map<int,list<int>> adj,int i,bool visited[]){
	visited[i] = true;

for(auto x:adj[i])
	if(!visited[x])
	 func_util(s,adj,x,visited);

s.push(i);
}



void func(map <int,list<int>> adj ,int n){
	bool visited[n]={0};
	stack <int> s;
	for(int i=0;i<n;i++)
		if(!visited[i])
			func_util(s,adj,i,visited);

	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}



int main(){

	int n,e;
	cin>>n>>e;
	map <int,list<int>> adj;
	for(int i=0;i<e;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	func(adj,n);
}
