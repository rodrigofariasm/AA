// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int a[5][5];

int main(){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5 ; j++){
			cin >> a[i][j];	
		}
	}
	int aux[5];
	ll maior= 0;
	ll soma = 0;
	for(int i = 0; i < 5; i++){
		aux[i] = i;
	}
	do{
		soma += a[aux[0]][aux[1]] + a[aux[1]][aux[0]] + a[aux[2]][aux[3]] + a[aux[3]][aux[2]];
		soma += a[aux[1]][aux[2]] + a[aux[2]][aux[1]] + a[aux[4]][aux[3]] + a[aux[3]][aux[4]];
		soma += a[aux[2]][aux[3]] + a[aux[3]][aux[2]];
		soma += a[aux[4]][aux[3]] + a[aux[3]][aux[4]];
		if(soma > maior) maior = soma;
		soma = 0;
	}while(next_permutation(aux, aux+5));
	cout << maior << endl;
}
