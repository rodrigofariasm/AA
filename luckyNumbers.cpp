// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <algorithm> 
#include <vector>
#include <iterator>
#include <math.h>
using namespace std;

int main(){
	int q4=0, q7=0, moves = 0;
	string x, y;
	cin >> x >> y;
	for (int i = 0; i < x.length(); i++ ){
		if(x[i] == '4' && y[i] == '7') q4++;
		else if(x[i] == '7' && y[i] == '4') q7++;
	}
	while (q4 > 0 || q7>0){
		if(q4 > 0 && q7 > 0 ){
			q4--; q7--; moves++;
		}else if(q4 > 0){
			q4--; moves++;
		}else if(q7> 0){
			q7--; moves++;
		}
	}
	cout << moves;
	
	
	return 0;
}
