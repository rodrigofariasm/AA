 // Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <utility>
#include <iterator>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
	map<char, long long> hash;
	
void iniciamapa(){
	hash['a'] = 1; hash['b'] = 2; hash['c'] = 3; hash['d'] = 4; hash['e'] = 5; hash['f'] = 6; hash['g'] = 7;hash['h'] = 8; hash['i'] = 9; hash['j'] = 10;hash['k'] = 11;
	hash['l'] = 12; hash['m'] = 13; hash['n'] = 14; hash['o'] = 15; hash['p'] = 16; hash['q'] = 17; hash['r'] = 18; hash['s'] = 19; hash['t'] = 20;
	hash['u'] = 21; hash['v'] = 22; hash['w'] = 23; hash['x'] = 24; hash['y'] = 25; hash['z'] = 26;
	hash['A'] = 27; hash['B'] = 28; hash['C'] = 29; hash['D'] = 30; hash['E'] = 31; hash['F'] = 32; hash['G'] = 33;hash['H'] = 34; hash['I'] = 35; hash['J'] = 36;hash['K'] = 37;
	hash['L'] = 38; hash['M'] = 39; hash['N'] = 40; hash['O'] = 41; hash['P'] = 42; hash['Q'] = 43; hash['R'] = 44; hash['S'] = 45; hash['T'] = 46;
	hash['U'] = 47; hash['V'] = 48; hash['W'] = 49; hash['X'] = 50; hash['Y'] = 51; hash['Z'] = 52;
	hash['0'] = 53; hash['1'] = 53; hash['2'] = 54; hash['3'] = 55; hash['4'] = 56; hash['5'] = 57; hash['6'] = 58;hash['7'] = 59; hash['8'] = 59; hash['9'] = 60;
	
}

int rabinKarp(char word[], int len){
	
	int resp = len;
	for(int i = 0; i<len; i++){ 
		int aux = len;
		if(len%(i+1) == 0){ // se pode ser um periodo
			long long hashw = 0;
			for(long long j = 0; j < len; j+=(i+1)){ //calcular os hashs
				long long auxh = 0, mod = 29, x;
				for (long long k = 0; k < i+1; k++){
					x = pow(61, k);
					auxh += (x * hash[word[j+k]]) % mod;
				}
				auxh = auxh%mod;
				if(hashw == 0){
					hashw = auxh;	
				} 
				aux = i+1;
				if(auxh - hashw != 0){
					aux = len+1;
					break;	
				}
			}
		}
		if(aux < resp){
			resp = aux;
		}
	}
	return resp;	
}


int main(){
	//std::ios_base::sync_with_stdio(false);
	int test;
	iniciamapa();
	char word[80];
	scanf("%d", &test);
	while(test--){
		int i = 0; char c;
		scanf("%s", &word);
		while (word[i]){
    		i++;
  		}
  		
  		int x = rabinKarp(word, i);
  		cout << x << endl;
  		if(test > 0){
  			cout << endl;
  		}
		
	}
}





