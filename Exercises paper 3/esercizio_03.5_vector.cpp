/* Author: Giovanni Pinna
   Type: esercizio_03.5
   Object: Read the LittleWomen.txt and then print all the read words (without repetitions) followed by the number of repetitions of that word.
           The order in which the words are printed is not relevant. with vector
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
 
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
  vector<string> parole;
  vector<int> occorrenze;
auto t0 = std::chrono::high_resolution_clock::now();

  fstream file("LittleWomen.txt", ios::in);
  while(file >> parola)
    parole.push_back(pulisci(parola));
  file.close();
  
  
  	for (int i= 0; i<parole.size();i++){
		int count =0;
		for (int j = 0; j<parole.size();j++){
			if (j<i){													//compares the word an dcount it only if is a new word else skip the word
				if (parole[i]==parole[j])
					break;
			}
			else{
				if (parole[i]==parole[j])
					count++;			
			}
		}
		if (count != 0)
			std::cout<<" "<< parole[i] <<"  => " << count << std::endl;
	}
  
  
auto t1 = std::chrono::high_resolution_clock::now();   
auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;

  return 0;
}









