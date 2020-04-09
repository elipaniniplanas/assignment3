#include <iostream> // I/O library.
#include <algorithm> // Includes sort()
#include <ctime> // access to the system clock
#include <time.h> // access to "wall clock"
#include "Isort.h" // our quicksort (and insertion sort)
using namespace std;

double elapsed_time( clock_t start, clock_t finish){
   // returns elapsed time in milliseconds
   return (finish - start)/(double)(CLOCKS_PER_SEC/1000);
}

void printArray( char s[], int A[], int lo, int hi ){
  // call like this: printArray( "A1", A1, 0, SIZE-1 );
  // useful for debugging
  cout << s << " [ " ;
  for( int i = lo ; i < hi ; i++ ){
    cout << A[i] << ", " ;
  }
  cout << A[hi] << " ]" ;
  cout << endl;
}

int main (int argc, char * const argv[]) {

   int SIZE = 10000; // size of array to sort.
   int TIMES = 10 ; // number of times to run - mean is reported.

   srand( time(NULL) ); // seed the random number generator.

   clock_t start, finish ;// used to time function calls.

   double insertsort_time1 = 0 ;
   double quicksort_time1 = 0 ;
   double introsort_time1 = 0 ;
   double insertsort_time2 = 0 ;
   double quicksort_time2 = 0 ;
   double introsort_time2 = 0 ;

   int *A1 = new int[SIZE];
   int *A2 = new int[SIZE];
   int *A3 = new int[SIZE];
   int *A4 = new int[SIZE];
   int *A5 = new int[SIZE];
   int *A6 = new int[SIZE];

   for( int t = 0 ; t < TIMES ; t++ ){

      for(int i = 0 ; i < SIZE ; i++ ){ 
         int x = SIZE - i ; // reverse-ordered 
         // int x = ( x == 2*(x/2) ?  SIZE - i : i );
         // int x = rand() % SIZE*10;
         A1[i] = x ;
         A2[i] = x ;
         A3[i] = x ;
         A4[i] = i ;
         swap(A4[i], A4[rand() % (i+1)]);//shuffle array
      }
      A5 = A4;
      A6 = A4;

      start = clock();
      InsertionSort(A1,0,SIZE-1);
      finish = clock();
      insertsort_time1 += elapsed_time(start,finish);

      start = clock();
      QuickSort(A2,0,SIZE-1);
      finish = clock();
      quicksort_time1 += elapsed_time(start,finish);

      start = clock();
      IntroSort(A3,0,SIZE-1);
      finish = clock();
      introsort_time1 += elapsed_time(start,finish);

      start = clock();
      InsertionSort(A4,0,SIZE-1);
      finish = clock();
      insertsort_time2 += elapsed_time(start,finish);

      start = clock();
      QuickSort(A5,0,SIZE-1);
      finish = clock();
      quicksort_time2 += elapsed_time(start,finish);

      start = clock();
      IntroSort(A6,0,SIZE-1);
      finish = clock();
      introsort_time2 += elapsed_time(start,finish);

    }

   //Experiment with reverse ordered array
   cout << "Insertsort: " << insertsort_time1 / TIMES << endl ;  
   cout << "Quicksort: " << quicksort_time1 / TIMES << endl ;
   cout << "Introsort: " << introsort_time1 / TIMES << endl ;

   //Experiment with randomly ordered array that contains without repeating numbers
   cout << "Insertsort: " << insertsort_time2 / TIMES << endl ;  
   cout << "Quicksort: " << quicksort_time2 / TIMES << endl ;
   cout << "Introsort: " << introsort_time2 / TIMES << endl ;

   return 0;
}
