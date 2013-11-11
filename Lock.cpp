// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 

using namespace std;
int calcGraus(int x, int y, bool z){
	int graus;
	if (x >= y){
		if(z){
			return (x-y)*9;
		}else{
			return (y+40-x)*9;
		}
	}else{
		if(z){
			return (x+40-y)*9;
		}else{
			return (y-x)*9;
		}
	}
}
int main(){
	int x, a, b, c;
	scanf("%d %d %d %d", &x, &a, &b, &c);
	while( x != 0 || a!=0 || b != 0 || c != 0){
		int graus = 1080;
		graus += calcGraus(x, a, true);
		graus += calcGraus(a, b, false);
		graus += calcGraus(b, c, true);
		printf("%d\n", graus);
		scanf("%d %d %d %d", &x, &a, &b, &c);
	}	
	return 0;
}
