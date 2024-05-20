#include <iostream>
#include <vector>
//vector
#include <algorithm>
//max,min
#include <numeric>
//accumulate

using namespace std;
#define MAX 100
using ll = long long;

//1. *max_element(start,end)/*min_element(start,end) Tìm phần tử lớn/ nhỏ nhất trong mảng, vector
void op1(){
    int n;
    cout << "n: ";
    cin >> n;
    //Với mảng tĩnh:
    int a[MAX];
    for (int i = 0; i < n; i++){
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
    cout << *max_element(a,a+n) << endl;
    cout << *min_element(a,a+n) << endl;
    cout << "-----------------------------------\n";

    //Với mảng vector:
    vector<int> v(n);
    //vector<int> v;
    for (int i = 0; i < n; i++){
        cout << "v[" << i << "]: ";
        cin >> v[i];
        
        // int buffer;
        // cin >> buffer;
        // v.push_back(buffer);
    }
        
    cout << *max_element(v.begin(), v.end()) << endl;
    cout << *min_element(v.begin(), v.end()) << endl;
}

//2. accumulate(start,end,init value of sum): Tính tổng phần tử trong mảng, vector
void op2(){
    int n;
    cout << "n: ";
    cin >> n;
    int sum;
    //Với mảng tĩnh:
    int a[MAX];
    for (int i = 0; i < n; i++){
        cout << "a[" << i << "]: ";
        cin >> a[i];
    }
    sum = accumulate(a,a+n,0);
    // 0 là giá trị sum khởi tạo ban đầu
    cout << sum << endl;
    cout << "-----------------------------------\n";

    //Với mảng vector:
    vector<int> v(n);
    //vector<int> v;
    for (int i = 0; i < n; i++){
        cout << "v[" << i << "]: ";
        cin >> v[i];
        
        // int buffer;
        // cin >> buffer;
        // v.push_back(buffer);
    }
    sum = accumulate(v.begin(), v.end(),0);
    cout << sum << endl;
}

//3. fill(start,end,value): Gán 1 giá trị ban đầu cho tất cả phần tử trong mảng, vector
void op3(){
    int n;
    cout << "n: ";
    cin >> n;
    int sum;
    //Với mảng tĩnh:
    int a[MAX];
    fill(a,a+n,2106);
    //fill mảng với số 2106
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n-----------------------------------\n";

    //Với mảng vector:
    vector<int> v(n);
    fill(v.begin(), v.end(),69);
    //fill mảng với số 2106
    for (int x: v)
        cout << x << " ";
    cout << endl;
}

//4.search(main array start,main arrat end, sub array start, sub array end): kiểm tra có xuất hiện mảng con liên tiếp trong mảng đã cho
//-Nếu có trả về vị trí của phần tử đầu viên của mảng con trong mảng đã cho
//-Không có thì trả vể vị trí cuối mảng đã cho
void op4(){
    int n = 5;
    int m = 3;
    int a[MAX] = {1,2,5,3,4,7};
    int b[MAX] = {2,5,3};
    if (search(a,a+n,b,b+m) != a + n)
        cout << "FOUND\n";
    else
        cout << "NOT FOUND\n";
    
    cout << "--------------------------------\n";
    vector<int> v1 = {1,2,5,3,4,7};
    vector<int> v2 = {2,5,3};
    if (search(v1.begin(), v1.end(),v2.begin(),v2.end()) != v1.end())
        cout << "FOUND\n";
    else
        cout << "NOT FOUND\n";
}

//5. binary_search(start, end, searching value): Tìm kiếm nhị phân, chỉ áp dụng cho mảng, vector đã sắp xếp
//-Nếu có trả về true, ko thì trả về false
void op5(){
    int n = 6;
    int a[MAX] = {1,2,2,3,5,7};
    if (binary_search(a,a+n,2))
         cout << "FOUND\n";
    else
        cout << "NOT FOUND\n";
    
    cout << "--------------------------------\n";
    vector<int> v = {1,2,3,4,5,7};
    if (binary_search(v.begin(), v.end(), 8))
        cout << "FOUND\n";
    else
        cout << "NOT FOUND\n";
}

//6. sort(start, end, thêm greater nếu muốn sắp giảm dần): mặc đỉnh là sắp xếp tăng dần cho 1 mảng, vector
//Thuật toán cốt lõi: intro sort (phụ thuộc vào đầu vào và trường hợp mà sử dụng inserttion sort/quick sort/heap sort)
//Độ phức tạp cho mọi TH: O(nlogn)
void op6(){
    int n = 5;
    int a[] = {1,5,3,4,2};
    sort(a,a+n);
    for (int x: a)
        cout << x << " ";
    cout << endl;
    sort(a,a+n,greater<int>());
    for (int x: a)
        cout << x << " ";
    
    cout << "\n--------------------------------\n";
    vector<int> v = {1,5,2,4,2};
    sort(v.begin(),v.end());
    for (int x: v)
        cout << x << " ";
    cout << endl;
    sort(v.begin(), v.end(),greater<int>());
    for (int x: a)
        cout << x << " ";
    cout << endl;
}

//7. reserve(start,end): đảo ngược mảng, vector, string
void op7(){
    int n = 5;
    int a[] = {1,5,3,4,2};
    reverse(a,a+n);
    for (int x: a)
        cout << x << " ";
    cout << "\n--------------------------------\n";
    vector<int> v = {1,5,2,4,2};
    reverse(v.begin(),v.end());
    for (int x: v)
        cout << x << " ";
    cout << "\n--------------------------------\n";
    string s = "Lam Hoang Quoc";
    reverse(s.begin(),s.end());
    cout << s << endl;
}

//8. for_each(start, end, function): áp dụng một hàm với các phần tử trong mảng/vector
void X2(int &x){
    x = x * 2;
}

void op8(){
    int n = 5;
    int a[] = {1,5,3,4,2};
    for_each(a,a+n,X2);
    for (int x: a)
        cout << x << " ";
    cout << "\n--------------------------------\n";
    vector<int> v = {1,5,2,4,2};
    for_each(v.begin(),v.end(),X2);
    for (int x: v)
        cout << x << " ";
    cout << endl;
}

int main(){
    
    while(1){
        system("cls");
        //op1();
        //op2();
        //op3();
        //op4();
        //op5();
        //op6();
        //op7();
        op8();
        system("pause");
    }
    return 0;
}