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
	
	long long test, coins;
	cin >> test;
	while(test--){
		long long cont = 0, soma = 0, aux, last;
		
		cin >> coins;
		vector<long long> values;
			for (long long i = 0; i<coins; i++){
			cin >> aux;
			values.push_back(aux);
		}
		for (int i = 0; i < coins-1; i++){
			if(values[i] > soma){
				if(soma + values[i] < values[i+1]){
					cont++;
					soma += values[i];
				}
			}
				
		}
		if(values[coins-1] > soma){
			cont++;
		}
		cout << cont << endl;
		
		
		
	
	}
	return 0;
}
