// ========================================
// SEÇÃO 1: IF/ELSE
// ========================================
function verificarIdade() {
    const idade = parseInt(document.getElementById('idade1').value);
    const resultado = document.getElementById('resultado-idade');
    
    let mensagem = '';
    
    if (idade >= 18) {
        mensagem = `<strong>Idade: ${idade} anos</strong><br>`;
        mensagem += `✅ <strong style="color: green;">MAIOR DE IDADE</strong><br>`;
        mensagem += `Pode votar, dirigir (com habilitação) e assinar contratos.`;
    } else {
        mensagem = `<strong>Idade: ${idade} anos</strong><br>`;
        mensagem += `❌ <strong style="color: red;">MENOR DE IDADE</strong><br>`;
        mensagem += `Faltam ${18 - idade} ano(s) para atingir a maioridade.`;
    }
    
    resultado.innerHTML = mensagem;
    resultado.style.display = 'block';
}

function classificarNota() {
    const nota = parseInt(document.getElementById('nota').value);
    const resultado = document.getElementById('resultado-nota');
    
    let classificacao, mensagem, cor;
    
    if (nota >= 90) {
        classificacao = 'A - Excelente!';
        mensagem = 'Parabéns! Desempenho excepcional! 🌟';
        cor = '#2e7d32';
    } else if (nota >= 70) {
        classificacao = 'B - Bom!';
        mensagem = 'Muito bem! Continue assim! 👍';
        cor = '#1976d2';
    } else if (nota >= 50) {
        classificacao = 'C - Regular';
        mensagem = 'Você passou, mas pode melhorar.';
        cor = '#f57c00';
    } else {
        classificacao = 'D - Reprovado';
        mensagem = 'Precisa estudar mais para a próxima. 📚';
        cor = '#c62828';
    }
    
    resultado.innerHTML = `
        <strong>Nota: ${nota}</strong><br>
        <strong style="color: ${cor};">${classificacao}</strong><br>
        ${mensagem}
    `;
    resultado.style.display = 'block';
}

// ========================================
// SEÇÃO 2: TERNÁRIO E SWITCH
// ========================================
function testarTernario() {
    const idade = parseInt(document.getElementById('idade-ternario').value);
    const resultado = document.getElementById('resultado-ternario');
    
    // Usando operador ternário
    const status = idade >= 18 ? 'adulto' : 'menor';
    const cor = idade >= 18 ? 'green' : 'red';
    
    resultado.innerHTML = `
        <strong>Idade: ${idade} anos</strong><br>
        <strong>Operador Ternário:</strong><br>
        <code>const status = idade >= 18 ? 'adulto' : 'menor';</code><br><br>
        <strong style="color: ${cor};">Status: ${status}</strong>
    `;
    resultado.style.display = 'block';
}

function verificarDia() {
    const dia = parseInt(document.getElementById('dia').value);
    const resultado = document.getElementById('resultado-dia');
    
    let nomeDia, tipo;
    
    switch(dia) {
        case 1:
            nomeDia = 'Segunda-feira';
            tipo = 'Dia útil';
            break;
        case 2:
            nomeDia = 'Terça-feira';
            tipo = 'Dia útil';
            break;
        case 3:
            nomeDia = 'Quarta-feira';
            tipo = 'Dia útil';
            break;
        case 4:
            nomeDia = 'Quinta-feira';
            tipo = 'Dia útil';
            break;
        case 5:
            nomeDia = 'Sexta-feira';
            tipo = 'Dia útil (quase fim de semana! 🎉)';
            break;
        case 6:
            nomeDia = 'Sábado';
            tipo = 'Fim de semana! 🎊';
            break;
        case 7:
            nomeDia = 'Domingo';
            tipo = 'Fim de semana! 😴';
            break;
        default:
            nomeDia = 'Dia inválido';
            tipo = '';
    }
    
    resultado.innerHTML = `
        <strong>Dia ${dia}: ${nomeDia}</strong><br>
        ${tipo}
    `;
    resultado.style.display = 'block';
}

// ========================================
// SEÇÃO 3: FOR LOOP
// ========================================
function gerarTabuada() {
    const num = parseInt(document.getElementById('num-tabuada').value);
    const resultado = document.getElementById('resultado-tabuada');
    
    let html = `<strong>Tabuada do ${num}:</strong><br><br>`;
    
    for (let i = 1; i <= 10; i++) {
        html += `${num} × ${i} = <strong>${num * i}</strong><br>`;
    }
    
    resultado.innerHTML = html;
    resultado.style.display = 'block';
}

function contagemRegressiva() {
    const num = parseInt(document.getElementById('num-contagem').value);
    const resultado = document.getElementById('resultado-contagem');
    
    let html = '<strong>Contagem Regressiva:</strong><br><br>';
    
    for (let i = num; i >= 0; i--) {
        if (i === 0) {
            html += `<strong style="color: red; font-size: 1.5em;">🚀 ZERO!</strong>`;
        } else {
            html += `${i}... `;
        }
    }
    
    resultado.innerHTML = html;
    resultado.style.display = 'block';
}

// ========================================
// SEÇÃO 4: WHILE
// ========================================
function somaAteN() {
    const n = parseInt(document.getElementById('num-while').value);
    const resultado = document.getElementById('resultado-while');
    
    let soma = 0;
    let contador = 1;
    let calculo = '';
    
    while (contador <= n) {
        if (contador === 1) {
            calculo += contador;
        } else {
            calculo += ` + ${contador}`;
        }
        soma += contador;
        contador++;
    }
    
    resultado.innerHTML = `
        <strong>Soma de 1 até ${n}:</strong><br><br>
        ${calculo} = <strong>${soma}</strong><br><br>
        <code>
        let soma = 0;<br>
        let contador = 1;<br>
        while (contador <= ${n}) {<br>
        &nbsp;&nbsp;soma += contador;<br>
        &nbsp;&nbsp;contador++;<br>
        }
        </code>
    `;
    resultado.style.display = 'block';
}

// ========================================
// SEÇÃO 5: FUNÇÕES
// ========================================
// Funções de calculadora
function somar(a, b) {
    return a + b;
}

function subtrair(a, b) {
    return a - b;
}

function multiplicar(a, b) {
    return a * b;
}

function dividir(a, b) {
    if (b === 0) {
        return 'Erro: Divisão por zero!';
    }
    return a / b;
}

function usarSomar() {
    const num1 = parseFloat(document.getElementById('num1-func').value);
    const num2 = parseFloat(document.getElementById('num2-func').value);
    const resultado = document.getElementById('resultado-func');
    
    const res = somar(num1, num2);
    
    resultado.innerHTML = `
        <strong>Função: somar(${num1}, ${num2})</strong><br>
        Resultado: <strong>${res}</strong>
    `;
    resultado.style.display = 'block';
}

function usarSubtrair() {
    const num1 = parseFloat(document.getElementById('num1-func').value);
    const num2 = parseFloat(document.getElementById('num2-func').value);
    const resultado = document.getElementById('resultado-func');
    
    const res = subtrair(num1, num2);
    
    resultado.innerHTML = `
        <strong>Função: subtrair(${num1}, ${num2})</strong><br>
        Resultado: <strong>${res}</strong>
    `;
    resultado.style.display = 'block';
}

function usarMultiplicar() {
    const num1 = parseFloat(document.getElementById('num1-func').value);
    const num2 = parseFloat(document.getElementById('num2-func').value);
    const resultado = document.getElementById('resultado-func');
    
    const res = multiplicar(num1, num2);
    
    resultado.innerHTML = `
        <strong>Função: multiplicar(${num1}, ${num2})</strong><br>
        Resultado: <strong>${res}</strong>
    `;
    resultado.style.display = 'block';
}

function usarDividir() {
    const num1 = parseFloat(document.getElementById('num1-func').value);
    const num2 = parseFloat(document.getElementById('num2-func').value);
    const resultado = document.getElementById('resultado-func');
    
    const res = dividir(num1, num2);
    
    resultado.innerHTML = `
        <strong>Função: dividir(${num1}, ${num2})</strong><br>
        Resultado: <strong>${res}</strong>
    `;
    resultado.style.display = 'block';
}

// Arrow Function
const dobro = (x) => x * 2;

function calcularDobro() {
    const num = parseFloat(document.getElementById('num-arrow').value);
    const resultado = document.getElementById('resultado-arrow');
    
    const res = dobro(num);
    
    resultado.innerHTML = `
        <strong>Arrow Function:</strong><br>
        <code>const dobro = (x) => x * 2;</code><br><br>
        dobro(${num}) = <strong>${res}</strong>
    `;
    resultado.style.display = 'block';
}

// ========================================
// SEÇÃO 6: EXERCÍCIOS
// ========================================
function fizzBuzz() {
    const n = parseInt(document.getElementById('num-fizzbuzz').value);
    const resultado = document.getElementById('resultado-fizzbuzz');
    
    let html = '<strong>FizzBuzz de 1 até ' + n + ':</strong><br><br>';
    
    for (let i = 1; i <= n; i++) {
        if (i % 3 === 0 && i % 5 === 0) {
            html += `<span style="color: purple; font-weight: bold;">FizzBuzz</span>, `;
        } else if (i % 3 === 0) {
            html += `<span style="color: blue; font-weight: bold;">Fizz</span>, `;
        } else if (i % 5 === 0) {
            html += `<span style="color: green; font-weight: bold;">Buzz</span>, `;
        } else {
            html += i + ', ';
        }
    }
    
    resultado.innerHTML = html;
    resultado.style.display = 'block';
}

function mostrarPares() {
    const n = parseInt(document.getElementById('num-pares').value);
    const resultado = document.getElementById('resultado-pares');
    
    let html = `<strong>Números pares de 1 até ${n}:</strong><br><br>`;
    let pares = [];
    
    for (let i = 1; i <= n; i++) {
        if (i % 2 === 0) {
            pares.push(i);
        }
    }
    
    html += pares.join(', ');
    html += `<br><br><strong>Total: ${pares.length} números pares</strong>`;
    
    resultado.innerHTML = html;
    resultado.style.display = 'block';
}

function calcularFatorial() {
    const n = parseInt(document.getElementById('num-fatorial').value);
    const resultado = document.getElementById('resultado-fatorial');
    
    let fatorial = 1;
    let calculo = '';
    
    for (let i = n; i >= 1; i--) {
        fatorial *= i;
        if (i === n) {
            calculo += i;
        } else {
            calculo += ` × ${i}`;
        }
    }
    
    if (n === 0) {
        calculo = '1';
        fatorial = 1;
    }
    
    resultado.innerHTML = `
        <strong>${n}! (fatorial de ${n}):</strong><br><br>
        ${calculo} = <strong>${fatorial}</strong>
    `;
    resultado.style.display = 'block';
}

function verificarPrimo() {
    const num = parseInt(document.getElementById('num-primo').value);
    const resultado = document.getElementById('resultado-primo');
    
    function ehPrimo(n) {
        if (n < 2) return false;
        for (let i = 2; i <= Math.sqrt(n); i++) {
            if (n % i === 0) return false;
        }
        return true;
    }
    
    const primo = ehPrimo(num);
    
    let html = `<strong>Número: ${num}</strong><br><br>`;
    
    if (primo) {
        html += `✅ <strong style="color: green;">${num} é PRIMO!</strong><br>`;
        html += `É divisível apenas por 1 e por ${num}.`;
    } else {
        html += `❌ <strong style="color: red;">${num} NÃO é primo.</strong><br>`;
        // Encontrar um divisor
        for (let i = 2; i < num; i++) {
            if (num % i === 0) {
                html += `É divisível por ${i} (${num} ÷ ${i} = ${num/i}).`;
                break;
            }
        }
    }
    
    resultado.innerHTML = html;
    resultado.style.display = 'block';
}