// NOTE: funções

// função para resetar formulário de contato
function resetForm(form) {
    if (form) {
        form.reset();
    }
}

// toggle pra abrir/fechar menu navbar
function toggleNavbar() {
    const menuButton = document.querySelector('#navbar-toggle');
    const navbarMenu = document.querySelector('#navbar');

    if (menuButton && navbarMenu) {
        navbarMenu.classList.toggle('active');
        menuButton.classList.toggle('active');
    }
}

// pra atualizar contagem de caracteres na mensagem do form
function charCount() {
    const msgLen = document.querySelector('#mensagem').value.length;
    const charCountSpan = document.querySelector('#char-count');
    charCountSpan.textContent = `${msgLen}/5000 caracteres`;
}

// funções de validação do form
function validarNome() {
    const nome = document.querySelector('#nome');
    if (nome.value.trim() === '') {
        nome.classList.add("erro");
        return false;
    }

    nome.classList.remove("erro");
    return true;
}

function validarEmail() {
    const email = document.querySelector('#email');
    const emailValue = email.value.trim();
    if (emailValue === '') {
        email.classList.add("erro");
        email.setCustomValidity("Preencha este campo com o seu e-mail.")
        email.reportValidity();
        return false;
    }

    const regexEmail = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/;
    if (!regexEmail.test(emailValue)) {
        email.classList.add("erro");
        email.setCustomValidity("Insira um endereço de e-mail válido (ex: nome@dominio.com).")
        email.reportValidity();
        return false;
    }

        email.setCustomValidity("")
    email.classList.remove("erro");
    return true;
}

function validarAssunto() {
    const assunto = document.querySelector('#assunto');
    if (assunto.value.trim() === '') {
        assunto.classList.add("erro");
        return false;
    }

    assunto.classList.remove("erro");
    return true;
}

function validarMensagem() {
    const mensagem = document.querySelector('#mensagem');
    if (mensagem.value.trim() === '') {
        mensagem.classList.add("erro");
        return false;
    }

    mensagem.classList.remove("erro");
    return true;
}

// função p validar e enviar form
function validarEEnviarForm(e) {
    e.preventDefault();

    const currentForm = e.target.form || e.target;

    if (!validarNome() || !validarEmail() || !validarAssunto() || !validarMensagem()) {
        return;
    }

    const nome = document.querySelector('#nome').value;
    const email = document.querySelector('#email').value;
    const assunto = document.querySelector('#assunto').value;
    const mensagem = document.querySelector('#mensagem').value;

    // Simulando envio do form
    console.log(`
===============================
FORMULÁRIO ENVIADO COM SUCESSO!
===============================
Nome: ${nome}
E-mail: ${email}
Assunto: ${assunto}
\nMensagem: ${mensagem}
===============================
`);

    alert("Sua mensagem foi enviada com sucesso!");
    resetForm(currentForm);
}

// NOTE: inicializações e event listeners para chamar nossas funções

const menuButton = document.querySelector('#navbar-toggle');
const form = document.querySelector('#contato form')
const formInputs = document.querySelectorAll('#contato form input, #assunto, #mensagem');
const messageArea = document.querySelector('#mensagem');
const submitButton = document.querySelector('#submit-button');

if (menuButton) {
    menuButton.addEventListener('click', toggleNavbar);
}

// retirando a borda de erro caso user comece a digitar
if (formInputs) {
    formInputs.forEach((input) => {
        input.addEventListener('input', (e) => {
            e.target.classList.remove('erro');
            e.target.setCustomValidity("");
        });

        input.addEventListener('invalid', (e) => {
            e.preventDefault(); // impede a mensagem nativa em inglês

            if (e.target.validity.valueMissing) {
                e.target.setCustomValidity('Por favor, preencha este campo.');
            } else if (e.target.validity.typeMismatch || e.target.validity.patternMismatch) {
                e.target.setCustomValidity('Por favor, insira um formato válido.');
            }

            e.target.reportValidity();
        });
    });
}

if (messageArea) {
    messageArea.addEventListener('input', charCount);
}

if (submitButton) {
    submitButton.addEventListener('click', validarEEnviarForm);
}

// OBS: não precisa chamar esse resetForm() pelo DOMContentLoaded, pois
// estamos usando 'defer' na tag script do HTML
resetForm(form);
