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

	int n, k;
	scanf("%d %d", &n, &k);
	int esq = 0, dir = n, testes = 0;
	int media = (dir + esq) / 2 + (dir + esq) % 2;
	bool aux = false;
	while (dir - esq > 1){
		
		if (k == 1){
			aux = true;
			esq = media;
			media = (dir + esq) / 2;
		}else{
			dir = media;
			media = (dir + esq) / 2 + (dir + esq) % 2;
			k --;
			}
		testes++;
	}
	if(aux){
		testes++;	
	}
	printf("%d\n", testes);
	
	
	
}
