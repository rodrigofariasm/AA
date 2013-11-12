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

int reverse(int x){
	string s ;
	stringstream convert;
	convert << x;
	s = convert.str();
	string result = "";
	
	for(int i = s.length(); i > 0; i--){
		char a =s[i-1]; 
		if( a != '0'){
			result += a;
		}
	}
	
	int numb;
	istringstream( result )>> numb;
	return numb;
}

int main(){
	int n, a, b, soma;
	
	scanf("%d", &n);
	
	for(int i = 0; i <n; i++){
		scanf("%d %d", &a, &b);
		soma = reverse(a) + reverse(b);
		soma = reverse(soma);
		printf("%d\n", soma);
	}
	

	
}
