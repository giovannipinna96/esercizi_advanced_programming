/* Author: Giovanni Pinna
   Type: esercizio_02.3
   Object:Implement the Sieve of Eratosthenes algorithm.
          Write a code that prints on screen the first prime numbers up to N included, where N is read from stdin. 
		  The first prime number that should be printed is 2.
    Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include<iostream>
#include<cmath>

int massimo_div (int numins){										//make the square root for locate the maximum divisor
	int maxdiv = floor(sqrt(numins));								//floor is a function for approsimate the number
	return maxdiv;
}

void setaccio(int mdiv, int nins){									//in this function we use a array where there are all the number until
																	//the number that we insert. In the routine we put the number that has a divisor
																	//equal to zero.in this way the array has all prime nuber and the other are zero.
																	
	int* array{new int[nins-2]}; 									// allocated on the HEAP, or free-store
	for (int i= 2; i<nins+1; i++)
		array [i-2] = i;	
	for(int i = 0; i<mdiv; i++){
		int j= i+1;
		while(j<nins){
			if (array[i] != 0)										//if the value is not equal to zero
				if (!(array[j]%array[i]))							//divide all nuber and if there are some multiple put it on zero
					array[j] = 0;
			++j;		
		}
	}
	for (int k=0; k<nins; k++){ 									//in this for we print all the elements of the array that are not zero.
																	//This rule is right because we know for definition that 0 is not prime.
		if (array[k]!=0)
			std::cout<< array[k]<< " " ;
	}
	delete[] array;													//make free the memory
}

int main(){															//invalid input if 0 or 1 just from 2 onwards
	int N ;
	std::cout<< "enter up to what number you want to find the prime numbers"<<std::endl;
	std::cin>> N;
	while((N==0)||(N==1)){											//the Eratosthenes algorithm start to the nuber 2. I put that 0 and 1 are invalid input.
	std::cout<< "previous invalid value, enter a value that is not 0 or 1"<<std::endl;
	std::cin>> N;
	}
	int md = massimo_div(N);
	setaccio(md, N);
	}
