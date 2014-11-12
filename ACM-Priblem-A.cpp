// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long




void read(){
	int x;
	int a=0,b=0, i = 4, j = 4;
	while(!(cin >> x).eof()	){
		if(i>= 0){
			a+= pow(2,i)*x;	
			i--;
		}else if(j >= 0){
			b+= pow(2,j)*x;
			j--;
		}
		
		if(i < 0 && j < 0){
			if(a+b == 31){
    			cout << "Y" <<endl;
    		}else{
   		 		cout << "N" <<endl;
   	 		}
   	 		a = 0; b = 0; i = 4; j = 4;
		}
    	
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    read();
    return 0;
}
