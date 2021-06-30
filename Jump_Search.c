/*******************************************************************************************
* ! Title : Binary Search
* ! File Name : Binary_Search.c
* ! Description : This file is Implementation of Binary search algorithm
********************************************************************************************/

#include <stdio.h>
#include <math.h>

/*****************************************************************************************/
/*Function: Jump_search       		                         			                 */
/*I/P Parameters:  int length, int number			                                     */
/*Returns:it returns index of the number if found or -1 if it is not found               */
/*Desc:This Function applies the Binary search Algorithm with the method of jump sort    */
/*****************************************************************************************/
int Jump_search(int length, int number);
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
/******************************************************************************/
/*Function: linear_search       		                         			  */
/*I/P Parameters: int array[], int length, int number			              */
/*Returns:it returns index of the number if found or -1 if it is not found    */
/*Desc:This Function applies the Linear search Algorithm  		              */
/******************************************************************************/
int linear_search(int start,int end, int number);

int array[20]={0,5,6,4,3,18,9,8,5,2,10,12,7,15,17,20,25,29,35,45};  //Array of integers to be used in search

int main ()  // main Function
{
  int length = sizeof(array) / sizeof(array[0]);  //Get the length of the Array
  int number = 45;  //Number to be searched for
  int result = Jump_search(length,number);  //Function call to search for the number and get the result back
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

int Jump_search(int length, int number)
{
    //Jump sort as Binary search requires sorting 
    simple_sort(length);
    int step = sqrt(length); //calculate the step 
    int start=0; //declration of start index
    int end=length-1; //declration of end index
    while (1) //loop to apply jump search algorithm
    {
        
         if (number > array[start] && number <= array[end]) //check on number if still bounded between start and end
        {
            start+=step; //add step to start
            if (start >= length-1) // check if start is bigger than length
            {
                start-=step; //return start one step back to maintain number is still bounded
                break; //break from the loop
            }
            else if (number < array[start]) // check if number is less than the current value of start
            {
                end =start; //set the end to the start value after the last step is added
                start-=step; //return start one step back
                break;
            }
        }
        else
        {
            break;
        }
    }
 return linear_search(start, end, number); //call linear search for the boundary between start and end 

}

int linear_search(int start,int end, int number)
{ 

 int found=-1; //variable to be returned to caller 
 for (int i=start; i<=end; i++) //loop to search for the number
 {
    if (number ==array[i]) //check if the number is found at index number i
     {
      found=i; // if found, found variable will be changed to the index of the number
      break;   // break from the loop after the number is found
     }
 }
 return found; //return search result
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