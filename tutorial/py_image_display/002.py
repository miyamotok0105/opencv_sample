import numpy as np
import cv2
################################################
#画像を保存する
################################################

img = cv2.imread('../../img/hari.jpg',0)
cv2.imwrite('image_save.png',img) #画像保存
cv2.destroyAllWindows() #現在までに作られた全てのウィンドウを閉じる関数

