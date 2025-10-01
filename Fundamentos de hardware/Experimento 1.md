# Alunos:
- Allan Lucas
- Breno Araújo
- Guilherme Larré
- Mozart Moura
- Renan Souza

<br>

# Experimento #1

## Resistor 1

| Azul | Cinza | Marrom | Dourado |
| --- | --- | --- | --- |
| 6 | 8 | *10 | +- 5% |

- Resistência nominal: 680 Ω
- Tolerância: 646 ~ 714 Ω
- Resistência real: 667 Ω

## Resistor 2

| Marrom | Preto | Laranja | Dourado |
| --- | --- | --- | --- |
| 1 | 0 | *1000 | +- 5% |

- Resistência nominal: 10.000 Ω
- Tolerância: 9.500 ~ 10.500 Ω
- Resistência real: 9.600 Ω

## Resistor 3

| Marrom | Preto | Verde | Dourado |
| --- | --- | --- | --- |
| 1 | 0 | *100.000 | +- 5% |

- Resistência nominal: 1.000.000 Ω
- Tolerância: 950.000 ~ 1.050.000 Ω
- Resistência real: 1.007.000 Ω

## Resistor 4

| Laranja | Laranja | Marrom | Dourado |
| --- | --- | --- | --- |
| 3 | 3 | *10 | +- 5% |

- Resistência nominal: 330 Ω
- Tolerância: 313 ~ 343,5 Ω
- Resistência real: 325,6 Ω

## Resistor 5

| Marrom | Vermelho | Preto | Dourado |
| --- | --- | --- | --- |
| 1 | 2 | *1 | +- 5% |

- Resistência nominal: 12 Ω
- Tolerância: 11,4 ~ 12,6 Ω
- Resistência real: 12,5 Ω

# Síntese e reflexões finais

1. Sim, todos resistores estavam dentro da tolerância especificada.

2. Não houve consistência. 3 dos 5 resistores tiveram valores reais menores do que os valores nominais. Os outros 2 tiveram valores maiores.

3. A tolerância de resistores em um divisor de tensão pode causar um erro na tensão de saída, afetando a calibração de outros componentes, como conversores analógico-digitais (ADCs). ​Em filtros, a tolerância de resistores e capacitores altera a frequência de corte, o que pode comprometer a capacidade do filtro de remover ruídos ou de passar sinais específicos, impactando o desempenho em sistemas de áudio e telecomunicações.

4. Em circuitos como filtros de áudio de alta fidelidade ou instrumentos de medição, a precisão de um resistor é crucial, portanto seus valores devem estar exatamente como o esperado. Já em um circuito simples, como no uso de um resistor para limitar a corrente que vai para um LED, sua precisão é menos importante e uma pequena variação na resistência não compromete seu funcionamento.

# Conclusão do experimento

Concluímos que os resistores tenderam a estar na faixa de tolerância especificada pelos fabricantes. No caso dos nossos experimentos em sala de aula, os resistores examinados parecem ser suficientes. Já em aplicações reais do mercado, talvez fossem necessários resistores de maior precisão.

Outros pontos de preocupação em uma aplicação do "mundo real" seria a qualidade e precisão dos equipamentos usados nos experimentos, como o nosso multímetro, protoboard e jumpers.