/*******************************************************************************************
* ! Title : Selection Sort
* ! File Name : Selection_Sort.c
* ! Description : This file is Implementation of Binary search algorithm
********************************************************************************************/

#include <stdio.h>

/******************************************************************************/
/*Function: simple_sort         		                         			            
/*I/P Parameters: int length                               		                
/*Returns:it returns a sorted array                                           
/*Desc:This Function applies the selection Sort  Algorithm  		              
/******************************************************************************/
void selection_sort (int length);
/******************************************************************************/
/*Function: swap                		                         			            
/*I/P Parameters: int *first, int *second           			                    
/*Returns:it returns index of the number if found or -1 if it is not found    
/*Desc:This Function applies the Linear search Algorithm  		                
/******************************************************************************/
void swap(int *first, int *second);


int array[20]={0,5,6,4,3,6,9,8,5,6,10,12,7,15,17,20,25,29,35,45};  //Array of integers to be used in search

int main ()  // main Function
{
  int length = sizeof(array) / sizeof(array[0]);  //Get the length of the Array
  selection_sort(length); //selection sort calling
  printf ("\nSorted Array:- ");
  for (int i = 0 ; i < length ; i++)
    {
      printf ("%d ",array[i]);
    }

}


void selection_sort (int length)
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
