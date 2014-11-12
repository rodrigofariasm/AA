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

int t; //testcases number
int N; //size of the matrix
long long matrix[1026][1026];
char op[4];
long long sum;
int x, y; //coordenadas x y
int x2, y2; // coordenadas x2 y2, para o metodo SUM	
int value; //valor a ser adicionado.

long long rsq(int x, int y){
	 int y1;
	 int x1 = x;
	 long long sumaux = 0;
	 for (; x1; x1-= x1&(-x1)){
	 	y1 = y;
	 	for(y1 = y; y1 > 0; y1 -= y1&(-y1)){
	 		sumaux += matrix[x1][y1];
	 	}
	 }
	 return sumaux;
}

long long rsq(int x1, int y1, int x2, int y2){
	 return rsq(x2,y2)-rsq(x1-1,y2)-rsq(x2,y1-1)+rsq(x1-1,y1-1);
	
}

long long rsqaux(int x, int y){		
    return rsq(x,y,x,y);
}
	

void update(int x , int y , int val){
	long long a=val-rsqaux(x,y);
    
    for(;x<1026;x+=(x & -x))
        for(int i=y;i<1026;i+=(i & -i)) matrix[x][i]+=a;
}

int main(){
	
	scanf("%d", &t);

	for(t; t > 0; t--){
		scanf("%d", &N);
		for(int i=0;i<=N;i++) fill(matrix[i],matrix[i]+N+1,0);
		 while(1){
            scanf("%s",op);
            if(op[0]=='E') break;
			 if(op[1]=='E'){
                scanf("%d %d %d",&x,&y,&value);
                x++; y++;
                update(x,y,value);
            }else{
                scanf("%d %d %d %d",&x,&y,&x2,&y2);
                x++; y++; x2++; y2++;
                printf("%lld\n",rsq(x,y,x2,y2));
            }
		
		}
	}			
}
