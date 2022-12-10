from random import gauss
import cv2
import numpy as np

#1.Đọc và in ra màn ảnh 1 ảnh thông thường:
#a) Đọc ảnh gốc
#image = cv2.imread("input.jpg")
#b) Đọc ảnh gốc nhưng màu trắng đen
image = cv2.imread("input.jpg",0)

#d) Hiện ảnh đã đọc lên
#cv2.imshow("Sample", image)

#2. Làm mịn ảnh:
gaussian_image = cv2.GaussianBlur(image,(5,5), 1000)

#3. Convert ảnh làm mịn thành ảnh chỉ có đen hoặc trắng (ko còn xám)
_, thresh = cv2.threshold(gaussian_image, 8, 255, cv2.THRESH_BINARY)

#4. Đặt 2 bức ảnh gần nhau để xem khác biệt
cv2.imshow("Sample", np.hstack((image, gaussian_image)))

#5. Xem ảnh thresh
cv2.imshow("Sample2", thresh)

# Giữ lại ảnh hiện để xem
cv2.waitKey(0)

# Đóng hết các cửa sổ đang mở
cv2.destroyAllWindows()

