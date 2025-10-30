#include <bits/stdc++.h>
using namespace std;

int main() {
    int tab1[3], tab2[250000], tab3[250000]; // tab3 z zapasem np. 100 elementów
    int n2 = 0; 
    int n3 = 0;                      // licznik faktycznie wczytanych liczb do tab3
    string line;
    int counter = 0;

    // --- Pierwsza linia: 3 liczby ---
    getline(cin, line);
    stringstream ss1(line);
    for (int i = 0; i < 3; i++) ss1 >> tab1[i];

    // --- Druga linia: nie wiadomo ile liczb ---
    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> tab2[n2]) n2++;

    // --- Trzecia linia: nie wiadomo ile liczb ---
    getline(cin, line);
    stringstream ss3(line);
    while (ss3 >> tab3[n3]) n3++;
    // program
    for (int i = 0; i < n2; i++){
		for (int j = 0; j < n3; j++){
			if (abs(tab2[i] - tab3[j]) <= tab1[2]){
				counter++;
				cout << "Dodaje " << tab2[i] << " i " << tab3[j] << "\n";				
			}
		}
	}
		
	cout << "\n" << counter << "\n";

    return 0;
}
