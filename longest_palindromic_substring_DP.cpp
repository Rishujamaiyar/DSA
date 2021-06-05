#include <bits/stdc++.h>
using namespace std;



string longestPalindrome(string s) {
    int n = s.length();
    bool t[n][n];
    memset(t,0,sizeof(t));
    
    int start=0,max=1;
    
    for(int i=0;i<n;i++) t[i][i] = true;
    int flag = 0;
    
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            t[i][i+1] = true;
            if(flag==0){
                start =i;
                max =2;
                flag=1;
            }
        }
    }
    
    for(int k=3;k<=n;k++){
        for(int i=0;i<n-k+1;i++){
            int j=i+k-1;
            if(t[i+1][j-1] && s[i]==s[j]){
                t[i][j] = true;
                if(k>max){
                    start =i;
                    max=k;
                }
            }
        }
    }
    string str;
    for(int i=start;i<start+max;i++)
    str.push_back(s[i]);
    return str;
}
int main(){
  string s;
  cin>>s;
  string s2=longestPalindrome(s);
  cout<<s2;
  
}