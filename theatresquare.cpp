// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 
#include <vector>

using namespace std;

int main(){
	int n, m , a, l = 0; 
	cin >> n >> m >> a;
	if (n%a != 0 && n/a > 0){
		l+= n/a +1;
	}else if(n>a)l += n/a;
	if (m%a != 0 && m/a > 0){
		l+= m/a +1;
	}else if(m > a)l += m/a;
	if(n <= a && m <= a) l = 1;
	cout << l << endl;
	return 0;
}
