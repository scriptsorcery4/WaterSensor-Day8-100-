import serial
import time

# Setup the serial connection to the Arduino
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=.1)

def read_sensor_value():
    data = arduino.readline()  # Read a line from the serial port
    if data:
        try:
            sensor_value = int(data)  # Convert the data to an integer
            return sensor_value
        except ValueError:
            print("Received non-integer value: ", data)
    return None

while True:
    sensor_value = read_sensor_value()
    if sensor_value is not None:
        print("Water Sensor Value:", sensor_value)
    time.sleep(0.2)  # Wait for a second before reading again
