import RPi.GPIO as GPIO
import time

# Configuração
BUZZER_PIN = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(BUZZER_PIN, GPIO.OUT)

# Criar objeto PWM (frequência de 1000Hz é comum para buzzers)
pwm = GPIO.PWM(BUZZER_PIN, 1000)

try:
    print("Testando buzzer...")
    
    # Ligar o buzzer com 50% de duty cycle
    pwm.start(50)
    print("Buzzer LIGADO")
    time.sleep(1)
    
    # Desligar o buzzer
    pwm.stop()
    print("Buzzer DESLIGADO")
    time.sleep(1)
    
    # Teste com diferentes frequências
    print("Testando frequências...")
    frequencies = [262, 330, 392, 523]  # Dó, Mi, Sol, Dó (oitava superior)
    
    for freq in frequencies:
        pwm.ChangeFrequency(freq)
        pwm.start(50)
        time.sleep(0.5)
        pwm.stop()
        time.sleep(0.2)
    
    print("Teste concluído!")

except KeyboardInterrupt:
    print("\nTeste interrompido pelo usuário")

finally:
    pwm.stop()
    GPIO.cleanup()