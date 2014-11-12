// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <utility>
#include <iterator>
#include <math.h>
#include <set>
#include <map>


using namespace std;


int main(){
	string line1, line2, line3;
	cin >> line1 >> line2 >> line3;
	line1+= line2;
	sort(line1.begin(), line1.end());
	sort(line3.begin(), line3.end());
	if(line1 == line3) cout << "YES\n";
	else cout << "NO\n";
}    
