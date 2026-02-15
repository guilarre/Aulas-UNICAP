# Experimento do semáforo (3 leds em sequência)
import RPi.GPIO as GPIO
import time

# Setando pra usar os pinos c numeração board
# GPIO.setmode(GPIO.BOARD)
# Ou
GPIO.setmode(GPIO.BCM)

# setup pins 14, 15, 18 as output
GPIO.setup(14, GPIO.OUT)
GPIO.setup(15, GPIO.OUT)
GPIO.setup(18, GPIO.OUT)

try:
    while True:
        GPIO.output(14, GPIO.HIGH)
        time.sleep(1)
        GPIO.output(14, GPIO.LOW)
        GPIO.output(15, GPIO.HIGH)
        time.sleep(1)
        GPIO.output(15, GPIO.LOW)
        GPIO.output(18, GPIO.HIGH)
        time.sleep(1)
        GPIO.output(18, GPIO.LOW)
except KeyboardInterrupt:
    print("\nInterrompido pelo usuário\n")
finally:
    GPIO.cleanup()