const startQuizButton = document.getElementById('startQuizButton');
const quizContainer = document.getElementById('quizContainer');
const quizElement = document.getElementById('quiz');
const submitQuizButton = document.getElementById('submitQuizButton');
const exitQuizButton = document.getElementById('exitQuizButton');
const timerElement = document.getElementById('timer');

let timer; // Dichiarazione del timer
let timeLeft = 600; // 10 minuti in secondi
let loadedQuestions; // Variabile per memorizzare le domande caricate

// Evento al click del pulsante di avvio del quiz
startQuizButton.addEventListener('click', () => {
    startQuizButton.style.display = 'none';
    quizContainer.style.display = 'block';
    startTimer();
    loadQuiz();
});

// Evento al click del pulsante di consegna del quiz
submitQuizButton.addEventListener('click', () => {
    clearInterval(timer); // Ferma il timer
    highlightCorrectAnswers(); // Evidenzia le risposte corrette
});

// Evento al click del pulsante di uscita dal quiz
exitQuizButton.addEventListener('click', () => {
    clearInterval(timer); // Ferma il timer
    alert("Uscita dal quiz!"); // Messaggio di uscita in italiano
    resetQuiz(); // Resetta il quiz
});

// Funzione per avviare il timer
function startTimer() {
    timer = setInterval(() => {
        if (timeLeft <= 0) {
            clearInterval(timer); // Ferma il timer quando il tempo è scaduto
            alert("Tempo scaduto! Consegna del quiz."); // Messaggio di tempo scaduto in italiano
            highlightCorrectAnswers(); // Evidenzia le risposte corrette
        } else {
            timeLeft--;
            timerElement.innerText = `Tempo rimanente: ${Math.floor(timeLeft / 60)}:${timeLeft % 60 < 10 ? '0' : ''}${timeLeft % 60}`;
        }
    }, 1000);
}

// Funzione per caricare il quiz dal file JSON
function loadQuiz() {
    fetch('quiz.json')
        .then(response => response.json())
        .then(data => {
            loadedQuestions = shuffleArray(data.questions).slice(0, 10); // Prendi 10 domande casuali

            let quizHTML = '';
            loadedQuestions.forEach((question, index) => {
                quizHTML += `<div class="mb-4"><h5>${question.question}</h5>`;
                question.options = shuffleArray(question.options);
                question.options.forEach(option => {
                    if (question.type === 'single') {
                        quizHTML += `<div class="form-check"><input class="form-check-input" type="radio" name="question${index}" value="${option}" id="q${index}o${option}"><label class="form-check-label" for="q${index}o${option}">${option}</label></div>`;
                    } else if (question.type === 'multiple') {
                        quizHTML += `<div class="form-check"><input class="form-check-input" type="checkbox" name="question${index}" value="${option}" id="q${index}o${option}"><label class="form-check-label" for="q${index}o${option}">${option}</label></div>`;
                    }
                });
                quizHTML += `</div>`;
            });
            quizElement.innerHTML = quizHTML;
        });
}

// Funzione per resettare il quiz
function resetQuiz() {
    quizContainer.style.display = 'none';
    startQuizButton.style.display = 'block';
    quizElement.innerHTML = '';
    timerElement.innerText = '';
    timeLeft = 600;
}

// Funzione per evidenziare le risposte corrette
function highlightCorrectAnswers() {
    loadedQuestions.forEach((question, index) => {
        if (question.type === 'single') {
            const correctElement = document.querySelector(`input[name="question${index}"][value="${question.correct}"]`);
            if (correctElement) {
                correctElement.parentElement.classList.add('bg-success');
            }
        } else if (question.type === 'multiple') {
            question.correct.forEach(correctOption => {
                const correctElement = document.querySelector(`input[name="question${index}"][value="${correctOption}"]`);
                if (correctElement) {
                    correctElement.parentElement.classList.add('bg-success');
                }
            });
        }
    });
    alert("Le risposte corrette sono evidenziate in verde."); // Messaggio in italiano
}

// Funzione per mescolare gli elementi di un array
function shuffleArray(array) {
    for (let i = array.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [array[i], array[j]] = [array[j], array[i]];
    }
    return array;
}
