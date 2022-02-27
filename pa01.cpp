/**
Implement the main here to match input and output. 
**/

#include "matrix_search.h"

int main()
{
  short int numGames;
  cin >> numGames;

  for(int i = 0; i < numGames; i++)
  {
    short int rowInput, colInput;
    char** wordSearchMatrix;
    int solution[4];
    string word;

    cin >> rowInput;
    cin >> colInput;

    wordSearchMatrix = build_matrix(rowInput, colInput);
    fill_matrix(rowInput, colInput, wordSearchMatrix);

    cin >> word;

    matrix_search(solution, word, rowInput, colInput, wordSearchMatrix);
    
    cout << "Searching for \"" << word << "\" in matrix " << i << " yields:" << endl;
    if (solution[0] == -1)
    {
      cout << "The pattern was not found." << endl;
      cout << endl;
    }
    else
    {
      cout << "Start pos:(" << solution[0] << ", " << solution[1] << ") to End pos:(" << solution[2] << ", " << solution[3] << ")" << endl;
      cout << endl;
    }

    delete_matrix(rowInput, wordSearchMatrix);
  }

  return 0;
}

