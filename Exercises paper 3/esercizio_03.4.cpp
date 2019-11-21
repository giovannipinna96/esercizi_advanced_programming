/* Author: Giovanni Pinna
   Type: esercizio_03.4
   Object: Store the numbers contained in file temperatures.txt into a std::vector<double> and compute:the mean and the median.
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include <iostream>
#include <fstream>												//Library NEEDED for file I / O operations
#include <string>
#include<vector>
#include <algorithm>

using namespace std;
int main(){
	vector <double> v;											//contains the number inside the temperatures file
    string s;
    fstream miofile;											//pointer to the file
    miofile.open("temperatures.txt", ios::in);					//istruction for open the file that has the name temeperature.txt.
																//The file MUST be in the same directory of the program otherwise we have to specify
																//the directory where is the file.
																
    while(!(miofile.eof())){									//read unti the EOF (end of file)
    getline(miofile, s);										//READING in the file associated with the object and put the result inside the string s
    v.push_back(stod(s));										//trasforme s in a double and put it in the v vector
}
    miofile.close();											//close the file
    double somma=0;
    for (int i = 0; i<v.size();i++)								//sum all the elements of the vector
    	somma = somma + v[i];
    double media = somma/ v.size();								//divide the sum by the size of the vector (average)
    std::cout<<"the average is " << media << std::endl;
    	
	std :: sort (v.begin (), v.end ());							//order the elements of the vector
	double mediana = v.at(v.size()/2);							//find the central element
	std::cout<<"the median is "<< mediana<< std::endl;			//print the central element of the order vector (median)
}
