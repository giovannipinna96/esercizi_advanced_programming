/* Author: Giovanni Pinna
   Type: esercizio_01.3
   Object: Write a code that reads a number with its proper unit of measure, and prints back that number according to the SI units.
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include <string>
#include<iostream>

int main(){
	std::cout<<"attention this program can perform the following conversions:\n inch, mile, foot to metri\n ounce e pound to kg\n all other conversions will not be allowed"<< std::endl;
	std:: string unita;										//unita is used for take from the stdin the SI unit of your value
	float valore;											//the valore variable is used for take the value from the stdin
	std::cin>>valore;										//read stdin
	std::cin>>unita;
	while ((unita != "inch")&&(unita != "mile")&&(unita != "foot")&&(unita != "ounce")&&(unita != "pound")){ //check if the SI unit is incorrect and is not approved 
																											 //to the program
		std::cin.clear();									//clear the stdin
		std::cin.ignore(1000, '\n');  						//ignore the caracter
		std::cout<<"input error"<<std::endl;
		std::cin>>valore;
		std::cin>>unita;
	}
	
	if (valore =>0){
															//if the input is correct find the right SI unit and do the conversion
		if (unita == "inch")									
			std::cout<<"the value in SI unit is " << valore*0.0254 <<  " m" << std::endl;//print the result of the conversion
		if (unita == "mile")
			std::cout<<"the value in SI unit is " << valore*1609.34 <<  " m" << std::endl;
		if (unita == "foot")
			std::cout<<"the value in SI unit is " << valore*0.3048 <<  " m" << std::endl;
		if (unita == "ounce")
			std::cout<<"the value in SI unit is " << valore*0.0283495 <<  " kg" << std::endl;
		if (unita == "pound")
			std::cout<<"the value in SI unit is " << valore*0.453592 <<  " kg" << std::endl;
	}
}
