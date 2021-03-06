// Simple Insertion Sort and Quicksort implementations
// for sorting Sorts arrays of ints.

// This quicksort uses A[hi] as the pivot
void QuickSortHi(int A[], int lo, int hi ){ 
   // Sorts A[lo] to A[hi].
   int temp ; // auxilliary variable used for performing swaps.
   if( lo < hi ){
      // Choose a pivot.
      // This is an easy, but poor, choice.
      int pivotIndex = hi ;

      // swap the pivot into A[hi] 
      temp = A[pivotIndex]; A[pivotIndex] = A[hi]; A[hi] = temp ;

      // Partition based on the pivot.
      int pivot = A[hi];
      int i = lo ; // i indexes the next place to put a newly found small value.
      for( int j = lo; j < hi; j++ ){
         // j indexes the next element to inspect.
         if( A[j] < pivot ){
            // swap A[i] and A[j], and increment i.
            temp = A[i]; A[i] = A[j]; A[j] = temp;
            i++; 
         }
      }
      // swap A[hi] and A[i], to put the pivot in place.
      temp = A[hi]; A[hi] = A[i]; A[i] = temp;

      // Recursively sort the two parts. 
      QuickSortHi(A, lo, i-1 );
      QuickSortHi(A, i+1, hi );
   }
}

// This quicksort uses the median of the lo, hi, and middle element as the pivot
void QuickSortMed(int A[], int lo, int hi ){ 
   // Sorts A[lo] to A[hi].
   int temp ; // auxilliary variable used for performing swaps.
   if( lo < hi ){
      // Choose a pivot.
      // This gets the median of the lo, middle, and hi
      int mid = (lo + hi)/2;
      if (A[mid] < A[lo]){
         temp = A[lo]; A[lo] = A[mid]; A[mid] = temp;
      }
      if(A[hi] < A[lo]){
         temp = A[lo]; A[lo] = A[hi]; A[hi] = temp;
      }
      if(A[mid] < A[hi]){
         temp = A[mid]; A[mid] = A[hi]; A[hi] = temp;
      }

      // Partition based on the pivot.
      int pivot = A[hi];
      int i = lo ; // i indexes the next place to put a newly found small value.
      for( int j = lo; j < hi; j++ ){
         // j indexes the next element to inspect.
         if( A[j] < pivot ){
            // swap A[i] and A[j], and increment i.
            temp = A[i]; A[i] = A[j]; A[j] = temp;
            i++; 
         }
      }
      // swap A[hi] and A[i], to put the pivot in place.
      temp = A[hi]; A[hi] = A[i]; A[i] = temp;

      // Recursively sort the two parts. 
      QuickSortMed(A, lo, i-1 );
      QuickSortMed(A, i+1, hi );
   }
}