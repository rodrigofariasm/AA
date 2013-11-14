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
	int n;
	scanf("%d", &n);
	stringstream ss;
	for (int i = 0; i < n; i++){
		for (int j = i; j < (i+n);j++){
			if(j < n){
				printf("%d ", (n*(j-i) + j + 1));
				
			}else{
				printf("%d ", (n*(j-i) + j - n + 1));
			}
			if(j == i+n-1){
				printf("\n");
			}
		}
	}	
	return 0;
}
