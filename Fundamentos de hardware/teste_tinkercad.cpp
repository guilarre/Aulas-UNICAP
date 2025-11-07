const int buzzerControlPin = 7;  // Pino que controla a base do transistor

void setup() {
    pinMode(buzzerControlPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // Tons
    #define B0 23
    #define C1 25
    #define CS1 26
    #define D1 28
    #define DS1 30

    #define E1 31
    #define F1 34
    #define FS1 35
    #define G1 37
    #define GS1 39

    #define A1 41
    #define AS1 44
    #define B1 46
    #define C2 49
    #define CS2 52

    #define D2 55
    #define DS2 58
    #define E2 62
    #define F2 65
    #define FS2 69

    #define G2 73
    #define GS2 78
    #define A2 82
    #define AS2 87
    #define B2 93

    #define C3 98
    #define CS3 104
    #define D3 110
    #define DS3 117
    #define E3 123

    #define F3 131
    #define FS3 139
    #define G3 147
    #define GS3 156
    #define A3 165

    #define AS3 175
    #define B3 185
    #define C4 196
    #define CS4 208
    #define D4 220

    #define DS4 233
    #define E4 247
    #define F4 262
    #define FS4 277
    #define G4 294

    #define GS4 311
    #define A4 330
    #define AS4 349
    #define B4 370
    #define C5 392

    #define CS5 415
    #define D5 440
    #define DS5 466
    #define E5 494
    #define F5 523

    #define FS5 554
    #define G5 587
    #define GS5 622
    #define A5 659
    #define AS5 698

    #define B5 740
    #define C6 784
    #define CS6 831
    #define D6 880
    #define DS6 932

    #define E6 988
    #define F6 1047
    #define FS6 1109
    #define G6 1175
    #define GS6 1245

    #define A6 1319
    #define AS6 1397
    #define B6 1480
    #define C7 1568
    #define CS7 1661

    #define D7 1760
    #define DS7 1865
    #define E7 1976
    #define F7 2093
    #define FS7 2217

    #define G7 2349
    #define GS7 2489
    #define A7 2637
    #define AS7 2794
    #define B7 2960

    #define C8 3136
    #define CS8 3322
    #define D8 3520
    #define DS8 3729

    // Introdução
    tone(buzzerControlPin, E7);
    delay(120);
    tone(buzzerControlPin, E7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, E7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, C7);
    delay(120);
    tone(buzzerControlPin, E7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, G7);
    delay(120);
    noTone(buzzerControlPin);
    delay(360);
    tone(buzzerControlPin, G6);
    delay(120);
    noTone(buzzerControlPin);
    delay(360);
            
    // Primeira seção
    tone(buzzerControlPin, C7);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
    tone(buzzerControlPin, G6);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
    tone(buzzerControlPin, E6);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
    tone(buzzerControlPin, A6);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, B6);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, AS6);
    delay(120);
    tone(buzzerControlPin, A6);
    delay(120);
        
    tone(buzzerControlPin, G6);
    delay(180);
    tone(buzzerControlPin, E7);
    delay(180);
    tone(buzzerControlPin, G7);
    delay(180);
    tone(buzzerControlPin, A7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, F7);
    delay(120);
    tone(buzzerControlPin, G7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, E7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, C7);
    delay(120);
    tone(buzzerControlPin, D7);
    delay(120);
    tone(buzzerControlPin, B6);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
            
    // Segunda seção
    tone(buzzerControlPin, C7);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
    tone(buzzerControlPin, G6);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
    tone(buzzerControlPin, E6);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
    tone(buzzerControlPin, A6);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, B6);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, AS6);
    delay(120);
    tone(buzzerControlPin, A6);
    delay(120);
        
    tone(buzzerControlPin, G6);
    delay(180);
    tone(buzzerControlPin, E7);
    delay(180);
    tone(buzzerControlPin, G7);
    delay(180);
    tone(buzzerControlPin, A7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, F7);
    delay(120);
    tone(buzzerControlPin, G7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, E7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, C7);
    delay(120);
    tone(buzzerControlPin, D7);
    delay(120);
    tone(buzzerControlPin, B6);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
            
    // Ponte
    noTone(buzzerControlPin);
    delay(180);
    tone(buzzerControlPin, G7);
    delay(120);
    tone(buzzerControlPin, GS7);
    delay(120);
    tone(buzzerControlPin, A7);
    delay(120);
    tone(buzzerControlPin, F7);
    delay(120);
    tone(buzzerControlPin, G7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, E7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, C7);
    delay(120);
    tone(buzzerControlPin, D7);
    delay(120);
    tone(buzzerControlPin, B6);
    delay(120);
    noTone(buzzerControlPin);
    delay(180);
            
    // Terceira seção
    tone(buzzerControlPin, C7);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
    tone(buzzerControlPin, G6);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
    tone(buzzerControlPin, E6);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
    tone(buzzerControlPin, A6);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, B6);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, AS6);
    delay(120);
    tone(buzzerControlPin, A6);
    delay(120);
        
    tone(buzzerControlPin, G6);
    delay(180);
    tone(buzzerControlPin, E7);
    delay(180);
    tone(buzzerControlPin, G7);
    delay(180);
    tone(buzzerControlPin, A7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, F7);
    delay(120);
    tone(buzzerControlPin, G7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, E7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, C7);
    delay(120);
    tone(buzzerControlPin, D7);
    delay(120);
    tone(buzzerControlPin, B6);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
            
    // Final
    tone(buzzerControlPin, E7);
    delay(120);
    tone(buzzerControlPin, E7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, E7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, C7);
    delay(120);
    tone(buzzerControlPin, E7);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
    tone(buzzerControlPin, G7);
    delay(120);
    noTone(buzzerControlPin);
    delay(360);
    tone(buzzerControlPin, G6);
    delay(120);
    noTone(buzzerControlPin);
    delay(360);
            
    // Acordes finais
    tone(buzzerControlPin, C7);
    delay(180);
    tone(buzzerControlPin, G6);
    delay(180);
    tone(buzzerControlPin, E6);
    delay(180);
    tone(buzzerControlPin, A6);
    delay(150);
    tone(buzzerControlPin, B6);
    delay(150);
    tone(buzzerControlPin, A6);
    delay(120);
    tone(buzzerControlPin, GS6);
    delay(120);
    tone(buzzerControlPin, AS6);
    delay(120);
    tone(buzzerControlPin, GS6);
    delay(120);
    tone(buzzerControlPin, G6);
    delay(120);
    tone(buzzerControlPin, FS6);
    delay(120);
    tone(buzzerControlPin, G6);
    delay(120);
    noTone(buzzerControlPin);
    delay(120);
            
    tone(buzzerControlPin, C7);
    delay(180);
    tone(buzzerControlPin, G6);
    delay(180);
    tone(buzzerControlPin, E6);
    delay(180);
    tone(buzzerControlPin, A6);
    delay(150);
    tone(buzzerControlPin, B6);
    delay(150);
    tone(buzzerControlPin, A6);
    delay(120);
    tone(buzzerControlPin, GS6);
    delay(120);
    tone(buzzerControlPin, AS6);
    delay(120);
    tone(buzzerControlPin, GS6);
    delay(120);
    tone(buzzerControlPin, G6);
    delay(120);
    tone(buzzerControlPin, FS6);
    delay(120);
    tone(buzzerControlPin, G6);
    delay(120);
        
    // Finalização
    tone(buzzerControlPin, B6);
    delay(120);
    tone(buzzerControlPin, G7);
    delay(120);
    tone(buzzerControlPin, D7);
    delay(120);
    tone(buzzerControlPin, E7);
    delay(120);
    tone(buzzerControlPin, C7);
    delay(120);
    tone(buzzerControlPin, A6);
    delay(120);
    tone(buzzerControlPin, FS6);
    delay(120);
    tone(buzzerControlPin, G6);
    delay(120);
    noTone(buzzerControlPin);
    delay(240);
    tone(buzzerControlPin, E6);
    delay(120);
    tone(buzzerControlPin, C7);
    delay(120);
    tone(buzzerControlPin, A6);
    delay(120);
    tone(buzzerControlPin, G6);
    delay(180);
    noTone(buzzerControlPin);
    delay(180);
}