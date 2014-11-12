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
#define _USE_MATH_DEFINES

using namespace std;

int main(){
	int times;
	scanf("%d", &times);
	while(times--){
		int pies, galera;
		double soma = 0;
		scanf("%d %d", &pies, &galera);
		float array[pies];
		float aux;
		for(int i = 0; i<pies; i++){
			cin >> aux;
			array[i] = aux*aux*M_PI ;
			soma += array[i];
		}
		int fatias = 0;
		float l = 0, r = 4e8, aux2 = 0;
		float media = soma/(galera+1);
		int x = 43;
		while(x--){
		//	cout << l << " L R "  << r << endl;
			for(int i = 0; i < pies; i++){
		//		cout << static_cast<int>(array[i]/media + 0.000001) << endl;
				fatias += static_cast<int>(array[i]/media);
				//cout << fatias<< " das" << endl;
			}
		//	cout << fatias << " FATIAS MEDIA " << media << endl;
		
			
			if(fatias == galera+1){
				aux2 = media;
				l = media + 0.0001;
				media = l + (r-l)/2;
			}else if(fatias < galera+1){
				fatias = 0;
				r = media - 0.0001;
				media = l + (r-l)/2;
			}else{
				aux2 = media;
				l = media + 0.0001;
				media = l + (r-l)/2;
			}
			fatias = 0;	
		}
		printf("%.4f\n", aux2);
	}	
		
	
	return 0;
}
