/* Author: Giovanni Pinna
   Type: esercizio_01.3
   Object: Write a simple text formatter that breaks the lines longer than a given number of characters. This formatter does not break words
   		   and leaves unmodified the lines shorter than the given threshold.
   	Compiler: gcc
   	Language:c++ 11
   Date:19/11/2019
   
*/

//ATTENCTION: if the word is longer than the maxsize the program cut the word and go in a new line.

#include <string>
#include<iostream>

int main(){
	const int maxsize = 20;									//max size tha we set
	std:: string line;
	std::getline(std::cin,line);							//take the line from the stdin
	std:: string riga [maxsize];							//buffer that we will use for set the max length of the line.
															//In this case after 20 caracters the program goes in a new line 
	int count = 0;
	int i = 0;
	if (line.length() > maxsize){							//if the lenght of the line is above 20 the program enter in the routine for break the line
															//and continue the print in a new line
		while (count < line.length()){	
			while (i<maxsize){
				riga[i] = line[i+ count];
				i++;
			}
			for(int q= 0; q<maxsize;q++){ 					//come back to the last space inside the 20 caracters 
				if (riga[i-q] == " ") {
					i = i-q;								//understand where is the last space befor the max size that we set for the line (20)
					q= 21;
				}
			}
			for (int k = 0; k<i; k++)						//print the line until the space that we identified before
		 		std::cout<<riga[k];
			std::cout<<std::endl;							//go in a new line
			count = count + i;
			i = 0;											//run again the routine until the end of the line
		}
	}
	else std::cout<<line;									//if the length of the line is less than 20 then print it immediately
}

