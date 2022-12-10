import cv2
import numpy as np

#ẢNH LÀ 1 MA TRẬN (MẢNG 2 CHIỀU)

# Danh sách các ký tự sử dụng, theo giảm dần độ dày
CHAR_LIST = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\|()1{}[]?-_+~<>i!lI;:,\"^`'. "
#In chiều dài của 1 chuỗi:
#print(len(CHAR_LIST))

input_file = "picwish.png"

image = cv2.imread(input_file,0)
#In kiểu dữ liệu của 1 biến:
#print(type(image))

#In ảnh dưới dạng ma trận (0 là màu đen, 255 là trắng, số còn lại nằm giữa 2 màu)
#print(image)

#In ra kích thước của ảnh (cột, hàng)
#print(image.shape)

#Lưu lại kích thước của ảnh xử lý
height, width = image.shape
#print(height, width)

#(Chỉnh) Chia ảnh ra các ô nhỏ, xử lý từng ô (chia càng nhiều, ảnh càng giống). Tạo biến lưu số cột/hàng của mỗi ô
num_cols = 450
#cell_height gấp đôi cell_width

cell_width = width / num_cols
#(Chỉnh)
cell_height = cell_width*2
num_rows = int(height/cell_height)
#print(cell_height, cell_width)

#In ra ảnh nhưng trong đoạn hàng [x,y], cột trong đoạn [z,t]
#cv2.imshow("Image", image[x:y,z:t])
#cv2.imshow("Image", image[:,100:400])

#Phạm vi của 1 ô:
#- width = [j*cell_width: (j+1)*cell_width]
#- height = [j*cell_height: (j+1)*cell_height]

#Tạo file output để ghi
output = open("ouput.txt", "w")

#Lặp qua từng ô nhỏ trong ảnh để xử lý (dùng int để làm tròn số)
#Chia từng ô nhỏ ra từng ảnh con
for i in range(num_rows):
    for j in range(num_cols):
        sub_image = image[int(i*cell_height):int((i+1)*cell_height), int(j*cell_width):int((j+1)*cell_width)]
        #In file ảnh con ra
        #cv2.imwrite("{} {}.jpg".format(i,j), sub_image)
        #In giá trị trung bình pixel của ảnh con (càng nhỏ thì càng nhiều màu đen, càng lớn thì càng nhiều màu trắng)
        #print("Cell {} {}: {}".format(i,j,np.mean(sub_image)))
        #(chỉnh) Tính chỉ số ký tự sẽ lấy trong CHAR_LIST
        index = int(np.mean(sub_image)/256*len(CHAR_LIST)) 
        #Viết ký tự ở index tương ứng ảnh con vào file output
        output.write(CHAR_LIST[index])
    output.write("\n")

output.close()
print("Done!")


#cv2.waitKey(0)
#cv2.destroyAllWindows()
