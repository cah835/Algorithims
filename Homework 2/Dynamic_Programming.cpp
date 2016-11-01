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


//memoization algorithim
int MemoSort(int n, int k, int** Narray)
{
   // cout << Narray[n][k] << endl;
    for(int i=1; i<n+1; i++)
    {
        for(int j=0; j<k+1; j++)
        {
            //set base cases
            if(j == 0 || j == i)
            {
                Narray[i][j] = 1;
            }
            else
            {
                Narray[i][j] = Narray[i-1][j] + Narray[i-1][j-1];
            }
        }//end of nested loop
    }//end of for loop

    //print Memo
    cout << "the output for Memoization array is " << endl;
    cout << Narray[n][k] << endl;
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
    return MemoSort(n,k, Narray);
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
            }
        }// end of for loop
    }
    //print the answer
    cout << "the output for Bottom_up array is " << endl;
    cout << BU_array[n][k] << endl;
    return BU_array[n][k];
}// end of bottom up

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
    //set value
    //call Memo
    Memo(n,k);
    Bottom_up(n,k);
    return 0;
}//end of main