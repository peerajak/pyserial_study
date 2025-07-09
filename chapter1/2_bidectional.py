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
        print('send message to arduino')
        ser.write("Hello from Raspberry pi\n".encode('utf-8'))
        while ser.in_waiting <= 0:
            print(ser.in_waiting)
            time.sleep(0.01)
            print(ser.in_waiting)
        response = ser.readline().decode('utf-8').rstrip()
        print("response from arduino:" + response)

        
except KeyboardInterrupt:
    print("Close Serial communication.")
    ser.close()