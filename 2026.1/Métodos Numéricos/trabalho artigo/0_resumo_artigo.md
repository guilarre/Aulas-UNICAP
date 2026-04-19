# A new optimal root-finding iterative algorithm: local and semilocal analysis with polynomiography

## APRESENTAÇÃO

- introdução -> contexto/justificativa de criar tal método- Daniel Silva 
- utilidade do método na prática (exs de uso) - Matheus Marques 
- apresentar nossa implementação do método em python, modulos usados, etc (guilherme)
- exemplos (renato)

---

## RESUMO

1. Introduction
- justificativa: métodos numéricos como esse ajudam a encontrar soluções para equações implícitas (equações transcendentais não lineares), que não podem ser resolvidas analiticamente (através de fórmulas exatas) e precisam de métodos iterativos para encontrar-se soluções aproximadas (p. 1)
- utilidades no mundo real: equações não lineares usadas em física (equações de Navier-Stokes em dinâmica de fluido) e engenharia que descrevem sistemas complexos, com múltiplos componentes que interagem entre si. O autor enfatiza que métodos numéricos são formas de se resolver mais facilmente que por métodos analíticos, que são muito difíceis ou impossíveis. Os métodos numéricos fazem com que possamos usar a estratégia de dividir e conquistar, dividindo grandes sistemas em partes menores e encontrando soluções para elas usando técnicas iterativas (p. 1-2)
- fala do método de newton-raphson como sendo mais rápido e preciso que outros métodos, porém tendo a desvantagem de utilizar a derivada e nem sempre convergir para certas funções
- conjetura kung-traub: para um algoritmo iterativo de busca de raiz sem memória ser considerado ótimo, deve ter uma ordem de convergência 2^(k-1), onde k = o nº de vezes que a função é avaliada POR ITERAÇÃO, portanto, um método de quarta ordem é considerado ótimo se exigir apenas 3 AVALIAÇÕES DA FUNÇÃO POR PASSO ITERATIVO
- o artigo apresenta um método ótimo de quarta ordem para encontrar raiz
- introdução de métodos numéricos em geral, trata f(x) como ψ(x) (psi) e vai mostrando exemplos de métodos para encontrar raiz, utilidades, etc
- definição de ordem de conversão e utilidades de ordens de conversão maiores
- quando o número de raizes é conhecido, existe uma simplificação do método proposto
- mostra performance do método proposto usando exemplos do mundo real: CSTR, radiação de Plank e Van der Waals

2. Some existing root-finding methods
- p. 3: menciona que são usados para encontrar soluções para equações não lineares que descrevem o compostamento de um sistema, ajudando a criar sistemas mais robustos e eficientes, projetar novas tecnologias em diversas áreas de pesquisa e desenvolvimento
- traz os métodos mais conhecidos
- detalha alguns métodos de raiz pra comparar posteriormente no artigo

3. Construction of the method
- ele traz como o método foi construído passo a passo, a partir das fórmulas 7 e 8, obtendo as fórmulas em 9 (fórmula base, estabelecendo o parâmetro n) e 18 (equação final usando η = 1/3, parâmetro identificado como o valor de n que anula os termos de erro de ordem inferior)

4. Local convergence analysis: first approach
5. Local convergence analysis: second approach
6. Semilocal convergence
- o autor dedica 3 capítulos, para demonstrar a convergência local (quando conhecemos a raiz e queremos analisar o raio de convergencia usando expansao de taylor) e semilocal (quando temos uma estimativa inicial e queremos definir as condições de convergência)

7. Numerical and graphical results
- mostra e analisa a polinomiografia do método proposto e outros métodos conhecidos
- exemplos numéricos de funções não lineares "acadêmicas"
- aplicações na vida real
