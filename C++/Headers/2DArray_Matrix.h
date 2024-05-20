#include <iostream>
#include <iomanip>
using namespace std;

void printMatrix(int** a, int length, int width){
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
}

void generateMatrix1(int** &a, int &length, int &width){
    a = new int*[length];
    for (int i = 0; i < length; i++)
        a[i] = new int[width];
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++){
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

int** generateMatrix2(int* a, int* b, int na, int nb, int &crow, int &ccol){
    crow = na;  ccol = nb;
    int** c = new int*[crow];
    for (int i = 0; i < crow; i++)
        c[i] = new int [ccol];
    for (int i = 0; i < crow; i++){
        for (int j = 0; j < ccol; j++)
            c[i][j] = a[i]*b[j];
    }
    return c;
}

//Hàm swapArrays hỗ trợ swapRows
void swapArrays(int* &a, int* &b, int &na, int &nb){
    int temp = na;
    na = nb;
    nb = temp;
    int* tempPointer = &a[0];
    a = &b[0];
    b = tempPointer;
}

void swapRows(int** a, int length, int width, int ir1, int ir2){
    swapArrays(a[ir1], a[ir2], width, width);
}

void swapColumns(int** a, int length, int width, int ic1, int ic2){
    for (int i = 0; i < length; i++)
        swap(a[i][ic1], a[i][ic2]);
}

int** transposeMatrix(int** a, int length, int width){
    int** t = new int*[width];
    for (int i = 0; i < width; i++)
        t[i] = new int [length];
    for (int i = 0; i < width; i++)
        for (int j = 0; j < length; j++)
            t[i][j] = a[j][i];
    return t;
}

int** concatenate2MatricesH(int** a, int** b, int length, int width, int &lres, int &wres){
    lres = length;  wres = width*2;
    int** newMa = new int*[lres];
    for (int i = 0; i < lres; i++)
        newMa[i] = new int [wres];
    for (int i = 0; i < lres; i++){
        for (int j = 0; j < width; j++){
            newMa[i][j] = a[i][j];
            newMa[i][j+width] = b[i][j];
        }
    }
    return newMa;
}

int** concatenate2MatricesV(int** a, int** b, int length, int width, int &lres, int &wres){
    lres = length*2;  wres = width;
    int** newMa = new int*[lres];
    for (int i = 0; i < lres; i++)
        newMa[i] = new int [wres];
    for (int i = 0; i < length; i++){
        for (int j = 0; j < wres; j++){
            newMa[i][j] = a[i][j];
            newMa[i+length][j] = b[i][j];
        }
    }
    return newMa;
}

bool multiple2Matrices(int**& res, int** a, int **b, int& lengthr, int& widthr, int lengtha, int widtha, int lengthb, int widthb){
    if (widtha != lengthb)
        return false;
    else{
        lengthr = lengtha;
        widthr = widthb;
        res = new int* [lengthr];
        for (int i=0; i<lengthr; i++)
            res[i] = new int [widthr];
        for (int i = 0; i < lengthr; i++)
            for (int j = 0; j < widthr; j++){
                int result = 0;
                for (int k = 0; k < widtha; k++)
                    result = result+ a[i][k]*b[k][j];
                res[i][j] = result;
            }
        return true;
    }
}

int** findSubmatrix(int** a, int length, int width, int &lres, int &wres){
    //Giả sử đã kiểm tra tính hợp lệ của lres và wres
    int** subMa = new int* [lres];
    for (int i = 0; i < lres; i++)
        subMa[i] = new int [wres];
    int max = 0;
    int rIndex, cIndex;
    for (int i = 0; i < length - lres + 1 ; i++){
        for (int j = 0; j < width - wres + 1; j++){
            int sum = 0;
            for (int k = 0; k < lres; k++)
                for (int t = 0; t < wres; t++){
                    sum =sum + a[i+k][j+t];
                }
            if (sum > max){
                max = sum;
                rIndex = i;
                cIndex = j;
            }
        }
    }
    for (int i = 0; i < lres; i++)
        for (int j = 0; j < wres; j++)
            subMa[i][j] = a[rIndex+i][cIndex+j];
    return subMa;
}