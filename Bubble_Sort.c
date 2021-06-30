/*******************************************************************************************
* ! Title : Bubble Sort
* ! File Name : Bubble_Sort.c
* ! Description : This file is Implementation of Bubble sort algorithm
********************************************************************************************/

#include <stdio.h>

/******************************************************************************/
/*Function: Bubble_sort         		                         			  */
/*I/P Parameters: int length                               		              */
/*Returns:it returns a sorted array                                           */
/*Desc:This Function applies the Bubble Sort  Algorithm  		              */
/******************************************************************************/
void Bubble_sort (int length);
/******************************************************************************/
/*Function: swap                		                         			  */
/*I/P Parameters: int *first, int *second           			              */
/*Returns:it returns index of the number if found or -1 if it is not found    */
/*Desc:This Function applies the Linear search Algorithm  		              */
/******************************************************************************/
void swap(int *first, int *second);


int array[20]={0,5,6,4,3,6,9,8,5,6,10,12,7,15,17,20,25,29,35,45};  //Array of integers to be used in search

int main ()  // main Function
{
  int length = sizeof(array) / sizeof(array[0]);  //Get the length of the Array
  Bubble_sort(length); //selection sort calling
  printf ("\nSorted Array:- ");
  for (int i = 0 ; i < length ; i++)
    {
      printf ("%d ",array[i]);
    }

}


void Bubble_sort (int length)
{ 
    for (int i=0; i<length-1; i++)
    {
        for (int c = 0 ; c < length-1-i ; c++) // loop to found the minimum index
        {
            if (array[c+1] < array[c]) // check if c+1 element is less than the element at c
            {
                swap(&array[c],&array[c+1]); //swap the two numbers
            }
        }
    }
}

void swap(int *first, int *second)
{
    int temp = *first; //set the temp with first location value
    *first = *second;  //set the first with temp location value
    *second = temp;    //set the second with temp location value
}