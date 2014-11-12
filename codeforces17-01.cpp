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
typedef vector<long long> vi;

int main(){
	string left = "", right = "", entrada, pesoslivres;
 	cin >> entrada;
 	cin >> pesoslivres;
 	
	for(int i = 0; i < entrada.size(); i++){
 		if(entrada[i] == '|'){
 			if(i >0) left = entrada.substr(0,i);
 			if(i < entrada[i]) right = entrada.substr(i+1, entrada.size());
 		}
 	}
 	 cout << right.size() - pesoslivres.size() - left.size();
 	if(left.size() < right.size()){
 		 int a = right.size() - left.size();
 		
		 if((right.size() - pesoslivres.size() - left.size()) % 2 == 0 && right.size() - pesoslivres.size() - left.size() <= 0){
 			left = left+pesoslivres.substr(0, a+1);
 			for(int i = a; i < pesoslivres.size(); i+=2){
 				left = left + pesoslivres[i];
 				right = right + pesoslivres[i+1];
 			}
 			cout << left << '|' << right;
 		}else{
 			cout << "Impossible";
 		}
 	} else if(left.size() == right.size()){
 		if(pesoslivres.size() % 2 == 0){
			for(int i = 0; i < pesoslivres.size(); i+=2){
 				left = left + pesoslivres[i];
 				right = right + pesoslivres[i+1];
 			}			
 			cout << left << '|' << right;
 		}else{
		 cout << "Impossible";
		}
	 }else{
 		 int a = left.size() - right.size();
		 if((left.size() - right.size() - pesoslivres.size()) % 2 == 0 && left.size() - right.size() - pesoslivres.size() <= 0){
		 	right = right+pesoslivres.substr(0,a+1);
		 	for(int i = a; i < pesoslivres.size(); i+=2){
 				left = left + pesoslivres[i];
 				right = right + pesoslivres[i+1];
 			}
 			cout << left << '|' << right;
 		}else{
 			cout << "Impossible";
 		}
 	}
}
