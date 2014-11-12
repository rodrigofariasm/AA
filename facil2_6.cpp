// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <utility>
#include <iterator>
#include <math.h>
#include <set>
#include <map>


using namespace std;

string decodificador(string exam){
	string result = "";
	map<char, char> cod;
	cod['1'] = '1';
	cod['A'] = '2'; cod['B'] = '2'; cod['C'] = '2'; cod['D'] = '3'; cod['E'] = '3'; cod['F'] = '3'; cod['G'] = '4'; cod['H'] = '4'; cod['I'] = '4'; cod['J'] = '5'; cod['K'] = '5';
	cod['L'] = '5'; cod['M'] = '6'; cod['N'] = '6'; cod['O'] = '6'; cod['P'] = '7'; cod['Q'] = '7'; cod['R'] = '7'; cod['S'] = '7'; cod['T'] = '8'; cod['U'] = '8'; cod['V'] = '8';
	cod['W'] = '9'; cod['X'] = '9'; cod['Y'] = '9'; cod['Z'] = '9'; cod['0'] = '0';
	for(int i = 0; i < exam.size(); i++){
		if(exam[i] == '-') result+='-';
		else result += cod[exam[i]];
		
	}
	return result;
}


int main(){
	string entrada;
	while(cin >> entrada){
		string x = decodificador(entrada);
		cout<< x << endl;
	}
	
}    
