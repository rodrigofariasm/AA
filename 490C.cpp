// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	string s,a,b, a1, a2;
	int flag=0;
	cin >> s >>a >> b;
	int x = atoi(a.c_str());
	int y = atoi(b.c_str());
	int w, z;
	for(int i = a.size()-1; i < s.size() - b.size();i ++){
		a1 = s.substr(0, i);
		a2 = s.substr(i, s.size()-1);
		w = atoi(a1.c_str());
		z = atoi(a2.c_str());
		if(w%x==0 && z%y == 0){
			cout << "YES\n"<< a1 << " " << a2 << endl;
			flag = 1;
			break;
		}
	}
	if(flag ==0) cout <<"NO" <<endl;
}
