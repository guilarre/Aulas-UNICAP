# import raspberry pi GPIO module
import RPi.GPIO as GPIO
import time

# Setando pra usar os pinos c numeração board
# GPIO.setmode(GPIO.BOARD)
# Ou
GPIO.setmode(GPIO.BCM)

# setup pin 3 as output
GPIO.setup(18, GPIO.OUT)

# setup pin 3 as pulse width modulation output
# frequency = 2 hz (2 times per second)
# pwm = GPIO.PWM(18, 2)

# start with 50% duty cycle
# pwm.start(50)
while True:
    GPIO.output(18, GPIO.HIGH)
    time.sleep(1)
    GPIO.output(18, GPIO.LOW)
    time.sleep(1)

GPIO.cleanup()