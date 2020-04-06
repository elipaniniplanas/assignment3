#include <iostream> // I/O library.
using namespace std;

int main(){
    
    int SIZE = 10000;
    int *A1 = new int[SIZE];
    int *A2 = new int[SIZE];
    int *A3 = new int[SIZE];

    for(int i = 0 ; i < SIZE ; i++ ){ 
         A1[i] = i ;
         swap(A1[i], A1[rand() % (i+1)]);
         A2[i] = i ;
         swap(A2[i], A2[rand() % (i+1)]);
         A3[i] = i ;
         swap(A3[i], A3[rand() % (i+1)]);
    }
    for(int i=0; i<40; i++)        // print the first 40 randomly sorted numbers
        std::cout << A1[i] << std::endl;
    cout << endl << endl << endl;
    for(int i=0; i<40; i++)        // print the first 40 randomly sorted numbers
        std::cout << A2[i] << std::endl;
    cout << endl << endl << endl;
    for(int i=0; i<40; i++)        // print the first 40 randomly sorted numbers
        std::cout << A3[i] << std::endl;
    cout << endl << endl << endl;
    int highest = A1[0], lowest = A1[0];
    for(int i = 0; i < 40; i++){
        if()
    } 

}