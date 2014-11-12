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



int main(){
	int testes, pal, ver;
	cin >> testes;
	
	while(testes--){
		map<string, string> dic;
		cin >> pal >> ver;
		string jap, por;
		cin.ignore();
		for(int i = 0; i < pal; i++){
			getline(cin, jap);
			getline(cin, por);
			dic[jap] = por;
		}
		string result = "";
		for (int i = 0; i < ver; i++){
		
			string s;
			getline(cin, s	);
			istringstream iss(s);
			do{
        	string sub;
        	iss >> sub;
        	if(dic.count(sub) > 0){
        		result += dic[sub] + " ";
        	}else result += sub + " ";
        	} while (iss);
    		result += "\n";
		}
		cout << result;
	}
	
}    
