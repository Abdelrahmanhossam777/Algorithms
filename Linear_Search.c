/*******************************************************************************************
* ! Title : Linear Search
* ! File Name : Linear_Search.c
* ! Description : This file is Implementation of linear search algorithm
********************************************************************************************/

#include <stdio.h>

/******************************************************************************/
/*Function: linear_search       		                         		          	  */
/*I/P Parameters: int array[], int length, int number			                    */
/*Returns:it returns index of the number if found or -1 if it is not found    */
/*Desc:This Function applies the Linear search Algorithm  		                */
/******************************************************************************/
int linear_search(int array[], int length, int number);

int main ()  // main Function
{
  int array[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};  //Array of integers to be used in search
  int length = sizeof(array) / sizeof(array[0]);  //Get the length of the Array
  int number = 7;  //Number to be searched for
  int result = linear_search(array,length,number);  //Function call to search for the number and get the result back
  if (result == -1) //check if the number not found
  {
    printf("Number not Found.\n"); //print number not found  
  }
  else
  {
      printf("Number %d is Found at location number %d.\n",number,(result + 1)); //print number location in the array
  }
}


int linear_search(int array[], int length, int number)
{ 
 int found=-1; //variable to be returned to caller 
 for (int i=0; i<length; i++) //loop to search for the number
 {
    if (number ==array[i]) //check if the number is found at index number i
     {
      found=i; // if found, found variable will be changed to the index of the number
      break;   // break from the loop after the number is found
     }
 }
 return found; //return search result
}