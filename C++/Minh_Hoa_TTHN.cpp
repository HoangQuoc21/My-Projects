#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include <vector>
using namespace std;

//Hàm gotoxy để đưa con trỏ đến vị trí (x,y)
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Hàm SetColor để đổi màu
//0 - BLACK
//1 - BLUE
// 2 - GREEN
// 3 - AQUA
// 4 - RED 
// 5 - PURPLE 
// 6 - YELLOW
// 7 - WHITE
// 8 - GRAY 
// 9 - LIGHT BLUE 
// 10(A) - LIGHT GREEN 
// 11(B) - LIGHT AQUA 
// 12(C) - LIGHT RED 
// 13(D) - LIGHT PURPLE 
// 14(E) - LIGHT YELLOW
// 15(F) - LIGHT WHITE
void SetColor(WORD color){
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

int y = 0;
//Hàm đưa ra lời giải cho bài toán tòa tháp Hà Nội có n đĩa và trả về dưới dạng chuỗi
void ToaThapHN(int n, char cot_goc, char cot_trung_gian, char cot_dich, string &loi_giai){
    //Nếu chỉ còn 1 đĩa (là đĩa lớn nhất) thì chuyển đĩa đó từ cột cot_goc sang cột cot_dich
	if (n == 1){
        loi_giai.push_back(cot_goc);
        loi_giai.push_back(cot_dich);
		return;
	}

    //Lấy cột C làm trung gian. Chuyển n-1 đĩa sang cột B
	ToaThapHN(n - 1, cot_goc, cot_dich, cot_trung_gian, loi_giai);
    
    //Chuyển chiếc đĩa lớn nhất sang cột C
	ToaThapHN(1, cot_goc, cot_trung_gian, cot_dich, loi_giai);
    
    //Lấy cột A làm cột trung gian. Chuyển n-1 đĩa từ cột B sang cột C
	ToaThapHN(n - 1, cot_trung_gian, cot_goc, cot_dich, loi_giai);
}

vector<pair<int,int>> TaoToaDo(int n, char cot){
    vector<pair<int,int>> toa_do;
    if(cot == 'A'){
        for (int i = 0; i < n; i++)
            toa_do.push_back({0,i});
    }
    else if(cot == 'B'){
        for (int i = 0; i < n; i++)
            toa_do.push_back({8,i});
    }
    else if(cot == 'C'){
        for (int i = 0; i < n; i++)
            toa_do.push_back({16,i});
    }
    return toa_do;
}

void MinhHoaDiChuyen(){
    //Vị trí bắt đầu (hoành độ trước rồi tới tung độ)
    int x = 10, y = 10;
    //Nước đi
    int i = 0, j = 0;
    while(1){
        //Bắt phím được nhấn trên bàn phím
        char move;
        move = getch();

        //Xử lý phím được nhấn sẽ có nước đi kiểu gì
        if(move == 'w'){
            //Đi lên
            i = 0;
            j = -1;
        }
        else if (move == 's'){
            //Đi xuống
            i = 0; 
            j = 1;
        }
        else if (move == 'a'){
            //Đi sang trái
            i = -1;
            j = 0;
        }
        else if (move == 'd'){
            //Đi sang phải
            i = 1;
            j = 0;
        }

        //Vẽ các nước đi trên màn hình console

        //Xóa hình ảnh cũ
        system("cls");
        //Đưa con trỏ đến vị trí cũ
        gotoxy(x,y);
        //Thay đổi vị trí 
        x +=i;
        y +=j;
        //Đưa con trỏ đến vị trí mới
        gotoxy(x,y);
        cout << "Q";
        //trả con trỏ về vị trí (0,0)
        gotoxy(0,0);

        Sleep(100);
    }
}

int ViTriDiaDinh(int*cot, int n){
    //Trả về vị trí đĩa đỉnh (đĩa trên cùng/đĩa đầu tiên)
    int vi_tri;
    for (int i = 0; i < n; i++)
        if (cot[i] != 0){
            vi_tri = i;
            break;
        }
    return vi_tri;
}

int ViTriBoDia(int*cot, int n){
    //Trả về vị trí trước đĩa đỉnh
    for (int i = 0; i < n; i++)
        if (cot[i] != 0)
            return i - 1;

    //Nếu cột hiện đang không có đĩa nào thì trả về vị trí cuối
    return n - 1;
}

void DiChuyenDia(char goc, char dich, int*a, int*b, int*c, int n){
    //Di chuyển đĩa ở vị trí x của cột gốc đến vị trí y của cột đích
    int x,y;
    if (goc == 'A'){
        if (dich == 'B'){
            // A --> B
            x = ViTriDiaDinh(a,n);
            y = ViTriBoDia(b,n);
            swap(a[x],b[y]);
        }
        else if (dich == 'C'){
            // A --> C
            x = ViTriDiaDinh(a,n);
            y = ViTriBoDia(c,n);
            swap(a[x],c[y]);
        }
    }
    else if (goc == 'B'){
        if (dich == 'A'){
            // B --> A
            x = ViTriDiaDinh(b,n);
            y = ViTriBoDia(a,n);
            swap(b[x],a[y]);
        }
        else if (dich == 'C'){
            // B --> C
            x = ViTriDiaDinh(b,n);
            y = ViTriBoDia(c,n);
            swap(b[x],c[y]);
        }
    }
    else if (goc == 'C'){
        if (dich == 'A'){
            // C --> A
            x = ViTriDiaDinh(c,n);
            y = ViTriBoDia(a,n);
            swap(c[x],a[y]);
        }
        else if (dich == 'B'){
            // C --> B
            x = ViTriDiaDinh(c,n);
            y = ViTriBoDia(b,n);
            swap(c[x],b[y]);
        }
    }
}

int main(){
    int n;
    string loi_giai;
    char cot_goc = 'A', cot_trung_gian = 'B', cot_dich = 'C';
    int *cot_dia_goc;
    int* cot_dia_trung_gian;
    int* cot_dia_dich;
    int k1,k2;
    while(1){
        //Xuất thông tin chương trình
        system("cls");
        cout << "==================================================\n";
        cout << "=          MINH HOA BAI TOAN TOA THAP HA NOI     =\n";
        cout << "==================================================\n";
        cout << "*Luu y:\n";
        cout << "-Cac dia di chuyen tu cot \"A\" sang cot \"C\".\n";
        cout << "-Moi dia se duoc bieu dien boi mot so tuong ung do lon cua no.\n";
        cout << "-\"0\" co nghia la khong co dia nao o vi tri nay.\n";
        cout << "--------------------------------------------------\n";
        cout << "Hay nhap vao so dia (nhap 0 de thoat): ";
        
        //Kiểm tra n 
        cin >> n;
        if (n == 0)
            break;
        
        //Tạo các cột và thêm giá trị của từng cột
        cot_dia_goc = new int[n];
        for (int i = 0; i < n; i++)
            cot_dia_goc[i] = i + 1;

        cot_dia_trung_gian = new int[n];
        for (int i = 0; i < n; i++)
            cot_dia_trung_gian[i] = 0;

        cot_dia_dich = new int[n];
        for (int i = 0; i < n; i++)
            cot_dia_dich[i] = 0;
        
        //Tìm lời giải cho BTTHN với n đĩa
        ToaThapHN(n, cot_goc, cot_trung_gian, cot_dich,loi_giai);

        //k1 và k2 để lấy vị trí của từng cặp cột gốc và cột đích trong lời giải
        k1 = 0;
        k2 = 1;
        //Cần 2^n - 1 bước để giải BTTHN, lặp 2^n lần vì còn hình ảnh đầu tiên (chưa giải gì) của bài toán
        for (int i = 1; i <= pow(2,n); i++){
            system("cls");
            cout << "==================================================\n";
            cout << "=          MINH HOA BAI TOAN TOA THAP HA NOI     =\n";
            cout << "==================================================\n";
            cout << "-So dia: " << n << endl;
            cout << "--------------------------------------------------\n";

            //In giá trị trong các cột và tên cột ra
            for (int j = 0; j < n; j++){
                cout << "\t\t" << cot_dia_goc[j] << "\t" << cot_dia_trung_gian[j] << "\t" << cot_dia_dich[j] << endl;
            }
            
            SetColor(4);
            cout << "\t\t-\t";
            SetColor(6);
            cout << "-\t";
            SetColor(2);
            cout << "-\n";

            SetColor(4);
            cout << "\t\t" << cot_goc << "\t";
            SetColor(6);
            cout << cot_trung_gian << "\t";
            SetColor(2);
            cout << cot_dich << endl;

            //Dùng lệnh Sleep để giảm thời gian nhảy giữa các hình ảnh, giúp quan sát ổn hơn
            SetColor(7);
            Sleep(1000);

            //Di chuyển 1 đĩa theo từng cặp cột gốc và cột đích
            DiChuyenDia(loi_giai[k1],loi_giai[k2],cot_dia_goc,cot_dia_trung_gian,cot_dia_dich,n);
            k1+=2;
            k2+=2;
        }

        //Giải phóng bộ nhớ/ Xóa dữ liệu để tái sử dụng chương trình
        delete[] cot_dia_goc;
        delete[] cot_dia_trung_gian;
        delete[] cot_dia_dich;
        loi_giai.clear();
        system("pause");
    }
    return 0;
}