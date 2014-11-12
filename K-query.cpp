// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, q;
const long long maxval = 1000000000;
ll a[30000];


int kquery(ll l, int r, ll k){
	int count=0;
	while (l <= r){
		if(a[l] > k){
			count++;	
		} 
		l++;
	}
	return count;
}


int main(){
	int l, r;
	long long k;
	cin >> n;
	int numg = sqrt(n) + 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cin >> q;
	while(q--){
		cin >> l >> r >> k;
		cout << kquery(l, r, k) << endl;
	}
}
