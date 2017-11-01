import numpy as np
import cv2
from matplotlib import pyplot as plt
################################################
#画像を表示する
################################################

img = cv2.imread('../../img/hari.jpg',0)
plt.imshow(img)
plt.xticks([]), plt.yticks([])  # to hide tick values on X and Y axis
plt.show()


