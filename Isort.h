// Simple Insertion Sort and Quicksort implementations
// for sorting Sorts arrays of ints.

void IntroSort(int A[], int lo, int hi ){
    // Sorts A[lo] to A[hi].
   int temp ; // auxilliary variable used for performing swaps.
   if( lo < hi ){
      if(hi-lo < 9)
      {
         InsertionSort(A, lo, hi);
      }
      else{
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
         IntroSort(A, lo, i-1 );
         IntroSort(A, i+1, hi );
      }
   }
     
}

// This quicksort uses the median of the lo, hi, and middle element as the pivot
void QuickSort(int A[], int lo, int hi ){ 
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
      QuickSort(A, lo, i-1 );
      QuickSort(A, i+1, hi );
   }
    
}

void InsertionSort(int A[], int lo, int hi ){
   // Sorts A[lo] to A[hi].
   for( int i = lo+1 ; i <= hi ; i++ ){
        int pivot = A[i] ;
        int j = i-1 ;
        while( j >= lo && A[j] > pivot ){
           // shift A[j] to the right.
           A[j+1]=A[j];
           j = j-1 ;
        }
        A[j+1]=pivot;
   }
}

// This quicksort uses A[hi] as the pivot
void QuickSort(int A[], int lo, int hi ){ 
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
      QuickSort(A, lo, i-1 );
      QuickSort(A, i+1, hi );
   }
}

// This quicksort uses the median of the lo, hi, and middle element as the pivot
void QuickSort(int A[], int lo, int hi ){ 
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
      QuickSort(A, lo, i-1 );
      QuickSort(A, i+1, hi );
   }
}