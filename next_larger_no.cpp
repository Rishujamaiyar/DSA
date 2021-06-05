#include <bits/stdc++.h>
using namespace std;

string func(string str){
	int n=str.length();
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=str[i];

	int a=arr[n-1];
	int index=0;
	for(int i=n-2;i>=0;i--){
		if(arr[i]>a){
			a=arr[i];
			continue;}
		else{
			index=i;
			break;
		}
	}
	if(index==n-1) index=n-2;
	string s1="-1";

	if(index==0) return s1;
	int temp=arr[index];
	arr[index]=arr[index+1];
	arr[index+1]=temp;
	sort(arr+index+1,arr+n);
	string s;
	for(int i=0;i<n;i++)
		s+=arr[i];

	return s;
}

int main(){
int t;
cin>>t;
while(t--){
	string str;
	cin>>str;
	cout<<func(str);

}	
}