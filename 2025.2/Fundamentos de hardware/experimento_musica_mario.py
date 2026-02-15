import RPi.GPIO as GPIO
import time

# Configuração
BUZZER_PIN = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(BUZZER_PIN, GPIO.OUT)

pwm = GPIO.PWM(BUZZER_PIN, 500)

# NOTAS CORRIGIDAS - baseadas em 500Hz como referência
E5 = 659   # Mi
C5 = 523   # Dó
G5 = 784   # Sol
E4 = 330   # Mi (mais baixo)
A4 = 440   # Lá ✅ CORRETO
B4 = 494   # Si
F5 = 698   # Fá
D5 = 587   # Ré
G4 = 392   # Sol (mais baixo)

# Música do Mario - CORRIGIDA
mario_notes = [
    (E5, 0.15), (E5, 0.15), (0, 0.15), (E5, 0.15), (0, 0.15), (C5, 0.15), (E5, 0.15), (0, 0.15),
    (G5, 0.15), (0, 0.30), (G4, 0.15), (0, 0.30),
    
    (C5, 0.15), (0, 0.15), (G4, 0.15), (0, 0.15), (E4, 0.15), (0, 0.15),
    (A4, 0.15), (0, 0.15), (B4, 0.15), (0, 0.15), (A4, 0.15), (0, 0.15), (G4, 0.20),  # ✅ A4 CORRETO
    (E5, 0.20), (G5, 0.20), (A4, 0.15), (0, 0.15), (F5, 0.15), (G5, 0.15), (0, 0.15),  # ✅ A4 CORRETO
    (E5, 0.15), (0, 0.15), (C5, 0.15), (D5, 0.15), (B4, 0.15), (0, 0.20),
    
    (C5, 0.15), (0, 0.15), (G4, 0.15), (0, 0.15), (E4, 0.15), (0, 0.15),
    (A4, 0.15), (0, 0.15), (B4, 0.15), (0, 0.15), (A4, 0.15), (0, 0.15), (G4, 0.20),  # ✅ A4 CORRETO
    (E5, 0.20), (G5, 0.20), (A4, 0.15), (0, 0.15), (F5, 0.15), (G5, 0.15), (0, 0.15),  # ✅ A4 CORRETO
    (E5, 0.15), (0, 0.15), (C5, 0.15), (D5, 0.15), (B4, 0.15), (0, 0.30)
]

def play_note(frequency, duration):
    """Tocar uma nota específica"""
    if frequency == 0:  # Pausa
        pwm.stop()
        time.sleep(duration)
    else:
        pwm.ChangeFrequency(frequency)
        pwm.start(70)
        time.sleep(duration)
        pwm.stop()
        time.sleep(0.02)

def play_mario():
    """Tocar a música completa do Mario CORRIGIDA"""
    print("🎵 Tocando Música do Mario (NOTAS CORRETAS)! 🎵")
    
    for i, (note, duration) in enumerate(mario_notes):
        play_note(note, duration)
    
    print("🏁 Música concluída!")

try:
    print("Preparando para tocar Mario com notas CORRETAS...")
    time.sleep(1)
    
    play_mario()

except KeyboardInterrupt:
    print("\n⏹️ Música interrompida")

finally:
    pwm.stop()
    GPIO.cleanup()