from tkinter import *
from tkinter.ttk import *
from tkinter import messagebox
import tkinter
import cv2
import PIL.Image, PIL.ImageTk
import time
from threading import Thread

window = Tk()
window.title('Tkinter OpenCV')

video = cv2.VideoCapture(0)
canvas_w = video.get(cv2.CAP_PROP_FRAME_WIDTH)
canvas_h = video.get(cv2.CAP_PROP_FRAME_HEIGHT)

canvas = Canvas(window, width= canvas_w, height= canvas_h, bg = 'red')
canvas.pack()

bw = 0

def handleButton():
    global bw
    bw = 1 - bw
    
button = Button(window, text = 'Black & White', command= handleButton)
button.pack()


def send_to_server():
    global button
    time.sleep(2)
    button.configure(text = "Server Received")
    return

photo = None
count = 0


def update_frame():
    global canvas, photo, count
    #Đọc từ camera
    ret, frame = video.read()
    #Resize
    frame = cv2.resize(frame, dsize= None, fx=0.5,fy=0.5)
    #Chuyển hệ màu
    if bw == 0:
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
    elif bw == 1:
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    #Convert hàm imageTK
    photo = PIL.ImageTk.PhotoImage(image= PIL.Image.fromarray(frame))
    #Show
    canvas.create_image(0,0,image = photo, anchor = tkinter.NW)
    #Gửi ảnh mỗi 10 lần
    count = count + 1
    if count % 10 == 0:
        #send_to_server()
        #Sử dụng đa luồng, làm ko gián đoạn đến interface chính
        thread = Thread(target= send_to_server)
        thread.start()
    #Cập nhật, lại lại quá trình trên liên tục
    window.after(15,update_frame)
    

update_frame()

window.mainloop()