/*******************************************************************************************
* ! Title : Ternary Search
* ! File Name : Linear_Search.c
* ! Description : This file is Implementation of Ternary search algorithm
********************************************************************************************/

#include <stdio.h>

/******************************************************************************/
/*Function: ternary_search       		                         		              
/*I/P Parameters: int array[], int length, int number			                    
/*Returns:it returns index of the number if found or -1 if it is not found    
/*Desc:This Function applies the Ternary search Algorithm  		                
/******************************************************************************/
int ternary_search(int length, int number);
/******************************************************************************/
/*Function: simple_sort         		                         			            
/*I/P Parameters: int array[], int length               		                  
/*Returns:it returns a sorted array                                           
/*Desc:This Function applies the selection Sort  Algorithm  		              
/******************************************************************************/
void simple_sort (int length);
/******************************************************************************/
/*Function: swap                		                         			            
/*I/P Parameters: int *first, int *second           			                    
/*Returns:it returns index of the number if found or -1 if it is not found    
/*Desc:This Function applies the Linear search Algorithm  		                
/******************************************************************************/
void swap(int *first, int *second);
int array[20]={0,5,6,4,3,18,9,8,5,2,10,12,7,15,17,20,25,29,35,45};  //Array of integers to be used in search

int main ()  // main Function
{
  int length = sizeof(array) / sizeof(array[0]);  //Get the length of the Array
  int number = 7;  //Number to be searched for
  int result = ternary_search(length,number);  //Function call to search for the number and get the result back
  if (result == -1) //check if the number not found
  {
    printf("Number not Found.\n"); //print number not found  
  }
  else
  {
      printf ("\nSorted Array:- ");
      for (int i = 0 ; i < length ; i++)
      {
          printf ("%d ",array[i]);
      }
      //print number location in the array
      printf("\nNumber %d is Found at location number %d after the array is sorted.",number,(result + 1));
  }
}


int ternary_search(int length, int number)
{ 
 simple_sort(length);   
 int found=-1; //variable to be returned to caller 
 int start=0;  //variable to save start index
 int end=length-1; //variable to save end index
 int mid1; //variable to save mid1 index
 int mid2; //variable to save mid2 index
 while (start <= end) //loop for applying the Algorithm 
 {
     int mid1 = (end-start)/3 + start; //set mid 1 index
     int mid2 = 2*(end-start)/3 + start; //set mid 2 index
     if (number==array[mid1]) //check if the required number at the mid 1  
     {
       found = mid1; // return the index
       break; //break from the loop
     }
     else if (number==array[mid2]) //check if the required number at the mid 2
     {
       found = mid2; // return the index 
       break; //break from the loop
     }
       else if (number < array[mid1]) //check if the number in the first Segment 
     {
         end=mid1-1; //set the end to end of Segment 1
     }
       else if (number < array[mid2]) //check if the number in the second Segment 
     {
         start=mid1+1; //set the start to start of Segment 2
         end=mid2-1; //set the end to end of Segment 2
     }
     else //number in the third Segment 
     {
         start=mid2+1; //set the start to start of Segment 3
     }
 }
 return found; //return the result
}

void simple_sort (int length)
{
    int minimum_index=0; //decleration of minimum index 
    for (int i=0; i<length-1; i++)
    {
        minimum_index=i; // set minimum index to the loop counter
        for (int c = i+1 ; c < length ; c++) // loop to found the minimum index
        {
            if (array[c] < array[minimum_index]) // check if any index ahead the i is less than c
            {
                minimum_index=c;
            }
        }
        swap(&array[minimum_index],&array[i]); //swap the two numbers
    }
}

void swap(int *first, int *second)
{
    int temp = *first; //set the temp with first location value
    *first = *second;  //set the first with temp location value
    *second = temp;    //set the second with temp location value
}
