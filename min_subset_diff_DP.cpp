#include <bits/stdc++.h>
using namespace std;


int main(){
int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	int arr[n],sum=0;

	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++) sum+=arr[i];

	bool t[n+1][sum+1];
	for(int i=0;i<sum+1;i++) t[0][i] = false;
	for(int i=0;i<n+1;i++) t[i][0] = true;

	for(int i=1;i<n;i++){
		for(int j=1;j<sum;j++){
			if(arr[i-1]<=j)
				t[i][j] = t[i-1][j] || t[i-1][j-arr[i]];
			else
				t[i][j] = t[i-1][j];			
		}
	}

	vector<int> v;
	for(int i=0;i<(sum+1)/2;i++)
		if(t[n][i]!=0)
			v.push_back(i);
		int mn = INT_MAX;
	for(auto x:v){
		mn = min(mn,sum - 2*x);
	}

	cout<<mn<<endl;


}	
}