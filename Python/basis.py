#Một số các lệnh cơ bản trong pyton
#-Comment 1 dòng: dùng #
#-Comment 1 khối: dùng 3 dấu ''' hoặc """

#===========================================================================
#1. Xuất dữ liệu: dùng print("Văn bản cần in")
#-Nếu để như trên nó tự động xuống dòng. muốn ko xuống thì cần thêm ,end=""
print("Hello ", end="")
print("World!")

#-In biến ra: print(biến)
age = 20
price = 19.95
first_name = "Hoang Quoc"
male = True
female = False
#-In nhiều biến ra nó tự động cách nhau 1 " "
print(age, price, first_name, male, female)
print(f"First Name: {first_name}")

#===========================================================================
#2. Nhập dữ liệu: dùng input("Thông báo nhập dữ liệu")
#-Gán nó vào 1 biến
#-Ép kiểu sẵn dữ liệu nhập vàom bằng các hàm int(), float(), str(), bool()

#-Tính toán với int
birth_year = int(input("Enter your birth year: "))
age = 2023 - birth_year
print("You are",age,"years old")

#-Cộng chuỗi string
family_name = "Lam"
full_name = family_name + " " + first_name
print(full_name)

#===========================================================================
#3. Các việc có thể làm với string trong python
#-string trong python là 1 object -> nó có nhiều phương thức thành phần
#*Các phương thức này ko làm thay đổi string gốc, muốn thay đổi thì cần gán lại cho string gốc
course = "python for beginners"
print(course)

#-.upper()
#-.lower()

#-.find("Ký tự/từ muốn tìm"): trả về vị trí xuất hiện đầu tiên của ký tự hoặc từ muốn tìm trong string. Nếu ko có thì trả về -1
#*Vị trí mảng hoặc string trong pyton bắt đầu từ 0
print(course.find("for"))

#-.replace("ký tự/ từ bị thay thể", "ký tự/ từ dùng để thay thế")
print(course.replace("for", "4"))

#-"string tìm" in "string gốc " Kiểm tra string tìm có xuất hiện trong string gốc hay không
#+Có thì trả về true
#+Không có trả về false
print("python" in course)

#===========================================================================
#4. Các toán tử toán học
#- "+", "-", "*", "+=", "-=", "*=", "/=" bình thường

#- Nếu dùng "/" thì là chia số thực
print(10 / 3)

#- Nếu dùng "//" thì là chia số nguyên
print(10 // 3)

#- Nếu dùng "%" thì chia lấy phần dư
print(10 % 3)

#-Nếu dùng "**" thì là phép lũy thừa
print(10 ** 3)

#*Độ ưu tiên của các toán tử như bình thường. Nhân chia trước, cộng trừ sau
#*Các toán tử so sánh (>, <, ==, !=, >=, <=) dùng như bình thường
#*Biểu thức logic dùng "and" và "or" và "not" (not kiểu như ! trong C++ á)

#===========================================================================
#5. Cấu trúc if-elif-else
temperature = 25

if temperature > 30:
    print("It's hot")
    print("Please drink plenty of water")
elif (temperature <= 30) and (temperature > 20):
    print("It's cool")
else:
    print("It's cold")
    
#===========================================================================
#5. Cấu trúc vòng lặp while
#- while(điều kiện logic đơn giản)
#* 1000 có thể viết là 1_000, không làm thay đổi giá trị. Giúp đọc code dễ hơn thôi
i = 1
while i <= 1_000:
    print(i)
    i = i + 1
    
#* Phép nhân "*" có thể nhân số cho ký tự => nhân số ký tự xuất hiện ra
i = 1
while i <= 10:
    print(i * "*")
    i = i + 1
    
#===========================================================================
#6. Kiểu dữ liệu list (khá giống array)
#-Khởi tạo
#*Vị trí phần tử đầu tiên là 0. -1 sẽ là phần tử cuối cùng. -2 sẽ là phần tử kế cuối cùng (nó quay ngược list)
names = ["Jhon", "Bob", "Mosh", "Sam", "Mary"]

#-Xuất list
#+Xuất nguyên list
print(names)

#+Xuất phần tử với vị trí mong muốn
print("0:", names[0], "1:",names[-1], "2:", names[-2])

#+Xuất một số phần tử trong khoảng mong muốn
print(names[0:3])

#-Các phương thức của list
numbers = [1,2,3,4,5]

#+.append(phần tử mới): Thêm một phần tử mới vào list
numbers.append(6)
print(numbers)

#+.insert(i, value): Thêm value vào vị trí i trong list
numbers.insert(1, 7)
numbers.insert(1, 7)
print(numbers)

#+.remove(value): Xóa giá trị value tìm thấy đầu tiên ra khỏi list
numbers.remove(7)
print(numbers)

#+Dùng tử khóa "in" để kiểm tra có một giá trị trong list hay không
print(3 in numbers)

#+Dùng từ khóa len(list) để xem có bao nhiêu phần tử trong list
print(len(numbers))

#+.clear(): xóa tất cả phần tử ra khỏi list
numbers.clear()
print(numbers)

#===========================================================================
#7. Vòng lặp for
# for <biến chạy> in <list>:
    #Làm gì đó
numbers = [1,2,3,4,5]
for item in numbers:
    #item = number[i] (Giống auto bên C++)
    print(item," ", end="")
#* print() này dùng để xuống dòng
print()

#-So sánh với vòng while:
i = 0
while i < len(numbers):
    print(numbers[i], " ", end="")
    i= i + 1
print()

#-Hàm range(stop): trả về 1 đoạn [0, stop-1]
#-Hàm range(start, stop): trả về 1 đoạn [start, stop-1]
#-Hàm range(start, stop, jump): trả về 1 đoạn [start, stop-1] với khoảng cách giữa 2 phần tử = jump
numbers_range = range(len(numbers))
for j in numbers_range:
    print(numbers[j], " ", end = "")
print()
#===========================================================================
#8. Cấu trúc tuple (bộ)
#<Tên tuple> = (bộ các phần tử)
tuple = (1,2,-1,3,3)

#-Không thể thay đổi phần tử trong tuple

#-Tuple chỉ có 2 phương thức là count(item): đếm số lần xuất hiện của item và index(item) trả về vị trí xuất hiện đầu tiên của item
print(tuple.count(3))
print(tuple.index(3))