// CHECK: ver quais realmente sao necessarios pro tinkercad
#include <cstdint>
#include <stdlib.h>
#include <sys/types.h>
// NOTE: n sei se precisa...
// #include <Arduino.h>
#include <LiquidCrystal.h>

#define MAX_LEDS 4
#define MAX_PLAYERS 4
#define MAX_SEQUENCIA 10

// NOTE: const globais
const uint8_t PINOS_LEDS[MAX_LEDS] = {13, 12, 11, 10};
const uint8_t PINOS_BOTOES[MAX_LEDS] = {9, 8, 7, 6};
const uint8_t PINO_BOTAO_MENU = 5;
const uint8_t PINO_BOTAO_ON_OFF = 4;
// pinos do lcd
const uint8_t PIN_LCD_RS = 2;
const uint8_t PIN_LCD_EN = 3;
const uint8_t PIN_LCD_D4 = A0;
const uint8_t PIN_LCD_D5 = A1;
const uint8_t PIN_LCD_D6 = A2;
const uint8_t PIN_LCD_D7 = A3;
// constantes de tempo
const uint16_t TEMPO_DEBOUNCE = 50; //50ms pra como filtro pra ruidos
const uint16_t TEMPO_CLIQUE_DUPLO = 300; // CHECK: ver se vai usar msm
const uint16_t TEMPO_CLIQUE_LONGO = 1000;

// NOTE: inicialização do display
LiquidCrystal lcd(PIN_LCD_RS, PIN_LCD_EN, PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7);

uint8_t ultimoEstadoBotao = HIGH; //HIGH por conta do INPUT_PULLUP
unsigned long tempoUltimaMudanca = 0;
unsigned long tempoPressionado = 0;
unsigned long tempoLiberado = 0;
uint8_t contagemCliques = 0;
bool cliqueLongoProcessado = false;

// NOTE: lógica da sequência de cores
// uint8_t (1 byte), em vez de int (2 ou 4 bytes)
enum Color : uint8_t {
    VERDE = 0,
    VERMELHO = 1,
    AZUL = 2,
    AMARELO = 3
};

// NOTE: fila pra sequência atual de cores (FIFO)
struct filaCor {
    Color sequenciaCor[MAX_SEQUENCIA];
    uint8_t inicio = 0, final = 0, qtd = 0;

    bool enqueue(Color cor) {
        if (qtd == MAX_SEQUENCIA) {
            return false;
        }
        sequenciaCor[final] = cor;
        final = (final + 1) % MAX_SEQUENCIA; //circular
        qtd++;
        return true;
    }

    bool dequeue(Color &corRemovida) {
        if (qtd == 0) {
            return false;
        }
        corRemovida = sequenciaCor[inicio];
        inicio = (inicio + 1) % MAX_SEQUENCIA; //circular
        qtd--;
        return true;
    }
};

// NOTE: classe player
class Player {
    public:
        // atributos
        uint16_t score;
        // CHECK: como vai ser a checagem do ranking?
        // uint8_t rank;
        bool ativo;

        // construtor
        Player() {
            score = 0;
            ativo = false;
            // rank = 0;
        }

        void reset() {
            score = 0;
            bool ativo = false;
        }
};

// NOTE: lógica do jogo
// NOTE: instanciação dos jogadores
// cria os 4 jogadores na memória
Player playerList[MAX_PLAYERS];
// ponteiro pro player atual
uint8_t playerAtual = 0;
// qtd jogadores escolhida
uint8_t totalPlayers = 1;
// função pra ir pro próx player
void proxPlayer() {
    uint8_t proxPlayer; //ponteiro em playerList

    do {
        proxPlayer = (playerAtual + 1) % totalPlayers;
    } while (playerList[proxPlayer].ativo == false);

    playerAtual = proxPlayer;
}
// função pra pontuar playerAtual
void pontuarPlayer(uint8_t pontos) {
    playerList[playerAtual].score += pontos;
}

// NOTE: sequência de cores
// variável global pra guardar sequência
filaCor sequenciaAtualGlobal;
// variável global da jogada atual (vai ser resetada a cada tentativa correta)
filaCor jogadaAtual;
// função pra resetar jogo (caso precise)
void resetJogo() {
    sequenciaAtualGlobal = filaCor();
}
// função pra inserir uma cor aleatória na var global
void randomColor() {
    uint8_t randNum = random(0, 4); //de 0 a 3
    sequenciaAtualGlobal.enqueue(static_cast<Color>(randNum));
}

// TEST:
// função pra comparar sequência atual com sequência inserida pelo player
bool verificarJogada(filaCor jogadaAtual) {
    // cria uma cópia da variável global
    filaCor sequenciaAtualCopia = sequenciaAtualGlobal;
    if (jogadaAtual.qtd != sequenciaAtualCopia.qtd) return false;
    for (int i = 0; i < sequenciaAtualGlobal.qtd; i++) {
        if (jogadaAtual.sequenciaCor[i] != sequenciaAtualGlobal.sequenciaCor[i]) return false;
    }
    return true;
}

// NOTE: menus
// menu setup: pegar qtd de jogadores desejada e setar globalmente (totalPlayers)
bool primeiraRodada = true;

// CHECK: essa lib String tá funcionando? é ideal? melhor usar char*?
void menu_setup() {
    primeiraRodada = false;
    String promptInicial = "Escolha a qtd de jogadores...";
    // TODO: logica de mostrar no display corretamente
    // printar o menu, solicitar totalPlayers...
    // totalPlayers = ;
    String prompt1P = "1 jogadores";
    String prompt2P = "2 jogadores";
    String prompt3P = "3 jogadores";
    String prompt4P = "4 jogadores";
    

}

// TODO: menu pausa (mostrar que está em pausa e deixar opções pra mostrar ranking, score, terminar jogo, resetar...)
void menu_pausa() {
    // pipipi popopo
}

// NOTE: strings pro menu
String vezPlayer1 = "-- Player 1 --";
String vezPlayer2 = "-- Player 2 --";
String vezPlayer3 = "-- Player 3 --";
String vezPlayer4 = "-- Player 4 --";

// TODO:
void mostrarSequenciaGlobal() {
    
}

// NOTE: setup + loop
// NOTE: em setup, as coisas rodam apenas 1 vez, no início.
void setup() {
    // aqui realizamos o setup desejado pros pinos do arduino
    for (int i = 0; i < MAX_LEDS; i++) {
        pinMode(PINOS_LEDS[i], OUTPUT);
        pinMode(PINOS_BOTOES[i], INPUT);
    }

    // TEST: ver se INPUT_PULLUP dá certo atualmente no circuito
    pinMode(PINO_BOTAO_MENU, INPUT_PULLUP);
    pinMode(PINO_BOTAO_ON_OFF, INPUT_PULLUP);

    lcd.begin(16, 2);

    // leitura analógica de um pino desconectado como seed
    randomSeed(analogRead(2));
    Serial.begin(9600); // REMOVE: pra teste apenas
}

// NOTE: loop contínuo do jogo
// TODO: checagem do tempo de input
void loop() {
    // TEST:
    if (primeiraRodada)
        menu_setup();
    uint8_t estadoBotaoMenu = digitalRead(PINO_BOTAO_MENU);
    if (estadoBotaoMenu == 1) {
        menu_pausa();
    }

    // TODO: se for primeiro, mostrar sequencia global na tela, se não, só recebe input até ter msm qtd de cores da seq global ou acabar o tempo
    // if (primeiroJogador) {
    //     randomColor();
    //     mostrarSequenciaGlobal();
    // }

    // se for primeiro jogador, mostra sequencia global

    // se não, recebe a sequência atual do jogador atual
    // e vai comparando

    // deve haver um tempo para poder inserir sequência (até 5s após o tempo da sequência atual)
    // TODO: checar quantos segundos leva pra mostrar
    // sequencia atual e se deve diminuir ao longo do jogo
    uint8_t estadoBotoes[MAX_LEDS] = {0}; //inicia tudo em LOW (0)

    for (int i = 0; i < MAX_LEDS; i++) {
        uint8_t estadoBotaoAtual = digitalRead(PINOS_BOTOES[i]);
        if (estadoBotaoAtual == 1) {
            jogadaAtual.enqueue(static_cast<Color>(i));
            if (jogadaAtual.qtd == sequenciaAtualGlobal.qtd) {
                if (verificarJogada(jogadaAtual) == true) {
                    // pontua jogador e passa pro prox
                    pontuarPlayer(10);
                    proxPlayer();
                } else {
                    // TODO:
                    // tira jogador e passa pro prox
                    playerList[playerAtual].ativo = false;
                    proxPlayer();
                }
            }
        }
    }
}

// TODO: pensar como será sistema de pontuação
// TODO: pensar no feedback ao user -> luz, som, ...?
// TODO: persistência na memória pra guardar highscore
