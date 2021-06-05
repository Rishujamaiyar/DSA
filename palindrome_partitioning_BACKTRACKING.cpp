#include<bits/stdc++.h>
using namespace std;



    
    bool ispal(string str,int low,int high){
        while(low<high)
            if(str[low++]!=str[high--])
                return false;
        return true;
    }

   void dfs(vector<vector<string>>& res,vector<string>& curr,string s,int index){
       
        if(index >= s.length())
            res.push_back(curr);
        
        
        for(int i=index;i<s.length();i++){
            if(ispal(s,index,i)){
                string str_left = s.substr(index,i-index+1);
                cout<<str_left<<endl;
                curr.push_back(str_left);
                dfs(res,curr,s,i+1);
                curr.pop_back();
            }       
        }    
    }
    





int main(){
	string s = "radar";


	      vector<vector<string>> res;
        vector<string > curr;
        dfs(res,curr,s,0);
         for(auto x: res){
         	for(auto j:x)
         		cout<<j<<' ';
         	cout<<endl;
         }
         	

}