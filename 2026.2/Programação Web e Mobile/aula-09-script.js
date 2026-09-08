// Aguarda o DOM carregar completamente
document.addEventListener('DOMContentLoaded', function() {
    
    // Seleciona elementos do formulário
    const formulario = document.getElementById('formulario-contato');
    const btnLimpar = document.getElementById('btn-limpar');
    const mensagemSucesso = document.getElementById('mensagem-sucesso');
    
    // Seleciona os campos
    const campoNome = document.getElementById('nome');
    const campoEmail = document.getElementById('email');
    const campoAssunto = document.getElementById('assunto');
    
    // Seleciona os elementos de erro
    const erroNome = document.getElementById('erro-nome');
    const erroEmail = document.getElementById('erro-email');
    const erroAssunto = document.getElementById('erro-assunto');

    // ========================================
    // FUNÇÃO: LIMPAR FORMULÁRIO
    // ========================================
    function limparFormulario() {
        // Limpa os valores dos campos
        formulario.reset();
        
        // Limpa as mensagens de erro
        erroNome.textContent = '';
        erroEmail.textContent = '';
        erroAssunto.textContent = '';
        
        // Esconde mensagem de sucesso (se estiver visível)
        mensagemSucesso.style.display = 'none';
        
        // Remove borda de erro (se houver)
        campoNome.style.borderColor = '#ddd';
        campoEmail.style.borderColor = '#ddd';
        campoAssunto.style.borderColor = '#ddd';
    }

    // ========================================
    // FUNÇÃO: VALIDAR NOME
    // ========================================
    function validarNome() {
        const nome = campoNome.value.trim();
        
        if (nome === '') {
            erroNome.textContent = '❌ O nome é obrigatório';
            campoNome.style.borderColor = '#dc3545';
            return false;
        }
        
        if (nome.length < 3) {
            erroNome.textContent = '❌ O nome deve ter pelo menos 3 caracteres';
            campoNome.style.borderColor = '#dc3545';
            return false;
        }
        
        // Nome válido
        erroNome.textContent = '';
        campoNome.style.borderColor = '#28a745';
        return true;
    }

    // ========================================
    // FUNÇÃO: VALIDAR E-MAIL
    // ========================================
    function validarEmail() {
        const email = campoEmail.value.trim();
        
        if (email === '') {
            erroEmail.textContent = '❌ O e-mail é obrigatório';
            campoEmail.style.borderColor = '#dc3545';
            return false;
        }
        
        // Expressão regular para validar e-mail
        const regexEmail = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        
        if (!regexEmail.test(email)) {
            erroEmail.textContent = '❌ Digite um e-mail válido';
            campoEmail.style.borderColor = '#dc3545';
            return false;
        }
        
        // E-mail válido
        erroEmail.textContent = '';
        campoEmail.style.borderColor = '#28a745';
        return true;
    }

    // ========================================
    // FUNÇÃO: VALIDAR ASSUNTO
    // ========================================
    function validarAssunto() {
        const assunto = campoAssunto.value.trim();
        
        if (assunto === '') {
            erroAssunto.textContent = '❌ O assunto é obrigatório';
            campoAssunto.style.borderColor = '#dc3545';
            return false;
        }
        
        if (assunto.length < 5) {
            erroAssunto.textContent = '❌ O assunto deve ter pelo menos 5 caracteres';
            campoAssunto.style.borderColor = '#dc3545';
            return false;
        }
        
        // Assunto válido
        erroAssunto.textContent = '';
        campoAssunto.style.borderColor = '#28a745';
        return true;
    }

    // ========================================
    // FUNÇÃO: ENVIAR FORMULÁRIO
    // ========================================
    function enviarFormulario(evento) {
        // Previne o envio padrão do formulário
        evento.preventDefault();
        
        // Valida todos os campos
        const nomeValido = validarNome();
        const emailValido = validarEmail();
        const assuntoValido = validarAssunto();
        
        // Se algum campo for inválido, para aqui
        if (!nomeValido || !emailValido || !assuntoValido) {
            return;
        }
        
        // Se chegou aqui, todos os campos são válidos!
        
        // Pega os valores
        const nome = campoNome.value.trim();
        const email = campoEmail.value.trim();
        const assunto = campoAssunto.value.trim();
        
        // Simula envio (aqui você enviaria para um servidor)
        console.log('=================================');
        console.log('FORMULÁRIO ENVIADO COM SUCESSO!');
        console.log('=================================');
        console.log('Nome:', nome);
        console.log('E-mail:', email);
        console.log('Assunto:', assunto);
        console.log('=================================');
        
        // Mostra mensagem de sucesso
        mensagemSucesso.style.display = 'block';
        
        // Esconde o formulário (opcional)
        // formulario.style.display = 'none';
        
        // Limpa o formulário após 3 segundos
        setTimeout(function() {
            limparFormulario();
        }, 3000);
    }

    // ========================================
    // EVENTOS
    // ========================================
    
    // Evento: Submeter formulário
    formulario.addEventListener('submit', enviarFormulario);
    
    // Evento: Botão Limpar
    btnLimpar.addEventListener('click', limparFormulario);
    
    // Eventos: Validação em tempo real (opcional)
    campoNome.addEventListener('blur', validarNome);
    campoEmail.addEventListener('blur', validarEmail);
    campoAssunto.addEventListener('blur', validarAssunto);
    
    // Remove mensagem de erro ao digitar
    campoNome.addEventListener('input', function() {
        if (campoNome.value.trim() !== '') {
            erroNome.textContent = '';
            campoNome.style.borderColor = '#ddd';
        }
    });
    
    campoEmail.addEventListener('input', function() {
        if (campoEmail.value.trim() !== '') {
            erroEmail.textContent = '';
            campoEmail.style.borderColor = '#ddd';
        }
    });
    
    campoAssunto.addEventListener('input', function() {
        if (campoAssunto.value.trim() !== '') {
            erroAssunto.textContent = '';
            campoAssunto.style.borderColor = '#ddd';
        }
    });
});