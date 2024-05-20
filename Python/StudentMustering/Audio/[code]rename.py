import os

#Lấy đường dẫn trực tiếp của thư mục đang làm việc
file_path=os.path.dirname(__file__)
file_path=file_path.replace("\\",'/') + "/"


	
	
	
   
		
if __name__ == "__main__":
    for i in range(1,25+1):
        src = file_path + 'mp3-output-ttsfree(dot)com (' + str(i) + ').mp3'
        des = file_path + str(i+123) + '.mp3'
        
        #Đổi tên
        os.rename(src,des)