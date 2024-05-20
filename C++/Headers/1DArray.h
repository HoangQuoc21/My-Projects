#include <iostream>
using namespace std;

void inputArray(int* &a, int &n){
    for (int i=0; i<n; i++){
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void printArray(int *a, int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int* findMax(int* arr, int n){
    int *max  = new int;
    *max = arr[0];
    for (int i = 1; i < n; i++){
        for (int j = i +1; j < n; j++){
            if (arr[j] > *max)
                *max = arr[j];
        }
    }
    return max;
}

int* findLongestAscendingSubarray(int* a, int n, int& length){
    length = 1;
    int lengthMax = 1;
    int currIndex = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] > a[i - 1])
            length++;
        else{
            if (length > lengthMax){
                lengthMax = length;
                currIndex = i - length;
            }
            length = 1;
        }
    }
    // Khi i == n
    if (length > lengthMax){
        lengthMax = length;
        currIndex = n - length + 1;
    }
    length = lengthMax;
    return &a[currIndex];
}

void swapArrays(int* &a, int* &b, int &na, int &nb){
    int temp = na;
    na = nb;
    nb = temp;
    int* tempPointer = &a[0];
    a = &b[0];
    b = tempPointer;
}

int* concatenate2Arrays(int* a, int*b, int na, int nb, int &nc){
    nc = na+nb;
    int* c = new int[nc];
    for (int i = 0; i < na; i++){
        c[i] = a[i];
        c[i+na] = b[i];
    }
    return c;
}

int* merge2Arrays(int*a , int*b, int na, int nb, int &nc){
    int* c = concatenate2Arrays(a,b,na,nb,nc);
    for (int i = 0; i < nc; i++){
        for (int j = i; j < nc; j++){
            if (c[j] < c[i]){
                swap(c[j], c[i]);
            }
        }
    }
    return c;
}