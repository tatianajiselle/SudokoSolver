//
//  sudokusolver.cpp
//  cse 382
//
//  Created by Tatiana Ensslin on 2/22/15.
//  Copyright (c) 2015 Tatiana Ensslin. All rights reserved.
// Partial code By Roger Chen

#include<iostream>
#define UNASSIGNED 0 //0 if the square is undefined
#define SQR 3 //square root of the row/column #
using namespace std;

//prototypes
void entergrid(int grid[][9]); //allows you to enter a new grid
void viewgrid(int grid[][9]); //prints the grid


bool useablecolumn(int grid[][9], int col, int num){ //if the column has that number in it already
    for (int row=0; row < 9; row++){
        if (grid[row][col] == num ){ //if that number already exists in that column
            return true;}}
        return false; //if the number does not exist
}
bool useablerow(int grid[][9], int row, int num) //if that row has that number in it already
{
    for (int col=0; col < 9; col++)
        if (grid[row][col]==num)//if that number already exists in that row
            return true;
    return false; //if the number does not exist
}

bool useablebox(int grid[][9], int boxstartR, int boxstartC, int num){ //if that box has already used that number

    for (int row = 0; row<SQR; row++)
        for (int col=0; col<SQR; col++)
            if (grid[row+boxstartR][col+boxstartC] == num) //if that number already exists in that box
                return true;
        return false; //if the number does not exist
    
}

bool useablenumber(int grid[][9], int row, int col, int num){ //if the number is a safe guess in the unassigned boc
    return ((!useablerow(grid,row,num)) && (!useablecolumn(grid,col,num)) && (!useablebox(grid,row - row%SQR,col - col%SQR,num)));
            }

bool location(int grid[][9],int &row, int &col){ //if the location of the index is unassigned or not
    for (row=0; row < 9; row++)
        for(col=0;col < 9; col++)
            if (grid[row][col] == UNASSIGNED) //if its unassigned return true
                return true;
    return false; //if its assigned return false
}

bool sudokusolver(int grid[][9]){
    int row=0;
    int col=0;
   
    if (!location(grid,row,col)){ //if location=false..inverse to true
        return true;} //if true...(should hit at end of puzzle).. puzzle complete
    for (int num=1; num<= 9 ; num++){
        if (useablenumber(grid,row,col,num)){ //if that number is useable
            grid[row][col]=num; //save that number into the grid
        if (sudokusolver(grid))
            return true;
    grid[row][col]=UNASSIGNED; //if everything is passed reset to unassigned
        }
    }
return false;
}

int main()
{
	//int i, j, k, i1, i2, j1, j2, p, count, po, po_x, po_y;
	int grid[9][9] =
	{
        
		{ 0, 7, 5, 0, 0, 0, 8, 4, 0 },
		{ 2, 0, 0, 5, 0, 8, 0, 3, 0 },
		{ 0, 0, 1, 0, 0, 3, 0, 2, 5 },
		{ 5, 2, 0, 3, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 9, 0, 5, 0, 0, 0 },
		{ 0, 9, 0, 0, 0, 4, 0, 6, 3 },
		{ 4, 5, 0, 7, 0, 0, 3, 0, 0 },
		{ 0, 8, 0, 4, 0, 6, 0, 0, 7 },
		{ 0, 1, 3, 0, 0, 0, 6, 8, 0 }
	};
    
    //If you want to enter a different problem, you should un-comment the next statement.
	cout<<"Would you like to select a pre-entered puzzle <p> or enter your own <o>?\n";
    char answer;
    char answer2;
    cin >> answer;
    
    switch(answer){
        case 'p': {
            cout<< "Enter your puzzle type: Simple <s>, Medium <m>, Difficult <d>, or Evil <e>?";
            cin >> answer2;
            if (answer2 == 's' || 'S'){
                cout<<"The puzzle you have chosen appears as the following:\n";
                viewgrid(grid); //starting off print of puzzle
            
                if (sudokusolver(grid)==true)
                    viewgrid(grid);
                else
                    cout<<("No Solution Exists");
                break;
                }
                if (answer2 == 'm' || 'M'){
                       int grid1[9][9] =
                    {
                        
                        { 5, 0, 0, 0, 6, 0, 0, 7, 8 },
                        { 2, 0, 0, 0, 0, 3, 9, 4, 5 },
                        { 0, 3, 0, 0, 0, 8, 0, 0, 0 },
                        { 9, 0, 8, 0, 2, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 0, 0, 0, 1, 0, 6, 0, 3 },
                        { 0, 0, 0, 2, 0, 0, 0, 3, 0 },
                        { 3, 7, 1, 4, 0, 0, 0, 0, 2 },
                        { 6, 9, 0, 0, 3, 0, 0, 0, 4 }
                    };
                    cout<<"The puzzle you have chosen appears as the following:\n";
                    viewgrid(grid1); //starting off print of puzzle
                    
                    if (sudokusolver(grid1)==true)
                        viewgrid(grid1);
                    else
                        cout<<("No Solution Exists");
                    break;
            }

                        
            if (answer2 == 'd' || 'D'){
                int grid2[9][9] =
                {
                    
                    { 9, 1, 0, 0, 0, 0, 0, 4, 6 },
                    { 8, 0, 0, 0, 4, 0, 0, 0, 0 },
                    { 0, 0, 7, 6, 0, 0, 8, 0, 0 },
                    { 0, 7, 0, 4, 9, 0, 0, 0, 0 },
                    { 0, 2, 0, 0, 0, 0, 0, 1, 0 },
                    { 0, 0, 0, 0, 7, 5, 0, 3, 0 },
                    { 0, 0, 5, 0, 0, 4, 1, 0, 0 },
                    { 0, 0, 0, 0, 5, 0, 0, 0, 8 },
                    { 1, 3, 0, 0, 0, 0, 0, 2, 7 }
                };
                cout<<"The puzzle you have chosen appears as the following:\n";
                viewgrid(grid2); //starting off print of puzzle
                
                if (sudokusolver(grid2)==true)
                    viewgrid(grid2);
                else
                    cout<<("No Solution Exists");
                break;
            }

            
            if (answer2 == 'e' || 'E'){
                int grid3[9][9] =
                {
                    
                    { 0, 9, 0, 0, 2, 0, 0, 0, 0 },
                    { 2, 3, 1, 0, 0, 8, 0, 0, 0 },
                    { 0, 4, 0, 3, 0, 0, 0, 0, 0 },
                    { 0, 0, 2, 7, 0, 0, 1, 0, 0 },
                    { 0, 0, 9, 0, 5, 0, 7, 0, 0 },
                    { 0, 0, 5, 0, 0, 4, 9, 0, 0 },
                    { 0, 0, 0, 0, 0, 1, 0, 6, 0 },
                    { 0, 0, 0, 6, 0, 0, 2, 1, 5 },
                    { 0, 0, 0, 0, 3, 0, 0, 8, 0 }
                };
                cout<<"The puzzle you have chosen appears as the following:\n";
                viewgrid(grid3); //starting off print of puzzle
                
                if (sudokusolver(grid3)==true)
                    viewgrid(grid3);
                else
                    cout<<("No Solution Exists");
                break;
            }
        }
            case 'o':
                entergrid(grid);
            cout<<"The puzzle you have chosen appears as the following:\n";
            viewgrid(grid); //starting off print of puzzle
            
            if (sudokusolver(grid)==true)
                viewgrid(grid);
            else
                cout<<("No Solution Exists");
            break;
    }
    
	return 0;
}

void entergrid(int grid[][9]) //allows user to enter a grid
{
    
    
	cout << "Enter grid\n\n";
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> grid[i][j];
}

void viewgrid(int grid[][9]) //prints the puzzle
{
	cout << "The following are the grid values: \n\n";
	for (int i = 0; i < 9; i++)
	{
		cout << " -------------------------------------\n";
        
		for (int j = 0; j < 9; j++)
			cout << " | " << grid[i][j];
        
		cout << " |\n";
	}
    cout << " -------------------------------------\n";
}
