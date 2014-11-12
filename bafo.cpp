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
	int n, a, b, testes = 1;
	scanf("%d", &n);
	
	while(n != 0){
		int i = 0, j = 0;
		for(int k = 0; k < n; k++){
			cin >> i >> j;
			a += i; b+= j;
		}
		cout << "Teste " << testes << endl;
		if (a >= b){
			cout << "Aldo\n" << endl;
		}else{
			cout << "Beto\n" << endl;
		}
		a = 0, b = 0;
		testes++;
		scanf("%d", &n);
	}
	return 0;
}
