/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<stdbool.h>
int get(int *arr, int diff, int start, int len)
{
	int i, result = 0;
	for (i = start;i+1 < len && arr[i + 1] - arr[i] == diff; i++)
	{
		result = i + 1;
	}
	return result;
}
int * find_sequences(int *arr, int len){
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	int *result = (int *)malloc(sizeof(int)* 6);
	int diff1, diff2;
	int i, ap, gp;
	int ab, bc;
	bool first_ap = false, first_gp = false;
	if (arr == NULL)
		return NULL;
	for (i = 0; i < len - 1; i++)
	{
		diff1 = arr[i + 2] - arr[i + 1];
		diff2 = (arr[i + 1] - arr[i]);
		ab = arr[i + 1] / arr[i];
		bc = arr[i + 2] / arr[i + 1];
		if (diff1 = diff2)
		{

			if (first_ap == false)
			{
				result[0] = i;
				first_ap = true;
				result[1] = get(arr, diff1, i, len);
				i = result[1];
			}
			else
			{
				result[1] = i;
				result[2] = get(arr, diff1, i, len);
				i = result[2];
			}
		}
		else if (ab == bc)
		{
			if (first_gp == false)
			{
				result[4] = i;
				first_gp = true;
				result[5] = i + 2;
			}
			else
			{
				result[5] = i + 2;
			}
		}
	}
	return result;
}