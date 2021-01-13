#include<iostream>
#include <windows.h> 
using namespace std;
bool FindEmpty(int sudoku[9][9], int& r, int& c)
{
    for (r = 0; r < 9; r++)
    {
        for (c = 0; c < 9; c++)
        {
            if (sudoku[r][c] == 0)
            {
                return true;
            }
        }
    }
    return false;
}
bool SafeInRow(int sudoku[9][9], int r, int n)
{
    for (int c = 0; c < 9; c++)
    {
        if (sudoku[r][c] == n)
        {
            return false;
        }
    }
    return true;
}
bool SafeInCol(int sudoku[9][9], int c, int n)
{
    for (int r = 0; r < 9; r++)
    {
        if (sudoku[r][c] == n)
        {
            return false;
        }
    }
    return true;
}
bool SafeInBox(int sudoku[9][9], int i,int j, int n)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (sudoku[r + i][c + j] == n)
            {
                return false;
            }
        }
    }
    return true;
}
bool isSafe(int sudoku[9][9], int r, int c, int n)
{
	if(SafeInRow(sudoku, r, n) == 1 && SafeInCol(sudoku, c, n) == 1 && SafeInBox(sudoku, r - r % 3, c - c % 3, n) == 1 && sudoku[r][c] == 0)
	{
		return true;
	}
	return false;
}
bool SolveSudoku(int sudoku[9][9])
{
    int r, c;

    if (FindEmpty(sudoku, r, c) == 0)
    {
        return true;
    }
 
    for (int n = 1; n <= 9; n++) 
    {  
        if (isSafe(sudoku, r, c, n)) 
        {
            sudoku[r][c] = n;
 
            if (SolveSudoku(sudoku))
            {
                return true;
            }
 
            sudoku[r][c] = 0;
        }
    }
    return false;
}
bool isValid(int sudoku[9][9])
{
	int temp;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if(sudoku[i][j] != 0)
			{
				temp = sudoku[i][j];
				sudoku[i][j] = 0;
				if(isSafe(sudoku, i, j, temp) == false)
				{
					cout<<temp<<" "<<sudoku[i][j];
					return false;
				}
				sudoku[i][j] = temp;
			}
		}
	}
	return true;
}
void print(int sudoku[9][9])
{
	system("cls");
	int countr=0, countc=0;
	cout<<"\n\t                     _____________________________________________________________________________________________  ";
    cout<<"\n\n\t\t                                         |           SUDOKU SOLVER         |";
    cout<<"\n\n\t\t                 _________________________________________________________________________________  \n\n\t\t\t\t\t\t\t\t";
    for (int i = 0; i < 9; i++) 
    {
    	countc=0;
        for (int j = 0; j < 9; j++)
        {
            cout<<sudoku[i][j]<<" ";
            countc++;
            if(countc == 3 && j+1 < 9)
            {
            	cout<<"|"<<" ";
            	countc=0;
            }
        }
        cout<<endl;
        countr++;
        if(countr == 3)
        {
        	cout<<"\t\t\t\t\t\t\t\t_____________________\n\n";
        	countr=0;
        }
        cout<<"\t\t\t\t\t\t\t\t";
    }
    cout<<"\n\n\n\n\t\t\t\t                                                                             -PRESS ENTER TO ESCAPE        ";
    getchar();
    getchar();
}
void input()
{
	system("cls");
	int sudoku[9][9];
	cout<<"\n\tEnter The Sudoku in a form of 9X9 Matrix (Empty Spaces should be denoted with 0) : "<<endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin>>sudoku[i][j];
		}
	}
	if(isValid(sudoku) == true)
	{
		if (SolveSudoku(sudoku) == true)
    	{
        	print(sudoku);
    	}
    	else
    	{
        	cout<<"\n\n\t\t!!No solution exists!!";
        	getchar();
			getchar();
    	}
	}
	else
	{
		cout<<"\n\n\t\t!! INVALID INPUT !!";
		getchar();
		getchar();
	}
}
void about()
{
    system("cls");
    cout<<"\n\t                     _____________________________________________________________________________________________  ";
    cout<<"\n\n\t\t                                         |           SUDOKU SOLVER         |";
    cout<<"\n\n\t\t                 _________________________________________________________________________________  ";
    cout<<"\n\n\t\t                                                        ABOUT                                               ";
    cout<<"\n\n\t\t                                  Sudoku is a logic-based, combinatorial number-placement ";
    cout<<"\n\n\t\t                                  puzzle. In classic sudoku, the objective is to fill a ";
    cout<<"\n\n\t\t                                  9X9 grid with digits so that each column, each row ";
    cout<<"\n\n\t\t                                  and each of the nine 3X3 subgrids that compose the ";
    cout<<"\n\n\t\t                                  grid contain all of the digits from 1 to 9.";
    cout<<"\n\n\t\t                                          This Program is developed by Jigyasu";
    cout<<"\n\n\t\t                                          To give the solution of any 9X9 Sudoku.";
    cout<<"\n\n\n\n\t\t\t\t                                                                             -PRESS ENTER TO ESCAPE        ";
    getchar();
    getchar();
    system("cls");
}
void inst()
{
    system("cls");
    cout<<"\n\t                     _____________________________________________________________________________________________  ";
    cout<<"\n\n\t\t                                         |           SUDOKU SOLVER         |";
    cout<<"\n\n\t\t                 _________________________________________________________________________________  ";
    cout<<"\n\n\t\t                                                     INSTRUCTIONS                                                ";
    cout<<"\n\n\t\t                                  In this program you have to enter a 9X9 SUDOKU";
    cout<<"\n\n\t\t                                  in Matrix form. You can denote blank spaces in";
    cout<<"\n\n\t\t                                  a SUDOKU by typing '0' ";
    cout<<"\n\n\t\t                                  The Number entered should be ina range of 1-9";
    cout<<"\n\n\t\t                                  where 0 is for blank spaces.There should be no";
    cout<<"\n\n\t\t                                  repetition of a number in a row, column and in 3x3 matrix";
    cout<<"\n\n\n\n\t\t\t\t                                                                             -PRESS ENTER TO ESCAPE        ";
    getchar();
    getchar();
    system("cls");
}
int main()
{
	int ch;
	do
	{
		system("cls");
		cout<<"\t\t.................................................."<<endl;
		cout<<"\t\t|                                                |"<<endl;
		cout<<"\t\t|                  SUDOKU SOLVER                 |"<<endl;
		cout<<"\t\t|                                                |"<<endl;
		cout<<"\t\t|________________________________________________|"<<endl;
		cout<<"\t\t|                    MAIN MENU                   |"<<endl;
		cout<<"\t\t|________________________________________________|"<<endl;
		cout<<"\t\t|                                                |"<<endl;
		cout<<"\t\t| 1. Input by typing 9X9 Matrix                  |"<<endl;
		cout<<"\t\t|                                                |"<<endl;
		cout<<"\t\t| 2. Instructions                                |"<<endl;
		cout<<"\t\t|                                                |"<<endl;
		cout<<"\t\t| 3. About                                       |"<<endl;
		cout<<"\t\t|                                                |"<<endl;
		cout<<"\t\t| 0. Exit                                        |"<<endl;
		cout<<"\t\t|                                                |"<<endl;
		cout<<"\t\t.................................................."<<endl;
		cout<<"\t\t         Enter Your Choice : ";
		cin>>ch;
		cout<<"\t\t\n\n                                            Loading";
		Sleep(500); 
		cout<<".";
		Sleep(500);
		cout<<".";
		Sleep(500);
		cout<<".";
		Sleep(500);
		switch(ch)
		{
			case 1: input();
			 			break;
			case 2: inst();
						break;
			case 3: about();
						break;
			case 0: break;

			default: cout<<"\n\n\t\t!!You Have Entered the Wrong Choice!!";
						break;
		}
	}while(ch!=0);
	return 0;
}