/* Author: Giovanni Pinna
   Type: esercizio_02.2
   Object: Find the first 100 prime numbers and use the vector
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include<iostream>
#include<vector>

bool primo (int numero){									//verify if the number is a multiple of a previous number (we use the rest)
															//if is not return that the number is prime else return 0 
	for (int i =2; i<numero; i++)
		if (!(numero%i)) 
			return false;
	return true;
}

int main(){
	std::vector<int> primi;									//inizialize the vector

	for (int i=1; i<100; i++){
		if (primo(i))										//enter if the number is primo 
			primi.push_back(i);								//push the primo number in the back of the vector
	}

	std::cout<<"i numeri primi fino a 100 sono: " <<std::endl;	
	for (int i = 0 ; i<primi.size();i++)
		std::cout<< primi[i]<< " ";
		
	std::cout<<std::endl;
}
