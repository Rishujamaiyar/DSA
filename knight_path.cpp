
#include <bits/stdc++.h> 
using namespace std; 

struct cell { 
	int x,y,dis;
	cell(){}
	cell(int x,int y,int dis):
			x(x),y(y),dis(dis){}
}; 

bool isInside(int x, int y, int N) 
{ 
	if (x >= 1 && x <= N && y >= 1 && y <= N) 
		return true; 
	return false; 
} 


int minStepToReachTarget(int knightPos[], int targetPos[],int n) 
{ 
	int dx[] = {1,2,-1,-2,-1,-2,1,2};
	int dy[] = {2,1,-2,-1,2,1,-2,-1};

	queue<cell> q;
	q.push(cell(knightPos[0],knightPos[1],0));

	cell t;
	int x,y;
	bool visited[n+1][n+1]={0};

	while(!q.empty()){
		t = q.front();
		q.pop();

		if(t.x == targetPos[0] && t.y == targetPos[1])
			return t.dis;

		for(int i=0;i<8;i++){

			x = t.x + dx[i];
			y = t.y + dy[i];

			if(isInside(x,y,n) && !visited[x][y]){
				visited[x][y] = true;
				q.push(cell(x,y,t.dis+1));
			}

		}

	}
	return 0;
} 

int main() 
{ 
	int N = 30; 
	int knightPos[] = { 1, 1 }; 
	int targetPos[] = { 30, 30 }; 
	cout << minStepToReachTarget(knightPos, targetPos, N); 
	return 0; 
} 
