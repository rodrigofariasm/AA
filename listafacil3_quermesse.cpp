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
	int n, ind = 0, testes = 1;
	scanf("%d", &n);
	
	while(n != 0){
		int aux = 0;
		for(int i = 0; i < n; i++){
			cin >> ind;
			if(ind == i+1){
				aux = ind;
			}
		}
		printf("Teste %d\n%d\n\n", testes, aux);
		testes++;
		scanf("%d", &n);
	}
	return 0;
}
