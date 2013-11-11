// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 

using namespace std;

int main(){
	int x, a, b;
	scanf("%d", &x);
	for (int i = 0; i < x; i++){
		scanf("%d %d", &a, &b);
		if( a > b){
			printf(">\n");
		}else if( b > a){
			printf("<\n");
		}else{
			printf("=\n");
		}
		
	}
	
	return 0;
}
