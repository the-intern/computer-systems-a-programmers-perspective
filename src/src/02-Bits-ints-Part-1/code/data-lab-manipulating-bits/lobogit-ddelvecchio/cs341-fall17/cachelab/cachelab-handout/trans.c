/*
 * trans.c
 *
 *  Created on: Dec 1, 2017
 *      Author: Dominic Delvecchio
 *      ddelvecchio
 */

/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include <stdlib.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char transpose_submit_desc[] = "Transpose submission";
/*
 * Transpose function for the 61*67. Uses four for loops to divide the matrix
 * into submatrices that allow the code to utilize the cache locality. Since
 * the 61*67 matrix is not square so an extra check must be utilized in the
 * bottom two four loops to insure the matrix does not go out of bounds
 */
void transposeIrregular(int M, int N, int A[N][M], int B[M][N])
{
  int block = 16;
  int diagflag = 0;
  int i,j,k,l,dindex,temp;
  for(i = 0; i < N; i += block)
    {
      for(j = 0; j < M; j += block)
	{
	  for(k = i; (k < i+block)&&(k<N); k++)
	    {
	      for(l = j; (l < j + block)&&(l<M); l++)
		{
		  /*
		   * This checks the diagonal. When you transpose a matrix the diagonal is in the
		   * same spot for both matrices, but this can cause cache misses for B as the
		   * matriix positions stored in the cache are not the same as A. If you do not
		   * store in a temporary variable, when you access B you will miss, if the cache
		   * access that set again it will now miss again.
		   */
		  if(k!=l) B[l][k] = A[k][l];
		  else
		    {
		      temp = A[k][l];
		      dindex = k;
		      diagflag = 1;
		    }

		}
	      /*
	       * a check if a diagonal is in temp
	       */
	      if(diagflag == 1)
		{
		  B[dindex][dindex] = temp;
		  diagflag = 0;
		}
	    }
	}
    }
}
/*
 * This function works the same way as transpose irregular. The difference is the matrix is square
 * so there is no need for an additional check in the bottom two for loops. This function is passed
 * an additional value based on the size of the matrix 32x32 or 64x64 that sets the block size.
 */
void transposeSquare(int size, int M, int N, int A[N][M], int B[M][N])
{
  int block,i,j,k,l,dindex,temp;
  int diagflag = 0;
  if(size == 32)
    {
      block = 8;
    }
  else
    {
      block = 4;
    }

  for(i = 0; i < N; i += block)
    {
      for(j = 0; j < M; j += block)
	{
	  for(k = i; k < i + block; k++)
	    {
	      for(l = j; l < j + block; l++)
		{
		  //same as the first function checks if the value is diagonal
		  if(k!=l) B[l][k] = A[k][l];
		  else
		    {
		      temp = A[k][l];
		      dindex = k;
		      diagflag= 1;
		    }

		}
	      //checks if the diagonal is in temp
	      if(diagflag == 1)
		{
		  B[dindex][dindex] = temp;
		  diagflag = 0;
		}
	    }
	}
    }

}
/*
 * The transpose submit function uses a simple switch statement to call either
 * transpose square or transpose irregular depending on whether or not the matrix
 * is square or irregular. If the function is square a 32 or 64 is passed to the
 * function and the function selects the correct block size.
 */
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
  switch(M)
    {
    case 32:
      transposeSquare(32,M,N,A,B);
      break;
    case 64:
      transposeSquare(64,M,N,A,B);
      break;
    case 61:
      transposeIrregular(M,N,A,B);
      break;
    default:
      exit(1);
    }
}

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

/*
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{


}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
  /* Register your solution function */
  registerTransFunction(transpose_submit, transpose_submit_desc);

  /* Register any additional transpose functions */
  registerTransFunction(trans, trans_desc);

}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
  int i, j;

  for (i = 0; i < N; i++) {
    for (j = 0; j < M; ++j) {
      if (A[i][j] != B[j][i]) {
	return 0;
      }
    }
  }
  return 1;
}


