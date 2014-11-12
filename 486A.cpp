// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n;

int main(){
	cin >> n;
	if(n %2 == 0){
		cout << n/2 << endl;
	}else{
		cout << n/2 - n << endl;
	}
	
	return 0;
}
