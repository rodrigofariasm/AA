// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll a, m;

int main(){
	cin >> a >> m;
	ll b = a%m + a;
	while(a < 10000000){
		if(a%m == 0){
			cout << "Yes" << endl;
			break;
		}else{
			a += a%m;
		}
			
	}
	if(a >= 100000) cout << "No"<<endl;
	 
	
	
	
	
	
	return 0;
}
