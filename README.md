# Fire-Fighting-Robot-V1 ( https://sites.google.com/view/rhythmshah/fire-fighting-robot-v1?authuser=0 )

**Components Required:**
1. Robot Chasis
2. Arduino Mega
3. L298n motor driver
4. 4 gear motors with wheels
5. Ultrasonic Sensor
6. 2 Sg90 Servo motors
7. 3 Flame sensors
8. Sim800l gsm module with Sim Card
9. 5v 1 channel Relay module
10. 5v submersible pump with Water tube
11. Water Container
12. 12v Power Supply

**Working-**

The main brain of this project is Arduino UNO/Mega depending upon applicating features. In my case, I‘m using the gsm module as features are more all pins of Arduino UNO are full so Arduino mega is used. But I cannot find 2g sim card anywhere so without 2g sim card, the alert message feature is useless so without the SMS feature Arduino UNO can be used. L298n motor driver is used to run the 4 motors of the robot. L293d motor driver shield has only some pins left for Arduino so here l298n is used rather than l293d for efficient use of all pins. 2 motors of two directions (left, right) are connected parallelly to run all 4 motors. Relay of 5v 1 channel is used to on/off the pump for water flow, for that 9v battery is used. The ultrasonic sensor is used to detect obstacles, with that two servo motors are used one for the obstacle to detecting an obstacle in both directions and the other is for water tube moves up and down. 3 flame sensors are used to detect fire in all 3 directions à left, center, right out of which the center should be of 4 pins so that the fourth pin is of analog pin used to calculate the distance of fire from the robot. Gsm 800l module is used with 2g sim card properly inserted and connected according to the circuit diagram. Arduino IDE software is used to write and upload the code to Arduino. 
