/* Author: Giovanni Pinna
   Type: esercizio_01.2
   Object: write a "get_int" function that reads from the stdin until a valid number is entered and
           write a "get_double" function that reads from the stdin until a valid number is entered.
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include <string>
#include<iostream>

void get_int (); 															// read from stdin until it comes inserted an integer
void get_double ();															// read from stdin until it comes inserted an double

void get_int (){
	int da_verificare{};
	while (!(std::cin>> da_verificare)){
		std::cin.clear();
		std::cin.ignore();  												//it only ignores the character that is not valid and takes the first valid
		std:: cout << "The value that you have added is NOT valid. Please, insert an integer or double value." << std::endl ;
	}
	std:: cout << "The value that you have added is valid and is an Integer" << std::endl ;
}

void get_double (){
	double da_verificare{};
	while (!(std::cin>> da_verificare)){
		std::cin.clear();
		std::cin.ignore(10000, '\n'); 										//ignore all 10000 characters after an invalid character 
																			//or ignore until the first newline
		std:: cout << "The value that you have added is NOT valid. Please, insert an integer or double value." << std::endl ;
	}
	std:: cout << "The value that you have added is valid and is an double." << std::endl ;
}

int main(){
	get_int();																//get_int is used for find a Integer
// get_double();															//get_double is used for find a double
}

