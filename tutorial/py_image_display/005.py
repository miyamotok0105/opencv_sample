# -*- coding: utf-8 -*-
import numpy as np
import cv2
from matplotlib import pyplot as plt
################################################
#画像中の注目領域(ROI)
################################################

img = cv2.imread('../../img/hari.jpg')
print(img.shape)
img_crop = img[100:200, 100:200]
img[0:100, 0:100] = img_crop

while(True):
    cv2.imshow('image',img)
    if cv2.waitKey(1) & 0xFF == ord('q'): #waitKey：キーボード入力を処理する関数
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows() #現在までに作られた全てのウィンドウを閉じる関数

