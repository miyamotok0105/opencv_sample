# -*- coding: utf-8 -*-
import cv2
import numpy as np

cap = cv2.VideoCapture(0)
# ret = cap.set(3, 640)
# ret = cap.set(4, 480)

# while (True):
while cap.isOpened():
    # Capture frame-by-frame
    ret, frame = cap.read()
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    edges = cv2.Canny(gray, 50, 150, apertureSize=3)
    # cv2.imwrite('houghlines5.jpg',img)
    cv2.imshow("houghlines3.jpg", frame)

    key = cv2.waitKey(1)
    if key == ord("q"):
        break

# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()

