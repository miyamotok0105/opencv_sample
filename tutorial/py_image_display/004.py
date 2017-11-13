# -*- coding: utf-8 -*-
import numpy as np
import cv2
from matplotlib import pyplot as plt
################################################
#画素値のアクセスと変更方法
################################################

img = cv2.imread('../../img/hari.jpg')
#画素の行と列の座標を指定することで画素値にアクセスできる
px = img[100,100]
print (px)
cv2.imshow('px',px)

#BGR画像の画素値は青，緑，赤の色成分の値の配列，グレースケール画像の画素値は明るさを返す
blue = img[100,100,0]
print (blue)

img[100,100] = [255,255,255]
print (img[100,100])

#Warning Numpyは配列計算を高速におこなうために最適化されたライブラリである．そのため，画素値の取得や変更を各画素に対して行う処理は処理時間がかかってしまうので推奨されない．

img.item(10,10,2) #redにアクセス

img.itemset((10,10,2),100) #redを変更
img.item(10,10,2)



