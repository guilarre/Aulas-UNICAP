// Organizando com struct:
struct Quadrado {
    float l;
};

typedef struct Quadrado quadrado;

// Protótipo da função pra podermos implementar a função após main
float calcular_area(quadrado q);
float calcular_perimetro(quadrado q);

// Menos verboso:
/*
typedef struct {
    float l;
} quadrado;
*/

// Organizando de maneira modular:
float calcular_area(quadrado q) {
    return q.l * q.l;
}

float calcular_perimetro(quadrado q) {
    return 4 * q.l;
}
