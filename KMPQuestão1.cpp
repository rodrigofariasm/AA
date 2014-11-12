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

int rabinKarp(char word[], int len){
	map<char, long long> hash;
	hash['a'] = 1; hash['b'] = 2; hash['c'] = 3; hash['d'] = 4; hash['e'] = 5; hash['f'] = 6; hash['g'] = 7;hash['h'] = 8; hash['i'] = 9; hash['j'] = 10;hash['k'] = 11;
	hash['l'] = 12; hash['m'] = 13; hash['n'] = 14; hash['o'] = 15; hash['p'] = 16; hash['q'] = 17; hash['r'] = 18; hash['s'] = 19; hash['t'] = 20;
	hash['u'] = 21; hash['v'] = 22; hash['w'] = 23; hash['x'] = 24; hash['y'] = 25; hash['z'] = 26;
	int resp = len;
	for(int i = 0; i<len; i++){ 
		int aux = 0;
		long long hashw = 0;
		if(len%(i+1) == 0){ // se pode ser um periodo
			cout << i+1 << " i+1" << endl; 
			for(int j = 0; j < len; j+=i+1){ //calcular os hashs
				long long auxh = 0;
				for (int k = 0; k < i+1; k++){
					auxh += (pow(27, k) + hash[word[j+k]]);//%5;
				}
				//auxh = auxh%5
				cout << auxh << " auxh" << endl;
				if(hashw == 0) hashw = auxh;
				if(auxh - hashw != 0) aux = len+1; cout << "quebrou"<<endl; break;
				aux = i+1;
				cout << aux << " aux" << endl;
				if(aux < resp) resp = aux;
			}
		}
		
	}
	return resp;	
}


int main(){
	//std::ios_base::sync_with_stdio(false);
	int test;
	char word[80];
	scanf("%d", &test);
	while(test--){
		int i = 0; char c;
		scanf("%s", &word);
		while (word[i]){
		    c=word[i];
    		word[i] = tolower(c);
    		i++;
  		}
  		cout<< rabinKarp(word, i)<<endl;
		
	}
}
