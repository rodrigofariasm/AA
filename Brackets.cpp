// Rodrigo Farias de Macêdo  com bit
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
struct seg{
  int FE; 
  int FD;
};

int tests = 0;
seg T[30005*4];
int index[30005];
char br[30005];

int left(int p){return p << 1;}
int right(int p){return (p << 1)+1;}

void build(int p, int l, int r){
	if(l==r){
		index[l] = p;
		if(br[l] == '('){
			T[p].FD=1; //falta fechar a direita
		}else{
			T[p].FE=1; // falta fechar a esquerda
		}
	}else{
		build(left(p), l, (l+r)/2);
		build(right(p), (l+r)/2+1, r);
		seg p1 = T[left(p)], p2 = T[right(p)];
		int aux = p1.FD - p2.FE;
		if(aux < 0 ? T[p].FD = p2.FD : T[p].FD = p1.FD + p2.FD - p2.FE);
		aux = p2.FE - p1.FD;
		if(aux < 0 ? T[p].FE = p1.FE : T[p].FE = p1.FE + p2.FE - p1.FD);
		
	}
}

void update(int node){
	
		if(T[node].FD == 0){
			T[node].FD = 1;
			T[node].FE = 0;
		}else{
			T[node].FD = 0;
			T[node].FE = 1;
		}
		while(node != 0){
			node = node/2;
			seg p1 = T[left(node)], p2 = T[right(node)];
			int aux = p1.FD - p2.FE;
			if(aux < 0 ? T[node].FD = p2.FD : T[node].FD = p1.FD + p2.FD - p2.FE);
			aux = p2.FE - p1.FD;
			if(aux < 0 ? T[node].FE = p1.FE : T[node].FE = p1.FE + p2.FE - p1.FD);
		}
}
 

int main(){
	int n, m, q;
	seg ex;
	ex.FD = 0; ex.FE = 0; 
	for(tests = 0; tests < 10; tests++){
		for(int i=0;i<=n*4;i++) T[i]=ex;
		printf("Test %d:\n", tests+1);
		scanf("%d", &n);
		scanf("%s", &br);
		build(1, 0, n-1);
		scanf("%d", &m);
		while(m--){
		scanf("%d", &q);
		if(q == 0){
			if(T[1].FD == 0 && T[1].FE == 0){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}else{
			update(index[q-1]);
		}
	}
		
	}
}
