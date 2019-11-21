
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string pulisci (string p){
	vector <string> punteggiatura = {".", ",", ";","!", "?", ":"};
//	string punteggiatura [5] = (".", ",", ";","!", "?", ":");
	int posizione=0;
	for (int i = 0; i<4;i++){
		if (p.find(punteggiatura[i])<20)
	p.erase(p.find(punteggiatura[i]));
	//	cout<< p.find(punteggiatura[i])<<endl;
	}
//		cout<<punteggiatura<<endl;
//	if (posizione ==0) return p;		
//	p.erase(p.find(punteggiatura[i]));

	return p;
	
} 

int main (){
	
	string parola = "ciao";
	cout<<pulisci(parola);
	
}
