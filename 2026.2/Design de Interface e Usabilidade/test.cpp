// #include <iostream>
// using namespace std;

// teste inicial pra ver cada um em sequência
const int leds[] = {10, 11, 12, 13};
const int totalLeds = sizeof(leds) / sizeof(int);
const int litTime = 200;
const int pauseTime = 200;

void setup() {
    for (int i = 0; i < totalLeds; i++) {
        pinMode(leds[i], OUTPUT);
    }
}

void loop() {
    for (int i = 0; i < totalLeds; i++) {
        digitalWrite(leds[i], HIGH);
        delay(litTime);
        digitalWrite(leds[i], LOW);
    }
}


// tests
// int main() {
//     cout << totalLeds;
//
//     return 0;
// }
