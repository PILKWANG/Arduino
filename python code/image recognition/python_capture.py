import cv2 #opencv 라이브러리 갖고 오기.

CAM_ID = 0  # 사용할 캠 선택

def capture(camid=CAM_ID):
    cam = cv2.VideoCapture(camid)
    if cam.isOpened() == False:
        print('cant open the cam (%d)' % camid)
        return None

    ret, frame = cam.read()
    if frame is None:
        print('frame is not exist')
        return None

    cv2.imwrite('test_photo2.jpg', frame, params=[cv2.IMWRITE_JPEG_QUALITY, 100])
    cam.release()


if __name__ == '__main__':
    capture()