import os
import numpy as np
import cv2
import glob

#macのfourccオプション
#https://gist.github.com/takuma7/44f9ecb028ff00e2132e

# files = os.listdir('videos/*.jpg')
files = glob.glob('videos/*.jpg') # ワイルドカードが使用可能
 
class video_write():
    def __init__(self):
        self.fourcc = cv2.VideoWriter_fourcc('m', 'p', '4', 'v')
        self.out = cv2.VideoWriter('videos_.mp4',self.fourcc, 2220.0, (640,480))

    def end(self):
        self.out.release()
        cv2.destroyAllWindows()


    def add_frame(self, frame):        
        print(frame.shape)
        # gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        # frame = del_mozaik(frame)
        # cv2.imshow('frame',frame)
        self.out.write(frame)

vw = video_write()

for file in files:
    print(file)
    img = cv2.imread(file)
    vw.add_frame(img)
vw.end()



