#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int tab1[2], tab2[21];
	string line;
	int n1, n2 = 0;
	
	getline(cin, line);
	stringstream ss1(line);
	while(ss1 >> tab1[n1]) n1++;
	
	getline(cin, line);
	stringstream ss2(line);
	while(ss2 >> tab2[n2]) n2++;
	
	cout << "tab1: ";
    for (int i = 0; i < n1; i++) cout << tab1[i] << " ";
    cout << "\n";

    cout << "tab2: ";
    for (int i = 0; i < n2; i++) cout << tab2[i] << " ";
    cout << "\n";
	
	int wyn = 0;
	int tab_wyn[tab1[1]][tab1[0]];
	
	//Glowna petla - sprawdzamy rozne rozwiazania
	
	for (int i = 1; i <= tab1[0]; i++){
		for (j = i; j <= tab1[0]; j++)  //dla kazdego rozwiazania zaczynamy sprawdzanie od iteratora 'i'
			// teraz sprawdzamy 
		}
	}
	
	return 0;
	
	}
