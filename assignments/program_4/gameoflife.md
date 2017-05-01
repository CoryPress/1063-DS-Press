```/**
* @ProgramName: program_4
* @Author: Cory Press
* @Description: 
*     This program simulates the game of life. It creates a board using a two deminsional
*     array with 1s representing a live cell. Then based on a simple set of rules it simulates
*     generation by generation, determing when a new cell is born and one dies.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 01 05 2017
*/

#include <iostream>
#include <string>
#include <fstream>


#include <unistd.h>

using namespace std;

class GameOfLife{
private:
    int **Board;
    int **Board2;
    int Rows;
    int Cols;
public:
    GameOfLife(string filename){
        string line;
        char ch;
        ifstream fin;
        fin.open(filename);
        fin >> Rows >> Cols;
        InitBoardArray(Board);
        InitBoardArray(Board2);
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                fin.get(ch);
                if (ch == 10){
                    continue;
                }
                Board[i][j] = int(ch) - 48;
            }
        }
    }
    
    GameOfLife(int r, int c){
        Rows = r;
        Cols = c;
        InitBoardArray(Board);
        InitBoardArray(Board2);
        PrintBoard();
    }
    
    void InitBoardArray(int **&b){
        b = new int*[Rows];
        for (int i = 0; i < Rows; i++){
            b[i] = new int[Cols];
        }
        ResetBoardArray(b);
    }
    
    void ResetBoardArray(int **&b){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                b[i][j] = 0;
            }
        }
    }
    
    void PrintBoard(){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                if (Board[i][j] == 1)
                    cout << char('X');
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
    
    int CountNeighbors(int row, int col){
        int neighbors = 0;
        if (Board[row][col] == 1){
            neighbors--;
        }
        for (int i = row - 1; i <= row + 1; i++){
            for (int j = col - 1; j <= col + 1; j++){
                if (OnBoard(i, j)){
                    neighbors += Board[i][j];
                }else{
                    neighbors += CheckOppositeSide(i, j);
                }
            }
        }
        return neighbors;
    }
    
    bool OnBoard(int row, int col){
        return (row >= 0 && row < Rows && col >= 0 && col < Cols);
    }
    
    void RandomPopulate(int num){
        int r = 0;
        int c = 0;
        for (int i = 0; i<num; i++){
            r = rand() % Rows;
            c = rand() % Cols;
            Board[r][c] = 1;
        }
    }
    
    void SetCell(int r, int c, int val){
        Board[r][c] = val;
    }
    
    void AddGens(){
        for (int i = 0; i < Rows; i++){
            for (int j = 0; j < Cols; j++){
                Board[i][j] += Board2[i][j];
            }
        }
        ResetBoardArray(Board2);
    }
    
    void clear_screen(int lines){
      for(int i=0;i<lines;i++){
        cout<<endl;
      }
    }
   
/**
* @FunctionName: CheckOppositeSide
* @Description: 
*     recieves a set of coordinates that is off the two-deminsional Array, and
*     checks the oppostie side of the Array and returns its value.
* @Params:
*    int r - the row of the coordinate
*    int c - the colomn of the coordinate
* @Returns:
*    int - the value in the two-deminsional array on the opposite side
*/
    int CheckOppositeSide(int r, int c){
      if(r < 0 && c >= 0 && c < Cols){
         return Board[Rows - 1][c];
      }else if(r >= Rows && c >= 0 && c < Cols){
         return Board[0][c];
      }else if(c < 0 && r >= 0 && r < Rows){
         return Board[r][Cols - 1];
      }else if(c >= Cols && r >= 0 && r < Rows){
         return Board[r][0];
      }else if(c < 0 && r < 0){
         return Board[Rows - 1][Cols];
      }else if(c < 0 && r >= Rows){
         return Board[0][Cols - 1];
      }else if(c >= Cols && r < 0){
         return Board[Rows - 1][0];
      }else if(c >= Cols && r >= Rows){
         return Board[0][0];
      }
    }

/**
* @FunctionName: Stable
* @Description: 
*     This function looks at Board2 and loops through the entire board, until
*     it comes across a value other than 0. If it does it returns true, otherwise it
*     returns false, as no change will occur on the board
* @Params:
*    
* @Returns:
*    bool - If true the board is stable, if false it is  changing in some way
*/
    bool Stable(){
      for (int i = 0; i < Rows; i++){
          for (int j = 0; j < Cols; j++){
              if(Board2[i][j] != 0){
                    return false;
              }
          }
      } 
      return true;
    }

/**
* @FunctionName: GliderGun
* @Description: 
*     This function clears the current board a places a structure that will
*     coninuely shoot off gliders.
* @Params:
* 
* @Returns:
*    void
*/  
    void GliderGun(){
      ResetBoardArray(Board);
      ResetBoardArray(Board2);
      SetCell(5, 1, 1);
      SetCell(5, 2, 1);
      SetCell(6, 1, 1);
      SetCell(6, 2, 1);
      SetCell(5, 11, 1);
      SetCell(6, 11, 1);
      SetCell(7, 11, 1);
      SetCell(8, 12, 1);
      SetCell(9, 13, 1);
      SetCell(9, 14, 1);
      SetCell(8, 16, 1);
      SetCell(7, 17, 1);
      SetCell(6, 17, 1);
      SetCell(5, 17, 1);
      SetCell(6, 18, 1);
      SetCell(6, 15, 1);
      SetCell(4, 16, 1);
      SetCell(3, 14, 1);
      SetCell(3, 13, 1);
      SetCell(4, 12, 1);
      SetCell(5, 21, 1);
      SetCell(4, 21, 1);
      SetCell(3, 21, 1);
      SetCell(2, 23, 1);
      SetCell(2, 25, 1);
      SetCell(1, 25, 1);
      SetCell(5, 22, 1);
      SetCell(4, 22, 1);
      SetCell(3, 22, 1);
      SetCell(6, 23, 1);
      SetCell(6, 25, 1);
      SetCell(7, 25, 1);
      SetCell(3, 35, 1);
      SetCell(3, 36, 1);
      SetCell(4, 35, 1);
      SetCell(4, 36, 1);
    }
    
    void Run(int generations=99999){
        PrintBoard();
        int neighbors = 0;
        int g = 0;
        while (g < generations){
            for (int i = 0; i < Rows; i++){
                for (int j = 0; j < Cols; j++){
                    neighbors = CountNeighbors(i, j);
                    if (Board[i][j] == 1 && (neighbors < 2 || neighbors > 3)){
                        Board2[i][j] = -1;
                    }
                    if (Board[i][j] == 0 && neighbors == 3){
                        Board2[i][j] = 1;
                    }
                }
            }
            if(Stable()){
              cout << "Board is stable";
              return;
            }
            AddGens();
            usleep(100000);
            clear_screen(30);
            PrintBoard();
            g++;
        }
        
    }
};

int main(){
    GameOfLife G("gen_one.txt");
    
    G.GliderGun();
   
    G.Run(100);
    return 0;
}
```
