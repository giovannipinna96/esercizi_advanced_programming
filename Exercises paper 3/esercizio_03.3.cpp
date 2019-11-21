/* Author: Giovanni Pinna
   Type: esercizio_03.3
   Object: Read from stdin a sequence of words. Store each word in a std::vector<std::string>. Then, print the words without repetitions.
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include <iostream>
#include <string> 
#include<vector>


int main() {
    std::vector<std::string> parole;								//inizialize the vectorn that will contain all the word
    int numparole;													//contain the number of word that the user wants write
    std::string s;													//contain one word at a time, which is read form the stdin
    std::cout<<"how many words you want to enter"<<std::endl;
    std::cin>> numparole;
    
    for (int i=0;i<numparole;i++){									//read worf for word 
    	std::cout<<"enter word number "<< i <<std::endl;			//read a word
    	std::cin>> s;												//put the word inside the string variable "S"
    	parole.push_back(s);										//put the word insite the vector
	}
	
	for (int i= 0; i<parole.size();i++){							//check all possible combination of words and count how many are the same word
		int count =0;
		for (int j = 0; j<parole.size();j++){
			if (j<i){												//not the word if has already appeared
				if (parole[i]==parole[j])
					break;
			}
			else{
				if (parole[i]==parole[j])
					count++;			
			}
		}
		if (count != 0)
			std::cout<<"the word "<< parole[i] <<" appears " << count << std::endl;
	}
}
