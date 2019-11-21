/* Author: Giovanni Pinna
   Type: esercizio_03.2bis
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

 
const int N=2, M=3;
 

void leggiMatrice(int matrice[N][M]){
     cout << "Inserisci la matrice " << N << " x " << M << ": " <<endl;
     for (int i=0; i<N; i++)
         for(int j=0; j<M; j++)
             cin >> matrice[i][j];
     return;
}
void visualizzaMatrice(int matrice[N][M]){
     cout << "La matrice inserita e': " <<endl;
     for (int i=0; i<N; i++){
         for(int j=0; j<M; j++){
             cout << matrice[i][j] << "\t";
         }
         cout <<endl;
     }
     return;
}
void Trasposta(int m[N][M], int t[M][N]){
     cout << "La matrice trasposta e': " <<endl;
     //determina la matrice trasposta
     for (int i=0; i<N; i++){
         for(int j=0; j<M; j++){
            swap(t[j][i],m[i][j]);
         }
     }

     //visualizza la matrice trasposta
     for(int i=0; i<M; i++){
         for(int j=0; j<N; j++){
             cout << t[i][j] << "\t";
         }
         cout <<endl;
     }
     return;
}
 

 
int main(){
    int matrice[N][M], trasposta[M][N], prodotto[N][N];
    leggiMatrice(matrice);
    visualizzaMatrice(matrice);
	Trasposta(matrice,trasposta);
}
 
