// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm> 

using namespace std;

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	while(m!= 0 && n != 0){
		
		if(m == 1){
			printf("%d knights may be placed on a %d row %d column board.\n", n, m, n);
		}else if(n == 1){
			printf("%d knights may be placed on a %d row %d column board.\n", m, m, n);
		}else if(m == 2){
			int aux;
			if(n%4 == 1){
				aux = n/4 * 4 + 2;
			}else if(n%4 == 0){
				aux = n/4 * 4 ;
			}else{
				aux = n/4 *4 + 4;
			}
			printf("%d knights may be placed on a %d row %d column board.\n", aux, m, n);
		}else if(n == 2){
			int aux;
			if(m%4 == 1){
				aux = m/4 * 4 + 2;
			}else if(m%4 == 0){
				aux = m/4 * 4 ;
			}else{
				aux = m/4 *4 + 4;
			}
			printf("%d knights may be placed on a %d row %d column board.\n", aux, m, n);
		}else{
			int aux = 0;
			int col;
			for(int i = 0; i < n; i+=2){
				col = i;
				for(int j = 0; j < m; j++){
					if(col < n){
						col++;
						aux++;
					}else{
						break;
					}
					
				}	
			}
	
			for(int i = 2; i < m; i+=2){
				int lin = i;
				for(int j = 0; j < n; j++){
					if(lin < m){
						lin++;
						aux++;
					}else{
						break;
					}
				}	
			}
			printf("%d knights may be placed on a %d row %d column board.\n", aux, m, n);
		}
		
		scanf("%d %d", &m, &n);
				
	}
	
	
		
}
