#GUI: Graphical User Interface

#Thư viện Tkinter được cài đặt sẵn trong Python rồi

#Import như thế này để sử dụng được hết các hàm/lệnh của tkinter
import tkinter
from tkinter import messagebox
from tkinter.ttk import *
from tkinter import *

#1. Cửa Sổ Window:

#-Tạo cửa sổ
window = Tk()

#-Ghi tiêu đề cho cửa sổ
window.title('Ví dụ lập trình GUI với Python')

#-Chỉnh sửa kích thước cho cửa sổ
window.geometry('800x800')


#2. Label (nhãn):

#-Tạo nhãn
lbl = Label(window,text = 'Hello world!', fg = 'blue', font= ('Arial', 50))

#-Hiển thị label trên một tọa độ nào đó trong cửa sổ window
lbl.grid(column= 0, row = 0)


#3. Textbox

#-Tạo textbox:
txt = Entry(window, width= 20)

#-Hiển thị textbox:
txt.grid(column = 0, row = 1)


#4. Button:

#-Tạo button:
btn1 = Button(window, text= 'Button 1')

#-Hiển thị button:
btn1.grid(column = 0, row = 2)

#-Hàm xử lý khi bấm button:
def handleButton2():
    #Thực hiện thao tác sau khi nút được bấm (ở vd này là hiển thị Hi + những gì nhập trong textbox)
    lbl.configure(text= "Hi, " + txt.get())
    return

#Cài đặt xử lý với button
btn2 = Button(window, text = 'Button 2', command= handleButton2)
btn2.grid(column= 1, row = 2)

#5. Combobox:

#-Tạo combobox
cb = Combobox(window)

#-Gán các giá trị
cb['values'] = ('giá trị 1', 'giá trị 2', 'giá trị 3')

#-Hiển thị combobox
cb.grid(column= 0, row = 3)

#-Chọn giá trị mặc định của combobox (ở đây là giá trị 1 - vị trí 0)
cb.current(0)

#-Hàm xử lý khi bấm button:
def handleButton3():
    #Thực hiện thao tác sau khi nút được bấm (ở vd này là hiển thị Hi + lựa chọn trong combobox)
    lbl.configure(text= "Lựa chọn của bạn " + cb.get())
    return

#Cài đặt xử lý với button
btn3 = Button(window, text = 'Button 3', command= handleButton3)
btn3.grid(column= 1, row = 3)


#6. Message box
#-Hàm xử lý khi bấm button:
def handleButton4():
    #Thực hiện thao tác sau khi nút được bấm (ở vd này là hiển thị message box với nội dung Hi + lựa chọn trong combobox)
    #Title của message box, nội dung ở trong message box
    messagebox.showinfo("Message","Hi " + cb.get())
    return

#Cài đặt xử lý với button
btn4 = Button(window, text = 'Message Box', command= handleButton4)
btn4.grid(column= 0, row = 4)


#Final: Gọi hàm mainloop để cửa sổ luôn mở cho tới khi ta tự đóng nó
window.mainloop()    