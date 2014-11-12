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

int contaLivros(int array[], int i, int time, int end){
	int soma = 0;
	int l = i-1, r = i+1;
	if(time > array[i]){
		time -= array[i];
		soma++;
		while((l >= 0 || r < end) && time > 0){
			if(l >=0 && array[l] < array[r]){
				if(time > array[l]){
					time -= array[r];
					soma++; l--;
				}else{
					l--;
				}
			}else if(r < end && array[r] < array[l]){
				if(time > array[r]){
					time -= array[r];
					soma++; r++;
				}else{
					r++;
				}
			}
		}
		
	}
	return soma;
}

int main(){
	int b, t, l=0;
	scanf("%d %d", &b, &t);
	int r = b-1;
	int boo[b];
	for (int i = 0; i < b; i++){
		cin >> boo[i];
	}
	int lidos, max=0;
	while(l <= r){
		lidos = contaLivros(boo, r-1, t, b);
		if(lidos > max){
			max = lidos;
		}
//		cout << lidos << "lidos r " << r << endl;
	
		lidos = revContaLivros(boo, t, r);
		if(lidos > max){
			max = lidos;
			r-= max ;
		}
		r--;
//		cout << lidos << "lidos r " << r <<  endl;
		
	}
	cout << max << endl;
	
	return 0;
}
