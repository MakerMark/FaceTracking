import cv2
import sys
import serial

# Create an object Serial with ttymxc3 port
ser = serial.Serial(
    port='/dev/ttymxc3',
    baudrate=115200,
    parity=serial.PARITY_ODD, # Optional
    stopbits=serial.STOPBITS_ONE, # Optional
    bytesize=serial.EIGHTBITS # Optional
)
# Check if Serial is Open, close it then re-open (to avoid exception)
if ser.isOpen():
    ser.close()
ser.open()

cascPath = sys.argv[1]
faceCascade = cv2.CascadeClassifier(cascPath)

# Set video source (UDOO Camera) and resolution
video_capture = cv2.VideoCapture(7)
video_capture.set(3,320)
video_capture.set(4,240)

while True:
    # Capture frame-by-frame
    ret, frame = video_capture.read()

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = faceCascade.detectMultiScale(
        gray,
        scaleFactor=1.2,
        minNeighbors=5,
        minSize=(30, 30),
        flags=cv2.cv.CV_HAAR_SCALE_IMAGE
    )

    # Draw a rectangle around the faces
    for (x, y, w, h) in faces:
		print ("x: ",x,", y: ",y)
		prov=str(x)
		prov = prov + 'x'
		ser.write(prov)
		prov=str(y)
		prov = prov + 'x'
		ser.write(prov)
		cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)

    # Display the resulting frame
    cv2.imshow('Video', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# When everything is done, release the capture
video_capture.release()
cv2.destroyAllWindows()
