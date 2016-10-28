/*
 * =====================================================================================
 *
 *       Filename:  minesweeper.c
 *
 *    Description:  To count the neighbouring mines (1s) of each 2D array element and
 *                  and replace the array with each element showing the count of 
 *                  neighbouring mines.
 *
 *                  For example,
 *
 *                  Input array = 
 *                  0 1 0
 *                  0 0 0
 *                  1 0 0
 *
 *                  Output array =
 *                  1 0 1
 *                  2 2 1
 *                  0 1 0
 *
 *        Version:  1.0
 *        Created:  09/17/2016 01:50:00 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Kurup (pk), prakashkurup7@gmail.com
 *        Company:  NONE
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/* Function to count the number of neighbouring 1s */
int mineCount(int **arr, int newN, int row, int col)
{
  int i, j;
  int count = 0;

  for (i = row - 1; i <= row + 1; i++) {
    for (j = col - 1; j <= col + 1; j++) {

      /* Count the number of neighbouring 1s but not itself */
      if (arr[i][j] == 1 && (i != row || j != col))
        count++;
    }
  }

  return count;
}

/* Function to print the 2D array */
void printArray(int N, int **arr)
{
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(void)
{
  int N;
  int i, j;

  printf("Enter N for (N X N) matrix\n");
  scanf("%d", &N);

  /* Dynamically allocating 2D array */
  int **arr = (int **)malloc(N * sizeof(int *));
  for (i = 0; i < N; i++) {
    arr[i] = (int *)malloc(N * sizeof(int));
  }

  /* User enter array elements */
  printf("\nEnter '1' for mines or '0' for no mines\n");
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("Array[%d][%d]: ", i, j);
      scanf("%d", &arr[i][j]);
    }
  }

  /* New array with N+2 rows and columns using calloc.
   * All array elements will be initialized to zero.
   * */
  int newN = N + 2;
  int **new_arr = (int **)calloc(newN, sizeof(int *));
  for (i = 0; i < newN; i++) {
    new_arr[i] = (int *)calloc(newN, sizeof(int));
  }

  /* Printing the given array */
  printf("\nGiven array:\n");
  printArray(N, arr);

  /* Copy values of (N x N) array to new array.
   * This is done to create a padding of zeros around
   * the original array.
   * */
  for (i = 1; i < newN - 1; i++) {
    for (j = 1; j < newN - 1; j++) {
      new_arr[i][j] = arr[i - 1][j - 1];
    }
  }

  /* Replace each array element with count of neighbouring 1s */
  for (i = 1; i < newN - 1; i++) {
    for (j = 1; j < newN - 1; j++) {
      arr[i - 1][j - 1] = mineCount(new_arr, newN, i, j);
    }
  }

  /* Printing the result array */
  printf("After finding mines...\n");
  printArray(N, arr);

  /* Free them mallocs and callocs */
  free(arr);
  free(new_arr);

  return 0;
}

