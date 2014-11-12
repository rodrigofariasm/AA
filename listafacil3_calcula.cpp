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
	int n, testes = 1, aux, i = 0;
	string exp;
	scanf("%d", &n);
	
	while(n!=0){
		int cont = 0;
		cin >> exp;
		int array[n];
		char operadores[n-1];
		aux = 0;
		for (int j = 0; j < exp.length(); j++){
			if (exp[j] == '+' || exp[j] == '-'){
				string x = exp.substr(i, j-i);
//				cout << x << "e" << endl;
				istringstream (x) >> array[cont];
				cont++;
				operadores[cont-1] = exp[j];
//				cout << operadores[cont-1] << "ope" << endl;
				i = j+1;
//				cout << array[n] << "dsa" << endl;
			}else if(j == exp.length()-1){
				string x = exp.substr(i, string::npos);
//				cout << x << "e" << endl;
				istringstream (x) >> array[cont];
//				cout << array[n] << "dsa" << endl;
				
			}
		}
		if(operadores[0] == '+'){
//			cout << array[0] << " " << array[1] << endl;
			aux += array[0] + array[1];
		}else{
			aux += array[0] - array[1];
		}
//		cout << "soma "<< aux << endl;
		for (int k = 1; k<n-1; k++){
			if(operadores[k] == '+'){
				aux += array[k+1];
			}else{
				aux -= array[k+1];
			}
//			cout << "soma "<< array[k+1] << endl;
		}
		printf("Teste %d\n%d\n\n", testes, aux);
		testes++;
		scanf("%d", &n);
		i=0;
		
		
	}
	return 0;
}
