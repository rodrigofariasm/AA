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
	int n, nota, inst = 1;
	string aluno;
	
	while(scanf("%d", &n) != EOF){
		int min =100000;
		map<int, string> alunos;
		for(int i = 0; i < n; i++){
			cin >> aluno >> nota;
			if(alunos[nota] < aluno){
				alunos[nota] = aluno;
			}
			if(nota < min){
				min = nota;
			} 	
		}
		cout << "Instancia " << inst << endl;
		cout << alunos[min] << "\n" << endl;
		inst++;
		
		
	}
}
