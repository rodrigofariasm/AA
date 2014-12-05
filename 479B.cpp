// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int a,b,c;
int main(){
	cin >> a >> b >> c;
	int x = a+b+c;
	int y = a*(b+c);
	int w = (a+b)*c;
	int z = a*b*c;
	a = max(x,y);
	b = max(w,z);
	cout << max(a,b) << endl;
	return 0;
}
