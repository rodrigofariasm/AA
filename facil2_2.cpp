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

int calcula(vector<int> a, vector<int> b){
	int counta = 0, countb = 0;
	int x[100000], y[100000];
	for(int i = 0; i < 100000;i++){
		x[i] = 0; y[i] = 0;
	}
	for(int i = 0; i < a.size();i++){
		x[a[i]-1]++;
	}
	for(int i = 0; i < b.size();i++){
		y[b[i]-1]++;
	}

	for(int i = 0; i < 100000;i++){
		if(x[i] >= 1 && y[i] == 0){
			counta++;
			x[i]--; y[i]++;
		}else{
			if(y[i] >= 1 && x[i] == 0){
				countb++;
				y[i]--; x[i]++;
			}
		}
	}
	if(counta > countb)return countb;
	else return counta;
	
	
}

int main(){
	int a, b,aux;;
	cin >> a >> b;
	while(a!= 0 || b!=0){
		vector<int> ca, cb;
		for(int i = 0; i<a; i++){
			cin >>aux;
			ca.push_back(aux);
		}
		for(int i = 0; i<b; i++){
			cin >>aux;
			cb.push_back(aux);
		}
		int x = calcula(ca, cb);
		cout << x <<endl;
		cin >> a >> b;
	}
	
}
