// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <iterator>
#include <math.h>
using namespace std;

int main(){
	long long b, lastp, minp = 0, aux;
	cin >> b >> lastp;
	long long dist = b;
	lastp--;
	vector<long long> box;
	for (int i = 0 ;i < b; i++){
		cin >> aux;
		box.push_back(aux);
	}
	for(int i = 1; i < b; i++){
		if(box[i] == box[minp]){
			if(i <= lastp && lastp - i < dist){
				dist = lastp - i;
				minp = i;
			}else if(i > lastp && lastp + b - 1 - i < dist){
				minp = i;
				dist = lastp + b - 1 - i;
			}
		}else if(box[i] < box[minp]){
			minp = i;
			if(i <= lastp){
				dist = lastp - i;
				minp = i;
			}else if(i > lastp){
				dist = lastp + b - 1 - i;
			}
		} 
		
	}
	if(box[minp] == box[lastp]){
		minp = lastp;
	}
	aux = box[minp];
	bool flag;
	long long num_it = box[minp]*b;
	if(lastp < minp){
		 num_it += lastp+1 + b - (minp+1); 
		 flag = false;
	}else{ 
		num_it += lastp+1 - (minp+1); 
		flag = true;
	}
	for (long long i = 0; i < b; i++){
		if(flag && i <= lastp && i> minp){
			box[i] -= aux+1;
			 
		}else if(flag){
			box[i] -= aux;
		}else if(!flag && (i > minp || i <= lastp)){
			box[i] -= aux +1;
		}else{
			box[i] -= aux;
		}
	}
	box[minp] = num_it;
	for (long long i = 0; i < b-1; i++){
		cout << box[i] << " ";
	}
	cout << box[b-1] << endl;
	return 0;
}
