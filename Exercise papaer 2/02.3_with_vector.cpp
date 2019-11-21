/* Author: Giovanni Pinna
   Type: esercizio_02.3
   Object:Implement the Sieve of Eratosthenes algorithm and use the vector.
          Write a code that prints on screen the first prime numbers up to N included, where N is read from stdin. 
		  The first prime number that should be printed is 2.
    Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include<iostream>
#include<cmath>
#include<vector>

int massimo_div (int numins){										//make the square root for locate the maximum divisor
	int maxdiv = floor(sqrt(numins));								//floor is a function for approsimate the number
	return maxdiv;
}

void setaccio(int mdiv, int nins){
	std::vector<int> primi{2};										//inizialize the vector, with inside the number 2. We know that the algorithm start from 2
	
	for (int i = 3; i<nins;i++){									//repeat the routine for all the number 
		int count = 0;
		for (int j=0; j<primi.size();j++){
			if(!(i%primi[j])){										//I divide the number I'm looking at for all the prime numbers I found before it.
																	//If the rest at least once it is different from 0 increment the variable count.
				count ++;
			}
		}
		if (count == 0)												//if count is 0 I mean that I didn't find a divider. So the analyzed number is prime.
		
		primi.push_back(i);											//the number is prime, I push it in the vector
	}
	
	for (int i = 0; i<primi.size();i++)								//print the vector. The vector contain only the number that are prime.
		std::cout<<primi[i]<<" ";

}

int main(){
	int N ;															//invalid input if 0 or 1 just from 2 onwards
	std::cout<< "enter up to what number you want to find the prime numbers"<<std::endl;
	std::cin>> N;
	while((N==0)||(N==1)){											//the Eratosthenes algorithm start to the nuber 2. I put that 0 and 1 are invalid input.
	std::cout<< "previous invalid value, enter a value that is not 0 or 1"<<std::endl;
	std::cin>> N;
	}
	int md = massimo_div(N);
	setaccio(md, N);
}
