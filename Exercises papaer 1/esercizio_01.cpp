/* Author: Giovanni Pinna
   Type: esercizio_01
   Object: Write a simple version of the Unix program "uniq -c", which,
           when fed with a text, outputs the same text with consecutive identical
		   lines collapsed to one prepended with the number of repetitions.
   Compiler: gcc
   Language:c++ 11
	Date: 19/11/2019
*/

#include <string>
#include<iostream>

int main(){
	std:: string s1 = "\0";
	int count{};
	std:: string line;
	while(std::getline(std::cin,line)){						//read line from cin	
		if (s1 == line)										//compare the string
			count ++;			
		if (s1 != line){
			std:: cout << count << " " << s1 << std::endl;
			s1 = line;
			count = 0;
		}
	}
}
