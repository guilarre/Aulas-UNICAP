import RPi.GPIO as GPIO
import time

# Configuração
PIEZO_PIN = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(PIEZO_PIN, GPIO.OUT)

# Criar PWM
pwm = GPIO.PWM(PIEZO_PIN, 1000)

def test_continuo():
    """Teste contínuo de som"""
    print("🔊 TESTE CONTÍNUO - 3 segundos")
    pwm.start(50)
    time.sleep(3)
    pwm.stop()

def test_frequencias():
    """Teste de diferentes frequências"""
    print("\n🎵 TESTE DE FREQUÊNCIAS")
    frequencias = [100, 250, 500, 1000, 2000, 3000, 4000]
    
    for freq in frequencias:
        print(f"Frequência: {freq}Hz")
        pwm.ChangeFrequency(freq)
        pwm.start(70)
        time.sleep(0.7)
        pwm.stop()
        time.sleep(0.3)

def test_volume():
    """Teste de diferentes níveis de volume"""
    print("\n📢 TESTE DE VOLUME")
    volumes = [30, 50, 70, 90, 100]
    
    for vol in volumes:
        print(f"Volume: {vol}%")
        pwm.ChangeFrequency(2000)
        pwm.start(vol)
        time.sleep(0.5)
        pwm.stop()
        time.sleep(0.2)

def beeps_rapidos():
    """Bips rápidos"""
    print("\n⚡ BIPS RÁPIDOS")
    for i in range(8):
        pwm.ChangeFrequency(3000)
        pwm.start(80)
        time.sleep(0.1)
        pwm.stop()
        time.sleep(0.1)

def sirene():
    """Efeito sirene"""
    print("\n🚨 EFEITO SIRENE")
    for i in range(3):
        # Subindo
        for freq in range(500, 2000, 100):
            pwm.ChangeFrequency(freq)
            pwm.start(60)
            time.sleep(0.05)
        pwm.stop()
        time.sleep(0.1)
        
        # Descendo
        for freq in range(2000, 500, -100):
            pwm.ChangeFrequency(freq)
            pwm.start(60)
            time.sleep(0.05)
        pwm.stop()
        time.sleep(0.2)

def musica_simples():
    """Música simples"""
    print("\n🎵 MÚSICA SIMPLES")
    notas = [
        (262, 0.3),   # Dó
        (294, 0.3),   # Ré
        (330, 0.3),   # Mi
        (349, 0.3),   # Fá
        (392, 0.3),   # Sol
        (440, 0.3),   # Lá
        (494, 0.3),   # Si
        (523, 0.5)    # Dó
    ]
    
    for freq, duracao in notas:
        pwm.ChangeFrequency(freq)
        pwm.start(80)
        time.sleep(duracao)
        pwm.stop()
        time.sleep(0.05)

def test_interativo():
    """Teste interativo pelo teclado"""
    print("\n🎮 MODO INTERATIVO")
    print("Pressione:")
    print("  1 - Bip curto")
    print("  2 - Bip longo") 
    print("  3 - Frequência baixa")
    print("  4 - Frequência alta")
    print("  q - Sair")
    
    while True:
        comando = input("Comando: ").strip().lower()
        
        if comando == '1':
            print("BIP CURTO")
            pwm.ChangeFrequency(2500)
            pwm.start(70)
            time.sleep(0.2)
            pwm.stop()
            
        elif comando == '2':
            print("BIP LONGO")
            pwm.ChangeFrequency(2000)
            pwm.start(70)
            time.sleep(1)
            pwm.stop()
            
        elif comando == '3':
            print("FREQUÊNCIA BAIXA (200Hz)")
            pwm.ChangeFrequency(200)
            pwm.start(70)
            time.sleep(0.8)
            pwm.stop()
            
        elif comando == '4':
            print("FREQUÊNCIA ALTA (4000Hz)")
            pwm.ChangeFrequency(4000)
            pwm.start(70)
            time.sleep(0.8)
            pwm.stop()
            
        elif comando == 'q':
            print("Saindo do modo interativo...")
            break
            
        else:
            print("Comando inválido!")

def main():
    """Função principal"""
    print("=" * 50)
    print("🔊 TESTE DE PIEZO COM RESISTOR")
    print("=" * 50)
    print("Conexão: GPIO 18 → Resistor 100Ω → Piezo(+)")
    print("         GND → Piezo(-)")
    print("=" * 50)
    
    try:
        # Executar todos os testes
        test_continuo()
        test_frequencias()
        test_volume()
        beeps_rapidos()
        sirene()
        musica_simples()
        
        # Modo interativo
        test_interativo()
        
        print("\n✅ Todos os testes concluídos!")
        
    except KeyboardInterrupt:
        print("\n\n🛑 Teste interrompido pelo usuário")
        
    except Exception as e:
        print(f"\n❌ Erro: {e}")
        
    finally:
        # Limpeza
        pwm.stop()
        GPIO.cleanup()
        print("🧹 GPIO limpo")
        print("🎯 Teste finalizado!")

# Executar o programa
if __name__ == "__main__":
    main()