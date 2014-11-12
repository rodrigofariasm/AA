//Rodrigo Farias de Macêdo
 
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 

using namespace std;

int main(){

	long long n;
	
	scanf("%lld", &n);
	
	bool result = false;
	
	n = n*2;
	
	ceil(sqrt(n));	


	if(result == true){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	

	return 0;
}

