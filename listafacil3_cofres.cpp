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
	int n, testes = 1, aux, i, j;
	scanf("%d", &n);
	
	while(n!=0){
		aux = 0;
		int array[n];
		for(int k = 0; k< n; k++){
			cin >> i >> j;
			aux += i-j;
			array[k] = aux;
//			printf("%d\n", aux);
		}
		printf("Teste %d\n", testes);
		for(int k = 0; k< n; k++){
			printf("%d\n", array[k]);
		}
		printf("\n");
		testes++;
		scanf("%d", &n);
	}
		
	return 0;
}
