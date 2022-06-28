#include<iostream>
#include <algorithm>
using namespace std;
typedef long long ll; 

void check(ll arr[] , ll n , ll d){
	sort(arr , arr + n);
	if(arr[0]>d || arr[1]>d){
		cout<<"NO\n";
		return;
	}
	if(arr[0]+arr[1]>d){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
}
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    ll t;	cin>>t;
    while(t--){
    	ll n , d;	cin>>n>>d;
    	ll arr[n];
    	int flag = 0;
    	for(int  i = 0; i<n; i++){
    		cin>>arr[i];
    		if(arr[i]>d){
    			flag = 1;
    		}
    	}
    	if (flag==0)
    	{
    		cout<<"YES\n";
    	}
    	else
    	{
    		check(arr , n , d);    		
    	}
    }
}