// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX 110111100000101101101011001110100111011001000000000000000000
#define MIN -1000000000
ll A[64];
ll q, l , r, maior, res; 


ll achamaior(ll l, ll r){
	for(int i = 62; i>=0; i--){
		if(A[i] >= l && A[i] <= r) return A[i] ;
	}
	ll num;
	int i;
	for(i = 0; i<61; i++){
		if(A[i] <= l && A[i+1] >= r) {
			num = A[i];
		}
	}
	for(int j = i-1; j>=0; j--){
		cout << "num = " << num<< endl;
		if(num + A[j] <= r) {
			num += A[j];
		}
	}
	return num;	
}


int main(){
	for(int i = 0; i<62; i++){
		A[i] = pow(2,i)-1;
	}
	cin >> q;
	while(q--){
		cin >> l >> r;
		res = achamaior(l,r);
		cout << res << endl;
	}
	
	
	
	
	return 0;
}
