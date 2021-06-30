/*******************************************************************************************
* ! Title : Insertion Sort
* ! File Name : Insertion_sort.c
* ! Description : This file is Implementation of Insertion Sort algorithm
********************************************************************************************/

#include <stdio.h>

/******************************************************************************/
/*Function: Insertion_sort         		                         			  */
/*I/P Parameters: int length                               		              */
/*Returns:it returns a sorted array                                           */
/*Desc:This Function applies the Insertion Sort  Algorithm  		          */
/******************************************************************************/
void Insertion_sort (int length);
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
  Insertion_sort(length); //selection sort calling
  printf ("\nSorted Array:- ");
  for (int i = 0 ; i < length ; i++)
    {
      printf ("%d ",array[i]);
    }

}

void Insertion_sort (int length)
{
    int number=0; //variable to hold number to be sorted
    int counter1, counter2; //counters for the loops
    for (int counter1=1; counter1<length; counter1++) //first loop for the Algorithm 
    {
        number = array[counter1]; //number to be sorted
        counter2 = counter1 - 1; //index for the number before the number to be sorted
        for(;(counter2 >= 0 && array[counter2]>number);counter2--) //loop to set the number in its right place compared to numbers before it
        {
            array[counter2+1]=array[counter2]; //change number locations to be Forwarded one location
        }
        array[counter2+1]=number; //set the number in its right Position 
    }
}

void swap(int *first, int *second)
{
    int temp = *first; //set the temp with first location value
    *first = *second;  //set the first with temp location value
    *second = temp;    //set the second with temp location value
}