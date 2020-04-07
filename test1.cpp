#include <iostream> // I/O library.
#include <algorithm> // Includes sort()
#include <ctime> // access to the system clock
#include <time.h> // access to "wall clock"
#include "Qsort.h" // our quicksort (and insertion sort)
using namespace std;

double elapsed_time( clock_t start, clock_t finish){
   // returns elapsed time in milliseconds
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
}

void printArray(int A[], int lo, int hi ){
  // call like this: printArray( "A1", A1, 0, SIZE-1 );
  // useful for debugging
  cout << " [ " ;
  for( int i = lo ; i < hi ; i++ ){
    cout << A[i] << ", " ;
  }
  cout << A[hi] << " ]" ;
  cout << endl;
}

int main (int argc, char * const argv[]) {

   int SIZE = 1000; // size of array to sort.
   int TIMES = 10 ; // number of times to run - mean is reported.

   srand( time(NULL) ); // seed the random number generator.

   clock_t start, finish ;// used to time function calls.

   double quicksorthi_time1 = 0 ;
   double quicksortmed_time1 = 0 ;
   double quicksorthi_time2 = 0 ;
   double quicksortmed_time2 = 0 ;

   int *A1 = new int[SIZE];
   int *A2 = new int[SIZE];
   int *A3 = new int[SIZE];
   int *A4 = new int[SIZE];

   for( int t = 0 ; t < TIMES ; t++ ){

      for(int i = 0 ; i < SIZE ; i++ ){ 
         int x = SIZE - i ; // reverse-ordered 
         A1[i] = x ;
         A2[i] = x ;
         A3[i] = i ;
         swap(A3[i], A3[rand() % (i+1)]);
      }
      A4 = A3;

      start = clock();
      QuickSortHi(A1,0,SIZE-1);
      finish = clock();
      quicksorthi_time1 += elapsed_time(start,finish);

      start = clock();
      QuickSortMed(A2,0,SIZE-1);
      finish = clock();
      quicksortmed_time1 += elapsed_time(start,finish);

      start = clock();
      QuickSortHi(A3,0,SIZE-1);
      finish = clock();
      quicksorthi_time2 += elapsed_time(start,finish);

      start = clock();
      QuickSortMed(A4,0,SIZE-1);
      finish = clock();
      quicksortmed_time2 += elapsed_time(start,finish);

    }

   //Experiment with reverse ordered array
   cout << "Quicksort with hi as the pivot point: " << quicksorthi_time1 / TIMES << endl ;  
   cout << "Quicksort with the median of three as the pivot point: " << quicksortmed_time1 / TIMES << endl ;

   //Experiment with randomly ordered array that contains without repeating numbers
   cout << "Quicksort with hi as the pivot point: " << quicksorthi_time2 / TIMES << endl ;  
   cout << "Quicksort with the median of three as the pivot point: " << quicksortmed_time2 / TIMES << endl ;

   return 0;
}
