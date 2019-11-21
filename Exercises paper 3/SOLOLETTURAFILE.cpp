///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////SOLO LETTURA DA FILE//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream> //Libreria NECESSARIA per le operazioni di I/O sui file
#include <string>
#include<vector>

using namespace std;
int main(){
	vector <double> v;
    string s;
    fstream miofile;
    miofile.open("temperatures.txt", ios::in);
    while(!(miofile.eof())){
    getline(miofile, s); 		//LETTURA nel file associato all'oggetto
    v.push_back(stod(s));
}
    miofile.close();
    for (int i = 0; i<v.size();i++)
    	std::cout<< v[i] <<" " ;
    return 0;
}
