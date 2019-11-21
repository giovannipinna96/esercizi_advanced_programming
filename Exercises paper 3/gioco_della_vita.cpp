/* Author: Giovanni Pinna
   Type: esercizio_03.6
   Object: Game of life
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include<iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <chrono>
#include <thread>

const int N = 20;															//rows of our space
const int M = 50;															//collums of our space
int griglia [N][M];
int griglianuova[N][M];

void Crea () {																//create random the life in our space

	for(int i =0; i<N; i ++)
		for(int j = 0; j<M;j++)
			griglia[i][j] = floor(rand()%2);
			
	for(int i =0; i<N; i ++){												//print the start space with the life
		for(int j = 0; j<M;j++)
			std::cout<<" "<<griglia[i][j];
		std::cout<<std::endl;
	}
	std::cout<<std::endl<<std::endl;

}

int Controlla(int r, int c){												//chek the close boxes for see the other organisms
	int somma = 0;
	for (int i =0; i<3 ; i++){
		for (int j = 0; j<3; j++){
			if ((r+i-1>=0)&&(c+j-1 >=0)&&(r+i-1<N)&&(c+j-1 <M))				//check the box only inside the space
				somma = somma + griglia[r+i-1][c+j-1];	
		}
		
	}
																			//rules about the dead, life and born
	if (griglia[r][c] == 0){
		if (somma ==3)
			return 1;
		else return 0;
	}
	if(griglia[r][c] == 1){
		somma = somma -1;
		if ((somma ==3)||(somma==2))
			return 1;
		else return 0;
	}
}


int main(){
 Crea ();																//create the firts time the life
 while(1){																	//Infinity loop
	for(int i =0; i<N; i ++)
		for(int j = 0; j<M;j++)
			griglianuova [i][j] = Controlla(i,j);
			
	for(int i =0; i<N; i ++)
		for(int j = 0; j<M;j++)
			griglia [i][j] = griglianuova [i][j];
			
	for(int i =0; i<N; i ++){
		for(int j = 0; j<M;j++){
			if (griglia[i][j]==0) std::cout<<".";							//the dot are dead 
			else std::cout<<"#";											// the # are in life
		}
		std::cout<<std::endl;
	}
	std::this_thread::sleep_for (std::chrono::milliseconds(100));			//wait for 100 milliseconds
	for (int i= 0; i<100;i++)												//print 100 spaces
		std::cout<<std::endl;
 }
}


