from pyetherscan import Client

client = Client()
address = '0x1c7dde76a6372af2e2cf51cc6dafcf48623a9040'


from time import sleep
import serial
ser = serial.Serial("COM3", 9600) # Establish the connection on a specific port
counter = 0
while True:
    counter += 1
    print("Reading: ", counter)

    address_balance = client.get_single_balance(address)
    print ("Status Code: ", address_balance.response_status_code)
    print ("Satus: ", address_balance.message)
    balance = address_balance.balance
    print("Balance: ", balance)

    signal = 0

    if balance >= 1e17:
        signal = 1
    if balance >= 2e17:
        signal = 2
    if balance >= 3e17:
        signal = 3
    if balance >= 4e17:
        signal = 4
    if balance >= 5e17:
        signal = 5

    print("Signal: ", signal)
    ser.write(str(signal).encode()) # Convert the decimal number to ASCII then send it to the Arduino
    print("reading line...")
    print(ser.readline()) # Read the newest output from the Arduino
    print(" ")
    sleep(1) # Delay for one tenth of a second
