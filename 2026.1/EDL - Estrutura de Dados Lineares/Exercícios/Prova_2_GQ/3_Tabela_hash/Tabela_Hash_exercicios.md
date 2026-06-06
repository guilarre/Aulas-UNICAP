# Lista de exercícios — Tabela Hash

1. Defina com suas palavras o que é uma tabela hash e como ela funciona.

2. Quando se utiliza tabelas hash, pode ocorrer colisão. Explique o que é uma colisão.

3. Quando se utiliza tabelas hash, pode ocorrer colisão. Quais são os métodos de tratamento de colisão? Explique cada um deles com suas palavras.

4. Cite duas características desejáveis quando definimos uma função hash.

5. Explique o método da divisão, usado na criação de funções hash. Cite um possível problema deste método.

6. Discuta as vantagens e desvantagens de se utilizar o método de endereçamento aberto para tratamento de colisões.

7. Demonstre a inserção das chaves 5, 28, 19, 15, 20, 33, 12, 7 e 10 numa tabela hash com colisões resolvidas por encadeamento separado. Considere a tabela com `m = 9` posições e a função hash como sendo `h(k) = k % m`. Reconstrua a tabela para `m = 11` (primo) e comente os resultados.

8. Suponha uma tabela hash de tamanho `M = 10` com endereçamento aberto para armazenar chaves no intervalo `[1, 999]`. Insira as seguintes chaves nessa tabela: `371`, `121`, `173`, `203`, `11`, `24`, nessa ordem, considerando diferentes métodos de resolução de colisões:

   (a) Sondagem linear, função hash: `h(k) = (k + i) % M`

   (b) Sondagem quadrática, função hash: `h(k) = (k + i²) % M`

   (c) Sondagem quadrática, função hash: `h(k) = (k + 2i + i²) % M`

   (d) Hash duplo: `h1(k) = k % M` e `h2(k) = 7 − (k % 7)`

9. Como excluir itens de uma tabela hash que usa encadeamento para tratar colisões? E se for endereçamento aberto? Quais são as circunstâncias especiais que devem ser tratadas?

10. Dado os valores `2341`, `4234`, `2839`, `430`, `22`, `397`, `3920`, uma tabela hash de tamanho `7`, e função de hash `h(x) = x % 7`, mostre as tabelas resultantes depois de inserir os valores na ordem dada com cada uma destas estratégias de colisão:
    
    (a) Sondagem linear
    
    (b) Sondagem quadrática
    
    (c) Encadeamento separado