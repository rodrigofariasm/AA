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
	int a, b, ca, cb, w = 0, d = 0, l = 0;
	cin >> a >> b;
	for(int i = 1; i <= 6; i++){
		ca = abs(i - a);
		cb = abs(i - b);
		if(ca < cb){
			w++;
		}else if(ca == cb){
			d++;
		}else{
			l++;
		}
	}
	printf("%d %d %d", w, d, l);
	

}
