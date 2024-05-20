#include <iostream>
using namespace std;

int RecursiveBinarySearch(int* a, int left, int right, int key){
    if (right >= left){
        int mid = left + (right - left)/2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            return RecursiveBinarySearch(a,left, mid-1,key);
        else
            return RecursiveBinarySearch(a,mid+1,right,key);
    }
    return -1; 
}

int sumRecursive(int n){
    if (n==0)
        return 0;
    return (n + sumRecursive(n-1));
}

int factorial(int n){
    if (n==1)
        return 1;
    return (n*factorial(n-1));
}

int exponentiation(int x, int n){
    if (n==0)
        return 1;
    return (x*exponentiation(x,n-1));
}

int countNumberOfDigits(int n){
    if (n < 10)
        return 1;
    return(1+countNumberOfDigits(n/10));
}

bool isAllDigitsEven(int n){
    if (n < 10 && n >= 0)
        return (n%2==0);
    return (isAllDigitsEven(n%10)&&isAllDigitsEven(n/10));
}

int greatestCommonDivisor(int number1, int number2){
    if(number2 == 0)
        return number1;
    return greatestCommonDivisor(number2, number1 % number2);
}

int leastCommonMultiple(int number1, int number2){
    return ((number1 * number2)/greatestCommonDivisor(number1, number2));
}

int countNumberOfCommonDivisor(int number1, int number2){
    //Biến i dùng để tìm ước chung của 2 số bằng cách sử dụng vòng lặp chia 
    static int i = 1; 
    if (i == greatestCommonDivisor(number1,number2))
        return 1;
    i++;
    return (((number1 % i == 0)&&(number2 % i == 0)) + countNumberOfCommonDivisor(number1,number2)); 
}

int fibonacciNumber(int n){
    if (n == 0 || n == 1)
        return 1;
    return (fibonacciNumber(n-1) + fibonacciNumber(n-2));
}

//Hàm in kết quả của những hoán vị tìm được
void printResult(int n, char result[]){
    for (int i = 0; i < n; i++)
        cout << result[i];
    cout << ", ";
}

void allPossiblePermutation(int i ,int n, char charArray[], char result[], char used[]){
    // i = 0
    for (int j = 0; j < n;j++){
        if(used[j] == 0){
            result[i] = charArray[j];
            used[j] = 1;
            if (i == (n - 1))
                printResult(n,result);
            else
                allPossiblePermutation(i+1,n,charArray,result,used);
            used[j] = 0;
        }
    }
}

void decimalToBinary(int n){
    if (n < 0)
        return;
    else{
        if (n == 0)
            return;
        decimalToBinary(n/2);
        cout << n%2;
    }
}

int countDigits(int n){
    if (n < 10)
        return 1;
    return 1 + countDigits(n/10);
}

int sumEvenDigits(int n){
    if (n == 0)
        return 0;
    if (n%2 == 0)
        return n%10 + sumEvenDigits(n/10);
    return sumEvenDigits(n/10);
}

int firstDigit(int n){
    if (n < 10)
        return n;
    return firstDigit(n/10);
}

int daoNguocSo(int n, int &reverseN){
    //int reverseN = 0;
    if (n == 0)
        return reverseN;
    reverseN = reverseN*10 + n%10;
    return daoNguocSo(n/10, reverseN);
}

// ===== Recursive With 1D Array ======
int maxDigit(int n){
    if (n < 10)
        return n;
    return max(n%10,maxDigit(n/10));
}

bool isAllOdd(int n){
    if (n < 10)
        return (n%2 != 0);
    return (n%2 != 0 && isAllOdd(n/10));
}

void inputArrayR(int a[], int n){
    if (n == 0)
        return;
    inputArrayR(a,n-1);
    cout << "Nhap vao a[" << n - 1 << "]: " ;
    cin >> a[n-1];
}

void printArrayR(int a[], int n){
    if (n == 0)
        return;
    printArrayR(a,n-1);
    cout << "a[" << n - 1 << "] = " << a[n-1] << endl;
}

void printArrayReverseR(int a[], int n){
    if (n == 0)
        return;
    cout << "a[" << n - 1 << "] = " << a[n-1] << endl;
    printArrayReverseR(a,n-1);
}

int findMaxR(int a[], int n){
    if (n == 1)
        return a[0];
    return max(a[n-1],findMaxR(a,n-1));
}

bool isPrime(int n){
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            count++;
    if (count == 2)
        return true;
    else
        return false;
}

int countPrinmeR(int a[], int n){
    if (n == 1)
        return isPrime(a[0]);
    return (isPrime(a[n-1]) + countPrinmeR(a, n-1 ));
}

bool isUnique(int a[], int n, int element){
    int count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == element)
            count++;
    if (count == 1)
        return true;
    return false;
}

int ketQua2(int a[], int n){
    //Sau mỗi lần gọi đệ quy thì n = n - 1, cần dùng 1 biến nsf = n + 1
    //để giữ nguyên giá trị số lượng phần tử trong mảng ban đầu,
    //truyền nsf vào isUnique để kiểm tra 1 element có độc nhất hay không
    int nsf = n + 1;
    if (n == 1)
        return isUnique(a, nsf, a[0]);
    return isUnique(a, nsf, a[n-1]) + ketQua2(a, n-1);
}

bool isAll7DividedR(int a[], int n){
    if (n == 1)
        return (a[0] % 7 == 0);
    return (a[n-1] % 7 == 0) && isAll7DividedR(a, n-1);
}

void sapXepTangDan(int a[], int n){
    // Sắp xếp mảng 1 phần tử rồi sắp xếp mảng 2 phần tử .... cho đến mảng n phần tử
    if (n == 0)
        return;
    sapXepTangDan(a, n-1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i] < a[j])
                swap(a[i], a[j]);
}