// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

string s;
int a , b;
int contaB(){
	int c=0;
	for(int i = 0; i < s.size();i++){
		if(s[i] == 'B') c++;
	}
	return c;
}

ll arrange(){
	int b = contaB();
	int l = b-1, r = b;

}


void read(){
	while(!(cin >> a).eof()	){
		cin >>b;
		cin >> s;
		cout << arrange() <<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    read();
    return 0;
}
