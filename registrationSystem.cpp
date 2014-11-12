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

//int int_mod(int a, int b){
//	return (a%b +b) &b;
//}
int geraHash(string text, int m){
	 // calculate the hash value of the pattern
	int hasha = 0, base = 64, mod = 179424673;
	for(int i = 0; i< m; i++){
		int aux = hash[text[i]] * pow(base, i);
    	hasha +=  aux % mod;
    }
    return hasha%mod;
}
//
//int arabinKarp(char text[], char pattern[], int n, int m){
//	 // calculate the hash value of the pattern
//	int B = 64, M = 997;
//  	int hp = 0;
//  	for( int i = 0; i < m; i++) {
//  		hp = int_mod(hp * B + hash[pattern[i]], M);	
//  	}
//  		cout << hp << " hp" << endl;
//	// calculate the hash value of the first segment 
//	// of the text of length m
//    int ht = 0;
//    for(int i = 0; i < m; i++){
//    	ht = int_mod(ht * B + hash[text[i]], M);
//    	cout << ht << " ht" << endl;
//	}
//	
//	if(ht != hp){
//		return -1;
//	}
//	int E = pow(B, m -1);
//	int resp = 1;
//	int fl = 1;
//    for(int i = m; i < n; i++){
//    	
//    	ht = int_mod(ht - int_mod(hash[text[i - m]] * E%M, M), M);
//    	ht = int_mod(ht * B, M);
//    	ht = int_mod(ht + hash[text[i]], M);
//    		cout << ht << " ht" << endl;
//		if(ht == hp){
//			resp++;
//		}
//		if(fl == m && ht != hp){
//			return -1;
//		}
//    }
//    return resp;
//
//}



int main(){
	//std::ios_base::sync_with_stdio(false);
	iniciamapa();
	map<int, int> hashs;
	int test;
	cin >> test;
	char word[33];
	for(int a = 0; a < test; a++){
		cin >> word;
		int i=0;
		while (word[i]){
    		i++;
  		}
		int j = geraHash(word, i);
  		if(hashs[j] >=1){
  			cout << word <<hashs[j] << endl;	
  			hashs[j]++;
  		}else{
  			hashs[j] = 1;
  			cout << "OK"<<endl;
  		}
	}
}
