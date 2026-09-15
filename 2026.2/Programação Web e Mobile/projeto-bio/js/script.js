// Toggle pra abrir menu navbar
const menuButton = document.querySelector('#navbar-toggle');
const navbarMenu = document.querySelector('#navbar');

menuButton.addEventListener('click', () => {
    navbarMenu.classList.toggle('hidden');
    menuButton.classList.toggle('active');
});

// Fechar navbar assim que clicar em link
const navbarLinks = document.querySelectorAll('#navbar a');
const headerHeight = document.querySelector('header').offsetHeight;

navbarLinks.forEach(link => {
    link.addEventListener('click', (e) => {
        e.preventDefault();

        const targetId = link.getAttribute('href');
        const targetSection = document.querySelector(targetId);

        if (targetSection) {
            // 1. Calcula a posição top da seção descontando a altura do header
            const targetPosition = targetSection.getBoundingClientRect().top + window.scrollY - headerHeight;

            // 2. Executa a rolagem suave pela janela (window)
            window.scrollTo({
                top: targetPosition,
                behavior: 'smooth'
            });
        }

        // 3. Adiciona um pequeno delay antes de esconder o menu para não interromper o scroll
        setTimeout(() => {
            navbarMenu.classList.add('hidden');
            menuButton.classList.remove('active');
        }, 100);
    });
});

// Botão de descer p prox seção
const nextButton = document.querySelector('#arrow-container button');
const sections = document.querySelectorAll('main section');

nextButton.addEventListener('click', () => {
    // Descobre qual seção está visível na tela no momento
    const currentScroll = window.scrollY + window.innerHeight / 2;

    for (let i = 0; i < sections.length; i++) {
        const sectionTop = sections[i].offsetTop;
        const sectionBottom = sectionTop + sections[i].offsetHeight;

        if (currentScroll >= sectionTop && currentScroll <= sectionBottom) {
            // Se houver uma próxima seção, rola até ela
            if (i + 1 < sections.length) {
                sections[i + 1].scrollIntoView({
                    behavior: 'smooth',
                    block: 'center'
                });
            } else {
                // Se já estiver na última seção, volta para a primeira
                sections[0].scrollIntoView({
                    behavior: 'smooth',
                    block: 'center'
                });
            }
            break;
        }
    }
});
