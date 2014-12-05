// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int a[5];
string s;
int main(){
	for(int i = 0; i < 4; i++){
		cin >> a[i];
	}
	cin >> s;
	ll soma = 0;
	for(int i = 0; i< s.size(); i++){
		soma += a[s[i]-'0'-1];
	}		
	cout << soma << endl;
}
