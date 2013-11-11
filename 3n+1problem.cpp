// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 


using namespace std;

int cycleLength(int x){
	int z = 1;
	while(x != 1 ){
	
		if (x%2 == 0){	
			x = x/2;
		}else{
			x = 3*x +1;
		}
		z += 1;
	}
	return z;
}

int main(){
	int l, r;
	while(scanf("%d %d", &l, &r) != EOF){
		int max = 0;
		
		if (l>r){
			for (int i = r; i <= l; i++){
				int a = cycleLength(i);
				if (a > max){
					max = a;
				}
			}	
		}else{
			for (int i = l; i <= r; i++){
 				int a = cycleLength(i);
				if (a > max){
					max = a;
				}
			}
		}
		printf("%d %d %d\n", l ,r, max);
	}
	return 0;
}
