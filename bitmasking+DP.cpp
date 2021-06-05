#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007

bool DEBUG = false;


int all_done;
ll dp[1025][101];
map <int,list<int>> mp;

ll func(int mask,int tid){
	if(mask==all_done)
		return 1;
	if(tid==101)
		return 0;
	if(dp[mask][tid]!=-1)
		return dp[mask][tid];
	

	ll ans=0;
	ans=func(mask,tid+1);

	for(auto x:mp[tid]){
		if((mask & 1<<x)==0)
			ans+=func(mask|1<<x,tid+1);
	}
	ans %=mod;
	dp[mask][tid] = ans;
return ans;
}



int main(){
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	all_done=(1<<n) -1;
	if(DEBUG) cout<<all_done<<endl;
	mp.clear();
	memset(dp,-1,sizeof(dp));
	cin.get();
	for(int i=0;i<n;i++){
		string s;
		getline(cin,s);
		stringstream sso(s);
		string str;
		
		while(sso >> str)
		  mp[stoi(str)].push_back(i);
}
		if(DEBUG){
			for(auto x:mp){
			cout<<x.first<<"->";
			for(auto i:x.second)
				cout<<i+1<<" ";
			cout<<endl;
		}

		}
			
cout<<func(0,1)<<endl;
	}
	
}