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
	int n;
	string x = "sim";
	scanf("%d", &n);
	//printf("%d", n%2);
	if(n%2 == 0){
		if(n != 2)x = "nao";
	}else{
		for (int i = 3; i < 1000000; i += 2 ){
			if(n%i == 0){
				x = "nao";
				break;
			}
		}
	}
	cout << x << endl;
	
	return 0;
}
