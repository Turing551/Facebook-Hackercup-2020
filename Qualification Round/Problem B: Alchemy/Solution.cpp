#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
	freopen("alchemy_input.txt", "r", stdin);
	freopen("alchemy_output.txt", "w", stdout);
	int n; 
	cin>>n;
	for(int i=1;i<=n;i++){
		cout << "Case #" << i << ": ";
		int a; 
		cin>>a;
		string arr; 
		cin>>arr;
		int x=0,y=0;
		for(int j=0;j<a;j++){
			if(arr[j]=='A')	x++;
			if(arr[j]=='B')	y++;
		}
		if(abs(x-y) == 1){
			cout<<"Y"<<endl;
		}else{
			cout<<"N"<<endl;
		}
	}
}
