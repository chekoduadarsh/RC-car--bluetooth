# Mechanical Assembly & Electrical Connecting

1.Assembly Track and wheel set as manual instruction.

2.Install Arduino UNO controller ,LEDs ,Buzzer,L298N motor drive module and battery on chassis.

3.Wiring all components together as circuit diagram.(In diagram,It's another motor drive module, I cannot find L298N device.)

Arduino pins to HC-06 :

0 - Rx

1 - Tx

2 - State

Arduino pins to L298N motor drive module :

10 - ENA

9 - IN1

8 - IN2

7 - IN3

6 - IN4

5 - ENB

Connect Arduino GND pin and L298N motor drive module GND.

Arduino pins to L298N motor drive module :
Connect power output to Motor A and B

Connect battery to Arduino controller and L298N drive module (can use battery up to 12V.)

Arduino pins to other parts :

Front light LED - 3

Back light LED - 4

Piezo buzzer - 12

# The Sketch Code and Android Application


1.Down load and install attached main sketch.

2.Upload sketch to Arduino controller.(Before click upload ,it's necessary to take HC-06 Bluetooth 5V. power off)

3.Open Arduino software serial monitor to see output.

Smart phone/Tablet Android application installation :

1.Use Android smart phone to install "Arduino Bluetooth RC Car" free application from Google play store.

2.Pair Bluetooth communication between smart phone and HC-06.

2.1 Scan device and pair.Password of HC-06 is "1234" from factory.

2.2 After paired ,open application and choose BT connection menu on application to connect between devices.

2.3 If communication complete,green light will appear.If communication not complete,red light will blink.Try to pair device again.

Test each functions on application to find wrong wiring or any mistakes during installation.Normally,software have been tested many times.It should not have any problems.
