#include <bits/stdc++.h>
using namespace std;
//auto makes i not the pointer but the value of the DS

void bfs(map<int ,list<int >> adj,int x,bool visited[]){
	queue <int> q;
	q.push(x);
	while(!q.empty()){
		int a = q.front();
		cout<<a<<" ";
		for(auto i : adj[a]){
			if(!visited[i]){
				q.push(i);
				visited[i]=true;
			}
			
		}
		q.pop();
	}
}

int main(){
map <int ,list<int>> adj;
int u,v;
int t,n;
cin>>t>>n;
  for(int i=0;i<t;i++){
  	cin>>u>>v;
  	adj[u].push_back(v);
  }
bool visited[n]={false};
 bfs(adj,0,visited);

    return 0; 

}