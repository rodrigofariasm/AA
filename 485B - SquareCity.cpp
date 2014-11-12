// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX 1000000000
#define MIN -1000000000

int n;

int main(){
	cin >> n;
	ll x, y;
	ll minx = MAX, maxx = MIN, miny = MAX, maxy= MIN;
	while(n--){
		cin >> x >> y;
		if(x < minx) minx = x;
		if(x > maxx) maxx = x;
		if(y < miny) miny = y;
		if(y > maxy) maxy = y;
	}
	ll a = maxx- minx;
	ll b = maxy - miny;
	if(a < b){
		cout << b*b << endl;
	}else{
		cout << a*a << endl;
	}
	
	
	
	
	return 0;
}
