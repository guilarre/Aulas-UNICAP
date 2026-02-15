# Experimento buzzer/botão
import RPi.GPIO as GPIO
import time

# Setando pra usar os pinos c numeração board
# GPIO.setmode(GPIO.BOARD)
# Ou
GPIO.setmode(GPIO.BCM)

# setup pins BCM 14, 15 as output
BUZZER = 14
BUTTON = 15

GPIO.setup(BUZZER, GPIO.OUT)
GPIO.setup(BUTTON, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

try:
    while True:
        if GPIO.input(BUTTON) == GPIO.HIGH:
            GPIO.output(BUZZER, GPIO.HIGH)
        else:
            GPIO.output(BUZZER, GPIO.LOW)
        time.sleep(0.05)
except KeyboardInterrupt:
    print("\nInterrompido pelo usuário\n")
finally:
    GPIO.cleanup()