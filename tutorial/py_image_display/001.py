import numpy as np
import cv2
################################################
#画像を読み込む
################################################

#cv2.imread()で画像を読み込む
# cv2.IMREAD_COLOR : カラー画像として読み込む．画像の透明度は無視される．デフォルト値
# cv2.IMREAD_GRAYSCALE : グレースケール画像として読み込む
# cv2.IMREAD_UNCHANGED : アルファチャンネルも含めた画像として読み込む

print("cv2.IMREAD_COLOR:", cv2.IMREAD_COLOR)
print("cv2.IMREAD_GRAYSCALE:", cv2.IMREAD_GRAYSCALE)
print("cv2.IMREAD_UNCHANGED:", cv2.IMREAD_UNCHANGED)

img = cv2.imread('../../img/hari.jpg',0)

while(True):
    cv2.imshow('image',img)
    if cv2.waitKey(1) & 0xFF == ord('q'): #waitKey：キーボード入力を処理する関数
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows() #現在までに作られた全てのウィンドウを閉じる関数

