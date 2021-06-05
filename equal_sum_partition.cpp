#include <bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++) cin>>arr[i];
		int sum=0;
	for(int i=0;i<n;i++) sum+=arr[i];
if(sum%2) 	cout<<"NO"<<endl;
else
	 {
	 	int k = sum/2;
bool t[n+1][k+1];
	for(int i=0;i<k+1;i++) t[0][i] = false;
	for(int i=0;i<n+1;i++) t[i][0] = true;

	for(int i=1;i<n+1;i++){
		for(int j=1;j<k+1;j++){
			if(arr[i-1]<=j)
				t[i][j] = t[i-1][j] || t[i-1][j-arr[i]];
			else
				t[i][j] = t[i-1][j];			
		}
	}

   if(t[n][k])
   	cout<<"YES"<<endl;
   else
   	cout<<"NO"<<endl;
	 }
}	
}