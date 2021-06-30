/*******************************************************************************************
* ! Title : Binary Search
* ! File Name : Binary_Search.c
* ! Description : This file is Implementation of Binary search algorithm
********************************************************************************************/

#include <stdio.h>

/******************************************************************************/
/*Function: Binary_search       		                         			  */
/*I/P Parameters:  int length, int number	            		              */
/*Returns:it returns index of the number if found or -1 if it is not found    */
/*Desc:This Function applies the Binary search Algorithm  		              */
/******************************************************************************/
int Binary_search(int length, int number);
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
/*Function: Binary_search       		                         			  */
/*I/P Parameters:  int length, int number			                          */
/*Returns:it returns index of the number if found or -1 if it is not found    */
/*Desc:This Function applies the Binary search Algorithm using recursion      */
/******************************************************************************/
int Binary_search_recursive(int start, int end, int number);

int array[20]={0,5,6,4,3,6,9,8,5,6,10,12,7,15,17,20,25,29,35,45};  //Array of integers to be used in search

int main ()  // main Function
{
  int length = sizeof(array) / sizeof(array[0]);  //Get the length of the Array
  int number = 7;  //Number to be searched for
  int result = Binary_search(length,number);  //Function call to search for the number and get the result back
  int result2=Binary_search_recursive(0,length-1,number);//Function call to search for the number and get the result back
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
      printf("\nNumber %d is Found at location number %d after the array is sorted using normal Binary Search.",number,(result + 1));
      printf("\nNumber %d is Found at location number %d after the array is sorted using recursive Binary Search.\n",number,(result2 + 1));
  }
  
}


int Binary_search( int length, int number)
{
    simple_sort(length); //Binary search requires sorting the array before
    int start = 0; //Start location in the array
    int end = length-1;  //last location in the array
    int mid ; //Mid number between start and end
    int found = -1; //variable to be returned to caller
    while (start <= end) //while loop for searching
    {
        mid = (start + end) / 2; //calculate mid between start and end
        if (array[mid] == number) //check if the mid index is the required number
        {
            found = mid; // if number is found, set found to the index of the number
            break; // break from the loop
        }
        else if (array[mid] < number) // check if the middle of the array is less than the required number
        {
            start = mid + 1; //change the start to the index after the mid
        }
        else
        {
            end = mid - 1; //change the end to the index before the mid
        }
    } 
    return found; //return the result
}

int Binary_search_recursive(int start, int end, int number)
{
    simple_sort(length); //Binary search requires sorting the array before
    if(end > 0) //condition for the search
    {
        int mid= (start + end)/2; //calculate the mid

        if (array[mid]==number) //check if the number equal the mid the array
        {
            return mid; //return the index
        }
        else if (array[mid] < number) // check if the middle of the array is less than the required number
        {
            start = mid + 1; //change the start to the index after the mid
        }
        else
        {
            end = mid - 1; //change the end to the index before the mid
        }
        return Binary_search_recursive(start, end, number); //call the recursive binary function with new start and end
    }
    else
    {
        return -1; //return -1 means number not found
    }
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