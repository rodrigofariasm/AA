// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <utility>
#include <iterator>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main(){
	int n;
	bool x = true;
	cin >> n;
	if(n%2 == 0){
		cout << (n*n)/2 << endl;
		for(int i = 0; i < n; i++){
			string s = "";
			for(int j = 0; j<n; j++){
				if(x){
					s = s + "C";
					x = false;
				}else{
					s = s + ".";
					x = true;
				}
			}
			if(x) x = false;
			else x = true;
			cout << s << endl;
		}
	}else{
		cout << (n*n)/2 +1 << endl;
		for(int i = 0; i < n; i++){
			string s = "";
			for(int j = 0; j<n; j++){
				if(x){
					s = s + "C";
					x = false;
				}else{
					s = s + ".";
					x = true;
				}
			}
			cout << s << endl;
		}
	}
	
	
	return 0;
}
