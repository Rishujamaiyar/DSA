#include <bits/stdc++.h>
using namespace std;
string patt(string str){
    map <char,int> mp;
    int k=0;
    string s1;
    for(auto x:str){
    	if(mp.find(x)==mp.end())
    		mp[x]=k++;
    	s1+=to_string(mp[x]);
    }
    
    return s1;
}

int main(){
string str= "foo";

 vector<string>  dict = { "abb", "abc", 
                                   "xyz", "xyy" }; 
   vector<string> v;
   for(auto x:dict){
       if(patt(x)==patt(str))
        v.push_back(x);
   }

   sort(v.begin(),v.end());
   for(auto x:v) cout<<x<<" ";


			
	}


