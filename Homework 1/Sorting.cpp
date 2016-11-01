//
//  main.cpp
//  homework1
//
//  Created by Corey Henry on 9/19/16.
//  Copyright © 2016 Corey Henry. All rights reserved.
//

//
//  algorithims-hw1.cpp
//
//
//  Created by Corey Henry on 9/19/16.
//
//
#include <chrono>
#include <iostream>
#include <cstdlib>
using namespace std;






//code from algolist.net
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}



//code from algolist.net
void insertionSort(int arr[], int length) {
    int i, j, tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

int main()
{
    int* quick;
    int* insert;
    
    for(int length = 5; length < 1000000000; length*=2)
    {
        quick= new int[length];
        insert= new int[length];
        
        //get random numbers between 1 and 100 and insert them into the array
        for(int i =0; i < length; i++)
        {
            int number = rand() % 1001;
            quick[i] = number;
            insert[i] = number;
        }// end of for loop for inserting numbers into the arrays
        
        
        //check time run quick sort check time again and then get the total time it took
        std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
        quickSort(quick,0,length-1);
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> quicktime = t2 - t1;
        
        //check the time run insertion and check time again then get total time it took
        std::chrono::high_resolution_clock::time_point t3 = std::chrono::high_resolution_clock::now();
        insertionSort(insert,length);
        std::chrono::high_resolution_clock::time_point t4 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> inserttime = t4 - t3;
        
        //print how long each array took to sorth
        cout << "The length of the array was " << length << endl;
        cout << "Quicksort algorithim took "<< quicktime.count() << " milliseconds" << endl;
        cout << "Insertion algorithim took "<< inserttime.count() << " milliseconds" << endl;
        cout << "\n" << endl;
        

        
        
    }//end of for loop
    return 0;
}//end of main

