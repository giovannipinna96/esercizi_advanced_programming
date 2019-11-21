/* Author: Giovanni Pinna
   Type: esercizio_02.1
   Object: Write a program that reads the length of an array from stdin and then stores the numbers given by stdin in it.
           The program should then print the numbers in reverse order. Remember to free up the memory used correctly.
           You should divide the problem into two parts:
           Write a model function that allocates an array of a certain size on the heap,
           initializes its elements and returns the pointer to the first element.
           Write a model function that prints the elements of an array in reverse order.
           Try whole and double numbers.
           Use std :: size_t.
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include <string>
#include<iostream>


int get_int (){														//this function is used for check if the user had insert an integer
																	//or another type of value. If the user has not insert a integer the input is discard

	int da_verificare{};											//variable that is used for understand if the user insert a integer or not

	while (!(std::cin>> da_verificare)){							//if the "da_verificare" is an integer return the number else we ignore the input
																	//and ask for an right input. Stay inside the loop until a correct input is entered
		std::cin.clear();
		std::cin.ignore(100,'\n');  								//ignore the first 100 caracter or ignore until the enter
		std:: cout << "the value that you had add is NOT valid. The value must be a integer" << std::endl ;
	}
	std:: cout << "The value that you add is a integer" << std::endl ;
	return da_verificare;
}

int* memorizza (int* punt, int lunghezza){							//this function is used memorize the values that the user add.
	int numero {};
	std::cout<< "Add the "<< lunghezza << " point that compose your array"<<std::endl;
	for (std::size_t i{0}; i<lunghezza; ++i){
		numero = get_int();											//call get_int for understand in the value is a correct one
		*(punt + i) = numero;										//if the value is correct save it in the array
	}
	return &punt[0];												//return to the main the adress of the first element of the array
																	//(that now have all the value that add the user)
}

void inverso (int* puntatore, int lunghezza){						//print in the reverse order the values of the array
		for (std::size_t i{0}; i<lunghezza; ++i){
			std::cout<< *(puntatore +lunghezza - i - 1)<< " " ;
		}
}

int main(){
	std::cout<< "insert the length of the array"<<std::endl;		//ask for the number of the elements of the array
	int quantita = get_int();										//call get_int ant put the result into quantita
	int* array{new int[quantita]};  								// allocated on the HEAP, or free-store
	int* p = memorizza(&array[0],quantita);							//call the "memorizza" function and pass to it the adress memory of the first element
																	//of the array and the length of the array

	inverso (p, quantita);											//call inverso ad pass to it the pointer to the array and the size of the array
	delete[] array;													//clear the memory that we had allocated
}
