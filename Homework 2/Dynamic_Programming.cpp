//
//  main.cpp
//  Homework 2
//
//  Created by Corey Henry on 10/30/16.
//  Copyright © 2016 Corey Henry. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

//set up counters to determine whats faster
int Mem_count = 0;
int BU_count = 0;
int C_count = 0;

//memoization algorithim
int Memoization(int n, int k, int** Narray)
{
    if(Narray[n][k] == -1)
    {
    Mem_count++;
    Narray[n][k] = Memoization(n-1, k, Narray) + Memoization(n-1, k-1, Narray);
    }
    return Narray[n][k];
}// end of MemoSort

// builds the array for Memoization method, populates the array then calls the sort
int Memo(int n, int k)
{
    int** Narray;
    Narray = new int*[n+1];
    //build the two diemensional array
    for(int i=0; i < n+1; i++)
    {
        Narray[i] = new int[k+1];
    }
    // set the array to -1 for unanswerd spots
    for(int i=0; i < n+1; i++)
    {
        for(int j=0; j<k+1; j++)
        {
            Narray[i][j] = -1;
        }
    }
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<k+1; j++)
        {
            //set base cases
            if(j == 0 || j == i)
            {
                Narray[i][j] = 1;
            }
        }//end of nested loop
    }//end of for loop
    return Memoization(n,k, Narray);
}//end of Memo

int Bottom_up(int n, int k)
{
    
    int** BU_array;
    BU_array = new int*[n+1];
    for(int i=0; i < n+1; i++)
    {
        BU_array[i] = new int[k+1];
    }
    for(int i=1; i < n+1; i++)
    {
        for(int j=0; j<k+1; j++)
        {
            if(j == 0 || j == i)
            {
                BU_array[i][j] = 1;
            }
            else
            {
            BU_array[i][j] = BU_array[i-1][j] + BU_array[i-1][j-1];
            BU_count++;
            }
        }// end of for loop
    }
    return BU_array[n][k];
}// end of bottom up

int C(int n, int k)
{
    if(k== 0 || k==n)
    {
        return 1;
    }
    else
    {
        C_count++;
        return C(n-1,k) + C(n-1,k-1);
    }
}

//main function that will set N and K and then call the different algorithims
int main()
{
    int k = 5;
    int n = 6;
    // get the values of N and K
    cout<< "what value do you want to set N at? " << endl;
    cin >> n;
    cout<< "what value do you want to set K at? "<< endl;
    cin >> k;
    cout << endl;
    //call the functions
    int Memo_answer = Memo(n,k);
    int BU_answer = Bottom_up(n,k);
    int C_answer = C(n,k);
    
    //print the results for Memoization
    cout << "the output for Memoization array is " << Memo_answer << endl;
    cout << Mem_count << " subproblems solved" << endl;
    cout << endl;
    
    //print the result for Bottom Up
    cout << "the output for Bottom_up array is " << BU_answer << endl;
    cout << BU_count << " sub problems solved" << endl;
    cout << endl;
    
    //print the result for C function provided
    cout << "the output for Recursive array is " << C_answer << endl;
    cout << C_count << " sub problems solved" << endl;
    cout << endl;
    
    return 0;
}//end of main