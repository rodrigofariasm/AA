// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <cctype>
#include <algorithm> 
#include <vector>
#include <utility>
#include <iterator>
#include <math.h>

using namespace std;

int coord(string x){
	int i;
	if(x[0] == 'a') i = 1;
	else if(x[0] == 'b') i = 2;
	else if(x[0] == 'c') i = 3;
	else if(x[0] == 'd') i = 4;
	else if(x[0] == 'e') i = 5;
	else if(x[0] == 'f') i = 6;
	else if(x[0] == 'g') i = 7;
	else if(x[0] == 'h') i = 8;
	return i;
}

int main(){
	string s, t;
	cin >> s >> t;
	int li, ci, lf, cf;
	ci = coord(s);
	li = s[1] - '0';
	lf = t[1] - '0';
	cf = coord(t);
	int cont = 0;
	
	int ls = abs(li-lf), cs = abs(ci-cf);
	if(ls > cs) cout << ls << endl;
	else cout << cs << endl;
	
	while(li != lf || ci != cf){
		if(ci > cf){
			cout << 'L';
			ci--;
		}else if(cf > ci){
			cout << 'R';
			ci++;
		}
	
		if(li > lf){
			cout << 'D';
			li--;
		}else if(lf > li){
			cout << 'U';
			li++;
		}
	
		cout << endl;
	}
	return 0;
}
