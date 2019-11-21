/* Author: Giovanni Pinna
   Type: esercizio_03.5
   Object: Read the LittleWomen.txt and then print all the read words (without repetitions) followed by the number of repetitions of that word.
           The order in which the words are printed is not relevant. 	with map
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <chrono>
#include <vector>
 
using namespace std;
 
string pulisci (string p){											//function for get out the punteggiatura
	vector <string> punteggiatura = {".", ",", ";","!", "?", ":"};
	for (int i = 0; i<4;i++){
		if (p.find(punteggiatura[i])<20)
			p.erase(p.find(punteggiatura[i]));
	}
	return p;														//retur a clean word
} 
 
 
int main(){
string parola;																//use for put a only single word
map<string, int> parole;													//map of the word
auto t0 = std::chrono::high_resolution_clock::now();						//start to take the time

  fstream file("LittleWomen.txt", ios::in);									//pointer to the file that has name LittleWomen.txt
  while(file >> parola)
    parole[pulisci (parola)]++;

    std::cout<<parola;
  file.close();																//close file

  map<string, int>::iterator prossparola;
  for(prossparola=parole.begin(); prossparola!=parole.end(); prossparola++) //order the word
    cout << (*prossparola).first << " => " << (*prossparola).second << endl;//print the word and how many times it appearances
    
auto t1 = std::chrono::high_resolution_clock::now();						//stop to take the time
auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);//calculate the elapse time
std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;

  return 0;
}
