/* Author: Giovanni Pinna
   Type: esercizio_02.2
   Object: Find the first 100 prime numbers
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include<iostream>

int* primis{new int[0]};  									// allocated on the HEAP, or free-store

bool primo (int numero){									//verify if the number is a multiple of a previous number (we use the rest)
															//if is not return that the number is prime else return 0 
	for (int i =2; i<numero; i++)
		if (!(numero%i)) 
			return false;
	return true;
}

int* salva (int numero, int lunghezza){ 					//save in the array primis all the nuber that are prime.
															//Every time create primis to the right size
	
	int* copiaprim{new int[lunghezza]};						//allocate a temporary array that is used to take at the moment the number inside primis
	if (lunghezza > 0){ 
		for (std::size_t i{0}; i<lunghezza;i++)
			copiaprim[i] = primis[i];						//save the value of primis 
		delete [] primis;									//delete primis
		int* primis{new int[lunghezza]};  					// allocated on the HEAP, or free-store. Create primis of the rith size
		for (std::size_t i{0}; i<lunghezza;i++)
			primis[i] = copiaprim[i];						//put the old value of primis
	}
	primis[lunghezza] = numero;								//put in primis the new value
	delete[] copiaprim;										//delite the temporary array copiaprim
	return &primis[0];										//retrurn the the adress of the first element of the new primis
}

int main(){
	std::cout<< "trova tutti i numeri primi fino a 100"<<std::endl;
	int count = 0;
	int* p;
	for (int i=1; i<100; i++){
		if (primo(i)){
			count ++;
			p = salva(i,count);
		}
	}
	for (int k=1; k<count+1; k++)
		std::cout<< p[k]<< " " ;
}
