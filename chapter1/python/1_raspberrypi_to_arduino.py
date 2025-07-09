#!/usre/bin/env python3
import serial
import time

ser = serial.Serial('/dev/ttyACM0', 115200, timeout=1.0)
time.sleep(3)
ser.reset_input_buffer()
print('Serial Ok')


try:
    while True:
        time.sleep(1)
        ser.write("Hello from Raspberry pi\n".encode('utf-8'))
        print('send message to arduino')
except KeyboardInterrupt:
    print("Close Serial communication.")
    ser.close()