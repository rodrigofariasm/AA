// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n, c;
map<char, int > mapa;
char s[100009];
int main(){
	mapa['a'] = 1; mapa['b'] = 2; mapa['c'] = 3; mapa['d'] = 4; mapa['e'] = 5; mapa['f'] = 6; mapa['g'] = 7; mapa['h'] = 8; mapa['i'] = 9; mapa['j'] = 10;
	mapa['k'] = 11; mapa['l'] = 12; mapa['m'] = 13; mapa['n'] = 14; mapa['o'] = 15; mapa['p'] = 16; mapa['q'] = 17; mapa['r'] = 18; mapa['s'] = 19; mapa['t'] = 20;
	mapa['u'] = 21; mapa['v'] = 22; mapa['w'] = 23; mapa['x'] = 24; mapa['y'] = 25; mapa['z'] = 26; 
	cin >> n >> c;
	cin >> s;
	c--;
	ll soma = 0;
	ll mid1, mid2;
	if(n%2 == 0){
		mid1 = n/2-1;
		mid2 = n/2;
	}else{
		mid1 = n/2-1;
		mid2 = n/2-1;
	}
	if(c <= mid1){
		ll aux;
		while(c <= mid1){
			aux = mid1 -c;
			if(mapa[s[c]] > mapa[s[mid2+aux]]){
				soma += min(mapa[s[c]] - mapa[s[mid2+aux]], 26 - (mapa[s[c]] - mapa[s[mid2+aux]]));	
			}else{
				soma += min(mapa[s[mid2+aux]]- mapa[s[c]], 26 - (mapa[s[mid2+aux]] - mapa[s[c]]) );	
			}
			
			if(c == mid1){
				c--; 
				soma++;
				break;
			}
			c++;
			soma++;	
			
		}
		
		while(c >= 0){
			aux = mid1 -c;
			if(mapa[s[c]] > mapa[s[mid2+aux]]){
				soma += min(mapa[s[c]] - mapa[s[mid2+aux]], 26 - (mapa[s[c]] - mapa[s[mid2+aux]]));	
			}else{ 
				soma += min(mapa[s[mid2+aux]]- mapa[s[c]], 26 - (mapa[s[mid2+aux]] - mapa[s[c]]) );	
			}
			if(c == 0){
				break;	
			}
			c--;
			soma++;
		}
	}else{
		ll aux= c - mid2;
		c = mid1 - aux; 
		while(c <= mid1){
			aux = mid1 -c;
			if(mapa[s[c]] > mapa[s[mid2+aux]]){
				soma += min(mapa[s[c]] - mapa[s[mid2+aux]], 26 - (mapa[s[c]] - mapa[s[mid2+aux]]));	
			}else{
				soma += min(mapa[s[mid2+aux]]- mapa[s[c]], 26 - (mapa[s[mid2+aux]] - mapa[s[c]]) );	
			}
			
			if(c == mid1){
				c--; 
				soma++;
				break;
			}
			c++;
			soma++;	
			
		}
		
		while(c >= 0){
			aux = mid1 -c;
			if(mapa[s[c]] > mapa[s[mid2+aux]]){
				soma += min(mapa[s[c]] - mapa[s[mid2+aux]], 26 - (mapa[s[c]] - mapa[s[mid2+aux]]));	
			}else{ 
				soma += min(mapa[s[mid2+aux]]- mapa[s[c]], 26 - (mapa[s[mid2+aux]] - mapa[s[c]]) );	
			}
			if(c == 0){
				break;	
			}
			c--;
			soma++;
		}
	}
	
	cout << soma << endl;
		
	
}
