/* Author: Giovanni Pinna
   Type: esercizio_03.2
   Object: Write a function that computes the transpose of a matrix. The matrix is represented by a simple std::array<double,N>
           where N is the total size of the matrix (i.e., number of rows times number of columns).
		   The original array must be modified inside the function transpose.
   Compiler: gcc
   Language:c++ 11
   Date:19/11/2019
*/

#include<cmath>
#include<utility>
#include<iostream>
#include<sstream>

using namespace std;
 
void leggiMatrice(int* matrice,int N,int M){								//read the matrix from the stdin.
    cout << "insert the matrix " << N << " x " << M << ": " <<endl;
    for (int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> *(matrice+(M*i)+j);
    return;
}

void visualizzaMatrice(int* matrice,int N,int M){							//print the matrix that the user has insert
    cout << "The matrix that you add is: " <<endl;
    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << *(matrice+(M*i)+j) << "\t";
        }
        cout <<endl;														//at the end of the row go in a new line
    }
}

void traspost(int* m, int N, int M){										//make the transpose matrix with the swap function
    cout << "The transpose of the matrix is: " <<endl;
    for (int i=0; i<N; i++){
        for(int j=i; j<M; j++)
        	std::swap(*(m+ (M*i)+j), *(m+(M*j)+i )); 						//play with the pinters
    } 
    for (int i = 0; i<M; i++){												//print the transpose matrix
     	for (int j = 0; j<N; j++)
     		std::cout<<*(m+ (M*i)+j)<<" ";	
     	std::cout<<std::endl;
    }
}

int main(){	
	int N,M;																//N=row ; M=collumn
	std::cout<<"enter the number of rows in the matrix"<<std::endl;
	std::cin>>N;															//read the number of rows
	std::cout<<"enter the number of collumns in the matrix"<<std::endl;
	std::cin>>M;															//read the number of collums
    int matrice[N][M];														//create the matrix of the right size
    leggiMatrice(&matrice[0][0], N,M);										//call the function for populate the matrix
    visualizzaMatrice(&matrice[0][0], N,M);									//call the function for print the matrix
    traspost(&matrice[0][0], N, M);											//call the function for do the transpose of the matrix
}
 
