import numpy as np
import cv2
################################################
#画像を圧縮
################################################

img = cv2.imread('../../img/hari.jpg',0)

cv2.imwrite('result.jpg', img)
cv2.imwrite('result_compress1.png', img,  [cv2.IMWRITE_PNG_COMPRESSION, 1])
cv2.imwrite('result_compress9.png', img,  [cv2.IMWRITE_PNG_COMPRESSION, 9])

