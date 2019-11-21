/* Author: Giovanni Pinna
   Type: esercizio_03.5
   Object: Read the LittleWomen.txt and then print all the read words (without repetitions) followed by the number of repetitions of that word.
           The order in which the words are printed is not relevant. with unordered_map
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <chrono>
#include<vector>
 
using namespace std;

string pulisci (string p){
	vector <string> punteggiatura = {".", ",", ";","!", "?", ":"};
	for (int i = 0; i<4;i++){
		if (p.find(punteggiatura[i])<20)
	p.erase(p.find(punteggiatura[i]));
	}
	return p;
} 
 
int main()
{
  string parola;
  unordered_map<string, int> parole;
  auto t0 = std::chrono::high_resolution_clock::now();

 fstream file("LittleWomen.txt", ios::in);
 while(file >> parola)
    parole[pulisci(parola)]++;
 file.close();

  unordered_map<string, int>::iterator prossparola;
  for(prossparola=parole.begin(); prossparola!=parole.end(); prossparola++)
    cout << (*prossparola).first << " => " << (*prossparola).second << endl;
auto t1 = std::chrono::high_resolution_clock::now();
    
auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;

  return 0;
}
