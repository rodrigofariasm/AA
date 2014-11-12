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
	hash['0'] = 1; hash['1'] = 2; hash['2'] = 3; hash['3'] = 4; hash['4'] = 5; hash['5'] = 6; hash['6'] = 7 ;hash['7'] = 8 ; hash['8'] = 9; hash['9'] = 10;
	
}

//int int_mod(int a, int b){
//	return (a%b +b) &b;
//}
int geraHash(string text, int m){
	int hasha = 0, base = 11, mod = 179424673;
	for(int i = 0; i< m; i++){
		int aux = hash[text[i]] * pow(base, i);
    	hasha +=  aux % mod;
    }
    return hasha%mod;
}



int main(){
	//std::ios_base::sync_with_stdio(false);
	iniciamapa();
	int test, phones;
	cin >> test; 
	string word;
	
	for(int a = 0; a < test; a++){
		cin>> phones;
		bool continua = true;
		map<int, int> hashs;
		vector<string> words;
		for (int b = 0; b<phones;b++){
			cin >> word;
			int i=0;
			while (word[i]){
    			i++;
    		}
    		words.push_back(word);
		}
		for(int p = 1; p<11;p++){
			for (int b = 0; b<phones;b++){
				word = words[b];
				if(word.size() == p){
					int i=0;
					int j;
					while (word[i]){
    					i++;
    					j = geraHash(word, i);
    					if(hashs[j] ==1){
		  					continua = false;
		  					break;
  						}
  					}
  					hashs[j] =1;
  				}	
			}
		}
		if(continua){
				cout <<"YES"<<endl;
		}else{
			cout << "NO" << endl;
		}
		
	}
}
