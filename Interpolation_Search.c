/*******************************************************************************************
* ! Title : Interpolation Search
* ! File Name : Interpolation_Search.c
* ! Description : This file is Implementation of Interpolation search algorithm
********************************************************************************************/

#include <stdio.h>

/*****************************************************************************************/
/*Function: interpolation_Search       		                         			         */
/*I/P Parameters:  int length, int number           			                         */
/*Returns:it returns index of the number if found or -1 if it is not found               */
/*Desc:This Function applies the Interpolation search Algorithm                          */
/*****************************************************************************************/
int interpolation_Search( int length, int number);
/******************************************************************************/
/*Function: simple_sort         		                         			  */
/*I/P Parameters: int array[], int length               		              */
/*Returns:it returns a sorted array                                           */
/*Desc:This Function applies the selection Sort  Algorithm  		          */
/******************************************************************************/
void simple_sort (int length);
/******************************************************************************/
/*Function: swap                		                         			  */
/*I/P Parameters: int *first, int *second           			              */
/*Returns:it returns index of the number if found or -1 if it is not found    */
/*Desc:This Function applies the Linear search Algorithm  		              */
/******************************************************************************/
void swap(int *first, int *second);


int array[20]={0,5,6,4,3,18,9,8,5,2,10,12,7,15,17,20,25,29,35,45};  //Array of integers to be used in search

int main ()  // main Function
{
  int length = sizeof(array) / sizeof(array[0]);  //Get the length of the Array
  int number = 45;  //Number to be searched for
  int result = interpolation_Search(length,number);  //Function call to search for the number and get the result back
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

int interpolation_Search( int length, int number)
{
    //Interpolation sort as Binary search requires sorting
    simple_sort(length);
    int start = 0; //start index of the array
    int end = (length - 1); // end index of the array
    int position=0; // decleration of position will follow the formula
    int result =-1; // set result as not found
 
    while (start <= end && number >= array[start] && number <= array[end]) //while loop for search
    {
        if (start == end) //check if start equals the end
        {
            if (array[start] == number) //check if the required number at the last index
            {
              result = start; //set result as start
              break; //break from the loop
            }
            else
            {
              break; //break from the loop if start at the end
            }
        }
        int position = start + (((double)(end - start) /
            (array[end] - array[start])) * (number - array[start])); //Applying the required formula for search
        if (array[position] == number) //check if this position is the required number
         {
             result= position; //set result index as the current position
             break; //break from the loop
         }   
        if (array[position] < number) //check if the number is less than the current index
        {
          start = position + 1; //increse the start to the position + 1 then we will be back for the formula
        }
        else // the number is bigger than the current index
        {
          end = position - 1; //decrease the end to the position - 1 then we will be back for the formula
        }
    }
    return result; //return the found result
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