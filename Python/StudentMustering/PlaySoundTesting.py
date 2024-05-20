from playsound import playsound
import os
import keyboard
import time

if __name__== "__main__":
    #Lấy đường dẫn trực tiếp của file input.txt
    file_path=os.path.dirname(__file__)
    file_path=file_path.replace("\\",'/') + '/Audio/'
    
    
    i = 0
    while True: 
        os.system('cls')
        
        print(i) 
        #time.sleep(1)
        
        if keyboard.is_pressed('x'):  
            print('Co Mat!')
            playsound(file_path + 'Co.mp3')
        elif keyboard.is_pressed('p'):
            print('Vang co phep!')
            playsound(file_path + 'Phep.mp3') 
        elif keyboard.is_pressed(' '):
            print('Vang')
            playsound(file_path + 'Vang.mp3')
             
        i+=1
        
        
       