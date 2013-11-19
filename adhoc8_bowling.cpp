// Rodrigo Farias de Macêdo

#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <map>
#include <algorithm> 
#include <vector>
#include <iterator>

using namespace std;

int main(){
	string aux;
	vector<int> scores;
	map<string, int> mapa;
	mapa["0"] = 0, mapa["1"] = 1, mapa["2"] = 2, mapa["3"] = 3, mapa["4"] = 4, mapa["5"] = 5, mapa["6"] = 6;
	mapa["7"] = 7, mapa["8"] = 8, mapa["9"] = 9, mapa["/"] = 10, mapa["X"] = 10;

	while(getline(cin, aux) != "Game Over"){
		if(aux == "Game Over"){
	//		printf("\n");
			break;
		}
		istringstream iss(aux);
		vector<string> tokens;
		copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string> >(tokens));
		
		int jogadas = 1, score = 0, bonusRoll = 0, roll = 0, i = 0;
		string penRoll, actualRoll, extraRoll;
		while (jogadas < 11 && i < tokens.size()){
			actualRoll = tokens[i];
			if (actualRoll == "/"){
				score += 10 - mapa[penRoll];
				score += mapa[tokens[i+1]];
				roll = 0;
				jogadas++;
			}else if(actualRoll == "X"){
				extraRoll = tokens[i+2];
				score +=  10;
				if(extraRoll == "/"){
					score += 10;
				}else{
					score += mapa[tokens[i+1]] + mapa[tokens[i+2]];
				}
				roll = 0;
				jogadas++;
			}else{
				score += mapa[actualRoll];
				if(roll == 1){
					jogadas++;
					roll = 0;
				}else{
					penRoll = actualRoll;
					roll++;
				}
			}
			i++;
		}
		printf("%d\n", score);
	}
}
