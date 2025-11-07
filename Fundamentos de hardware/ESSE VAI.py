# 5V Raspberry Pi → VCC Buzzer
# GPIO18 → 1kΩ → Base Transistor
# Coletor Transistor → IO Buzzer
# Emissor Transistor → GND
# IO Buzzer → 220Ω → GND
# GND Buzzer → GND Raspberry Pi

import RPi.GPIO as GPIO
import time
import threading

# Configurações
BUZZER_PIN = 18  # GPIO usado para controlar o buzzer
GPIO.setmode(GPIO.BCM)
GPIO.setup(BUZZER_PIN, GPIO.OUT)

buzzer = GPIO.PWM(BUZZER_PIN, 440)  # frequência inicial
buzzer.start(0)

# Variáveis globais
current_song_index = 0
songs_playing = True
change_song = False

def beep(freq, duration):
    buzzer.ChangeFrequency(freq)
    buzzer.ChangeDutyCycle(50)
    time.sleep(duration * 0.9)
    buzzer.ChangeDutyCycle(0)
    time.sleep(duration * 0.1)

# Notas musicais (Hz)
notes = {
    'B0': 31, 'C1': 33, 'CS1': 35, 'D1': 37, 'DS1': 39,
    'E1': 41, 'F1': 44, 'FS1': 46, 'G1': 49, 'GS1': 52,
    'A1': 55, 'AS1': 58, 'B1': 62, 'C2': 65, 'CS2': 69,
    'D2': 73, 'DS2': 78, 'E2': 82, 'F2': 87, 'FS2': 93,
    'G2': 98, 'GS2': 104, 'A2': 110, 'AS2': 117, 'B2': 123,
    'C3': 131, 'CS3': 139, 'D3': 147, 'DS3': 156, 'E3': 165,
    'F3': 175, 'FS3': 185, 'G3': 196, 'GS3': 208, 'A3': 220,
    'AS3': 233, 'B3': 247, 'C4': 262, 'CS4': 277, 'D4': 294,
    'DS4': 311, 'E4': 330, 'F4': 349, 'FS4': 370, 'G4': 392,
    'GS4': 415, 'A4': 440, 'AS4': 466, 'B4': 494, 'C5': 523,
    'CS5': 554, 'D5': 587, 'DS5': 622, 'E5': 659, 'F5': 698,
    'FS5': 740, 'G5': 784, 'GS5': 831, 'A5': 880, 'AS5': 932,
    'B5': 988, 'C6': 1047, 'CS6': 1109, 'D6': 1175, 'DS6': 1245,
    'E6': 1319, 'F6': 1397, 'FS6': 1480, 'G6': 1568, 'GS6': 1661,
    'A6': 1760, 'AS6': 1865, 'B6': 1976, 'C7': 2093, 'CS7': 2217,
    'D7': 2349, 'DS7': 2489, 'E7': 2637, 'F7': 2794, 'FS7': 2960,
    'G7': 3136, 'GS7': 3322, 'A7': 3520, 'AS7': 3729, 'B7': 3951,
    'C8': 4186
}

# Música Super Mario Theme (versão reduzida)
mario = [
    ('E7', 0.12), ('E7', 0.12), (0, 0.12), ('E7', 0.12),
    (0, 0.12), ('C7', 0.12), ('E7', 0.12), (0, 0.12),
    ('G7', 0.12), (0, 0.36), ('G6', 0.12), (0, 0.36),
    ('C7', 0.12), (0, 0.24), ('G6', 0.12), (0, 0.24),
]

# Música Zelda - Main Theme
zelda = [
    # Introdução
    ('A4', 0.4), ('D5', 0.4), ('F5', 0.4), ('A5', 0.8),
    (0, 0.2), ('A5', 0.4), ('G5', 0.4), ('F5', 0.4),
    
    # Melodia principal
    ('E5', 0.6), ('D5', 0.6), ('F5', 0.4), ('E5', 0.4),
    ('D5', 0.4), ('C5', 0.4), ('E5', 0.4), ('D5', 0.4),
    
    ('C5', 0.4), ('A4', 0.4), ('D5', 0.8), (0, 0.4),
    
    ('A4', 0.4), ('D5', 0.4), ('F5', 0.4), ('A5', 0.8),
    (0, 0.2), ('A5', 0.4), ('G5', 0.4), ('F5', 0.4),
    
    ('E5', 0.6), ('D5', 0.6), ('F5', 0.4), ('E5', 0.4),
    ('D5', 0.4), ('C5', 0.4), ('E5', 0.4), ('D5', 0.4),
    
    ('C5', 0.4), ('A4', 0.4), ('D5', 1.0), (0, 0.4),
    
    # Ponte
    ('F5', 0.3), ('E5', 0.3), ('D5', 0.3), ('C5', 0.3),
    ('D5', 0.6), (0, 0.2),
    
    ('F5', 0.3), ('E5', 0.3), ('D5', 0.3), ('C5', 0.3),
    ('A4', 0.6), (0, 0.2),
]

# Pokémon Theme - "Gotta Catch 'Em All"
pokemon = [
    # "I wanna be the very best"
    ('G4', 0.3), ('G4', 0.3), ('G4', 0.3), ('E4', 0.6),
    ('G4', 0.6), ('E4', 0.3), ('G4', 0.9),
    
    # "Like no one ever was"
    ('G4', 0.3), ('G4', 0.3), ('G4', 0.3), ('E4', 0.6),
    ('G4', 0.6), ('E4', 0.3), ('C4', 0.9),
    
    # "To catch them is my real test"
    ('C5', 0.3), ('C5', 0.3), ('C5', 0.3), ('A4', 0.6),
    ('C5', 0.6), ('A4', 0.3), ('F4', 0.9),
    
    # "To train them is my cause"
    ('F4', 0.3), ('F4', 0.3), ('F4', 0.3), ('D4', 0.6),
    ('F4', 0.6), ('D4', 0.3), ('G4', 0.9),
    
    # "I will travel across the land"
    ('G4', 0.3), ('G4', 0.3), ('G4', 0.3), ('E4', 0.6),
    ('G4', 0.6), ('E4', 0.3), ('G4', 0.9),
    
    # "Searching far and wide"
    ('G4', 0.3), ('G4', 0.3), ('G4', 0.3), ('E4', 0.6),
    ('G4', 0.6), ('E4', 0.3), ('C4', 0.9),
    
    # Refrão "Pokémon!"
    ('C5', 0.4), ('D5', 0.4), ('E5', 0.4), ('C5', 0.4),
    ('E5', 0.8), (0, 0.2),
    
    ('C5', 0.4), ('D5', 0.4), ('E5', 0.4), ('C5', 0.4),
    ('G4', 0.8), (0, 0.2),
]

# Mortal Kombat Theme
mortal_kombat = [
    # Intro icônica
    ('D2', 0.2), (0, 0.1), ('D2', 0.2), (0, 0.1),
    ('D2', 0.2), (0, 0.1), ('D2', 0.2), (0, 0.1),
    
    # Melodia principal
    ('D3', 0.3), ('F3', 0.3), ('G3', 0.6),
    ('D3', 0.3), ('F3', 0.3), ('G3', 0.6),
    
    ('D3', 0.3), ('F3', 0.3), ('G3', 0.3), ('F3', 0.3),
    ('D3', 0.6), (0, 0.2),
    
    ('G2', 0.3), ('AS2', 0.3), ('C3', 0.6),
    ('G2', 0.3), ('AS2', 0.3), ('C3', 0.6),
    
    ('G2', 0.3), ('AS2', 0.3), ('C3', 0.3), ('AS2', 0.3),
    ('G2', 0.6), (0, 0.2),
    
    # Segunda parte
    ('D3', 0.2), ('D3', 0.2), ('D3', 0.2), ('D3', 0.2),
    ('F3', 0.2), ('F3', 0.2), ('F3', 0.2), ('F3', 0.2),
    
    ('G3', 0.4), (0, 0.1), ('G3', 0.4), (0, 0.1),
    ('G3', 0.4), (0, 0.1), ('G3', 0.4), (0, 0.1),
    
    # Final
    ('D3', 0.2), ('F3', 0.2), ('G3', 0.4),
    ('D3', 0.2), ('F3', 0.2), ('G3', 0.4),
    ('D3', 0.2), ('F3', 0.2), ('G3', 0.2), ('F3', 0.2),
    ('D3', 0.8), (0, 0.4),
]

# Música Super Mario Underwater
underwater = [
    ('C4', 0.2), ('D4', 0.2), ('E4', 0.2), ('F4', 0.2),
    ('G4', 0.4), (0, 0.1), ('G4', 0.4), (0, 0.1),
    
    ('E4', 0.2), ('F4', 0.2), ('G4', 0.2), ('A4', 0.2),
    ('B4', 0.4), (0, 0.1), ('B4', 0.4), (0, 0.1),
    
    ('G4', 0.2), ('A4', 0.2), ('B4', 0.2), ('C5', 0.2),
    ('D5', 0.6), (0, 0.2),
]

# Música Super Mario Overworld
overworld = [
    ('E5', 0.15), ('E5', 0.15), (0, 0.15), ('E5', 0.15),
    (0, 0.15), ('C5', 0.15), ('E5', 0.15), (0, 0.15),
    ('G5', 0.15), (0, 0.3), ('G4', 0.15), (0, 0.3),
    
    ('C5', 0.15), (0, 0.3), ('G4', 0.15), (0, 0.3),
    ('E4', 0.15), (0, 0.3),
    
    ('A4', 0.15), (0, 0.15), ('B4', 0.15), (0, 0.15),
    ('AS4', 0.15), ('A4', 0.15),
]

# Lista de músicas disponíveis
songs = [
    ("Super Mario Theme", mario),
    ("Zelda Main Theme", zelda),
    ("Pokémon Theme", pokemon),
    ("Mortal Kombat", mortal_kombat),
    ("Mario Underwater", underwater),
    ("Mario Overworld", overworld)
]

def keyboard_listener():
    """Escuta por entrada do teclado em uma thread separada"""
    global change_song, songs_playing
    while songs_playing:
        try:
            input()  # Espera por Enter
            change_song = True
            print("Trocar de música detectado!")
        except:
            break

def play_song(song_index):
    """Toca a música especificada pelo índice"""
    global change_song
    song_name, song_notes = songs[song_index]
    print(f"🎵 Tocando: {song_name}")
    print("Pressione ENTER para trocar de música")
    
    for note, duration in song_notes:
        if change_song:
            change_song = False
            return True  # Indica que queremos trocar de música
            
        if note == 0:
            # Para pausas, verificamos mais frequentemente por input
            elapsed = 0
            step = 0.05
            while elapsed < duration:
                if change_song:
                    change_song = False
                    return True
                time.sleep(min(step, duration - elapsed))
                elapsed += step
        else:
            beep(notes[note], duration)
    
    return False  # Música terminou naturalmente

try:
    print("🎶 CONTROLE DO BUZZER MUSICAL 🎶")
    print("================================")
    print("Músicas disponíveis:")
    for i, (name, _) in enumerate(songs):
        print(f"  {i+1}. {name}")
    print("\nPressione ENTER para trocar de música")
    print("Pressione CTRL+C para sair")
    print()
    
    # Inicia a thread que escuta o teclado
    keyboard_thread = threading.Thread(target=keyboard_listener, daemon=True)
    keyboard_thread.start()
    
    while True:
        # Toca a música atual
        song_changed = play_song(current_song_index)
        
        if song_changed:
            # Avança para próxima música
            current_song_index = (current_song_index + 1) % len(songs)
            print(f"\n🔄 Próxima música: {songs[current_song_index][0]}")
        else:
            # Música terminou naturalmente, vai para próxima
            current_song_index = (current_song_index + 1) % len(songs)
            print(f"\n⏭️  Próxima música: {songs[current_song_index][0]}")
            time.sleep(1)  # Pequena pausa entre músicas

except KeyboardInterrupt:
    print("\n\n👋 Programa encerrado pelo usuário")
    songs_playing = False
finally:
    songs_playing = False
    buzzer.stop()
    GPIO.cleanup()
    print("GPIO limpo. Até mais!")