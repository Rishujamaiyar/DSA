#include <bits/stdc++.h>
using namespace std;
int maximizeTheCuts(int n)
{
   int wt[] = {1,2,3,4,5,6,7,8};
   int val[] = {1, 5, 8, 9, 10, 17, 17, 20};
   int w = n;
   int a = n;
   
   int t[a+1][w+1];
   for(int i=0;i<w+1;i++) t[0][i] = 0;
   for(int i=0;i<a+1;i++) t[i][0] = 0;
   
   for(int i=1;i<a+1;i++){
       for(int j=1;j<w+1;j++){
           if(wt[i-1]<=j)
           t[i][j] = max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
           else
           t[i][j] = t[i-1][j];
       }
   }
   for(int i=0;i<a+1;i++){
       for(int j=0;j<w+1;j++){
           cout<<t[i][j]<<" ";
       }cout<<endl;
   }

   return t[a][w];
}
int main(){
	cout<<maximizeTheCuts(8);
}