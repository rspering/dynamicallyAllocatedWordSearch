/**
Here in the .cpp you should define and implement the functions that are declared in the .h file.
It is not recommended to add extra functions on this assignment.
**/

#include "matrix_search.h"


// We're giving you this one the first time, and you should copy it into all future assignments.
// Change the information to your own email handle (S&T username)
void get_identity(string &my_id)
{
  my_id = "rjstrd";
}


char ** build_matrix(int rows, int cols)
{
  char** matrix = new char*[rows];
  for(int i = 0; i < rows; i++)
  {
    matrix[i] = new char[cols];
  }

  return matrix;
}


void fill_matrix(int rows, int cols, char **matrix)
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      cin >> matrix[i][j];
    }
  }
}


void print_matrix(int rows, int cols, char **matrix)
{
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}


void delete_matrix(int rows, char **matrix)
{
  for(int i = 0; i < rows; i++)
  {  
    delete[] matrix[i];
  }
  delete[] matrix;
}


void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{
  int length = word.length();
  int xDirections[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  int yDirections[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  
  for(int i = 0; i < 4; i++)
  {
    sol[i] = -1;
  }

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (matrix[i][j] == word[0])
      {
        for (int d = 0; d < 8; d++)
        {
          for(int k = 1; k < length; k++)
          {
            if ((i + (k * yDirections[d])) >= 0 && (j + (k * xDirections[d])) >= 0 && matrix[i + (k * yDirections[d])][j + (k * xDirections[d])] == word[k] && (i + (k * yDirections[d])) < rows && (j + (k * xDirections[d])) < cols)
            {
              if (k == length - 1)
              {
                sol[0] = i;
                sol[1] = j;
                sol[2] = i + k * yDirections[d];
                sol[3] = j + k * xDirections[d];
              
              }
            }
            else
            {
              break;
            }
          }
        }
      }
    }
  }
}

