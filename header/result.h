// For refernce the initial PDF syntax code is given in README.mdd
// https://github.com/mozilla/pdf.js-sample-files/blob/7dbc3700be83936e32d8df04dbb2df8024f38b59/helloworld.pdf
//MY TEST PROJECT
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include <unistd.h>  
int pdf(char name[], char school[], int, int,char path[]);

int pdf(char name[], char school[], int score, int numberOfQuestions,char path[]) {
  int content_length = strlen(name) + strlen(school);
  float page_width = 595.276, page_height = 841.890;
  FILE * file;

  file = fopen("../src/index.html", "wb");
  if (file == NULL) {
    printf("Error opening file.");
    return 1;
  }
fprintf(file, "<!DOCTYPE html>\n");
fprintf(file, "<html lang=\"en\">\n");
fprintf(file, "<head>\n");
fprintf(file, "    <meta charset=\"UTF-8\">\n");
fprintf(file, "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n");
fprintf(file, "    <title>Result Page</title>\n");
fprintf(file, "</head>\n");
fprintf(file, "    <style>\n");
fprintf(file, "        @keyframes rotate {\n");
fprintf(file, "            from {\n");
fprintf(file, "                transform: rotate(0deg);\n");
fprintf(file, "            }\n");
fprintf(file, "            to {\n");
fprintf(file, "                transform: rotate(360deg);\n");
fprintf(file, "            }\n");
fprintf(file, "        }\n");
fprintf(file, "        #clock {\n");
fprintf(file, "            animation: rotate 5s linear infinite;\n");
fprintf(file, "        }\n");
fprintf(file, "    </style>\n");
fprintf(file, "<body style=\"font-family: sans-serif;\">\n");
fprintf(file, "<h1 style=\"text-align:center;color:red;\">&copy;Made by समिप रेग्मी EUCLID 833</h1>\n");
fprintf(file, "<h3 style=\"text-align:center;color:darkgreen;\">FINAL YEAR PROJECT 2080:COMPUTER </h3>\n");
fprintf(file, "<h3 style=\"text-align:center;\">Examify : made on २०८० साउन ३, बुधवार</h3>\n");
fprintf(file, "<h3 style=\"text-align:center;\">Updated on १० माघ २०८०, बुधवार </h3>\n");
fprintf(file, "<br>\n");
fprintf(file,"<div style=\"text-align:center;\"><img src=\"./Logos/image.jpg\" height=\"70px\" width=\"130px\">");
fprintf(file,"<img id=\"clock\"  src=\"./Logos/logo.png\" height=\"65px\" width=\"65px\">");
fprintf(file,"<img src=\"./Logos/dragon.svg\" height=\"65px\" width=\"65px\">");
fprintf(file,"<img src=\"./Logos/college.jpg\" height=\"65px\" width=\"65px\">");
fprintf(file,"</div>");
fprintf(file, "<h2 style=\"text-align:left;text-transform: uppercase;color:rgb(5, 20, 120);\">RESULT AND ANALYSIS</h2>\n");
fprintf(file,"<h3 style=\"display: inline;\">School/College</h2>");
fprintf(file, "<h3 style=\"text-align:left;text-transform: uppercase;color:rgb(5, 120, 10);display: inline;\">: %s</h3>\n", school);
fprintf(file, "<h3 style=\"text-align:left;\">Name: %s</h3>\n", name);
fprintf(file, "<h3 style=\"text-align:left;\">Total Questions: %d</h3>\n", numberOfQuestions);
fprintf(file, "<h3 style=\"text-align:left;\">Score: %d</h3>\n", score);
fprintf(file,"<a href=\"./main.txt\"><p>SEE COMPLETE ANSWERS</p></a>");
fprintf(file,"<hr>");
fprintf(file, "<div id=\"quizContainer\"></div>\n");
fprintf(file, "<script>\n");
fprintf(file, "document.addEventListener('DOMContentLoaded', function () {\n"); //
fprintf(file, "    fetch('%s')\n",path);
fprintf(file, "        .then(response => {\n");
fprintf(file, "            return response.text();\n");
fprintf(file, "        })\n");
fprintf(file, "        .then(mainFileContent => {\n");
fprintf(file, "            const questionsAndAnswers = parseQuestionsAndAnswers(mainFileContent);\n");
fprintf(file, "\n");
fprintf(file, "            return fetch('answer.txt')\n");
fprintf(file, "                .then(response => {\n");
fprintf(file, "                    return response.text();\n");
fprintf(file, "                })\n");
fprintf(file, "                .then(answerFileContent => {\n");
fprintf(file, "                    const userAnswers = answerFileContent.split('\\n').map(answer => answer.trim().toLowerCase()); // Convert to lowercase\n");
fprintf(file, "\n");
fprintf(file, "                    displayQuestionsAndAnswers(questionsAndAnswers, userAnswers);\n");
fprintf(file, "                });\n");
fprintf(file, "        })\n");
fprintf(file, "\n");
fprintf(file, "    function parseQuestionsAndAnswers(content) {\n");
fprintf(file, "        const questions = content.split('\\n\\n');\n");
fprintf(file, "\n");
fprintf(file, "        // Parse each question and answer\n");
fprintf(file, "        return questions.map(question => {\n");
fprintf(file, "            const lines = question.split('\\n');\n");
fprintf(file, "            const text = lines[0];\n");
fprintf(file, "            const correctAnswer = lines[lines.length - 1].split(':')[1].trim().toLowerCase();\n");
fprintf(file, "\n");
fprintf(file, "            return { text, correctAnswer };\n");
fprintf(file, "        });\n");
fprintf(file, "    }\n");
fprintf(file, "\n");
fprintf(file, "function displayQuestionsAndAnswers(questionsAndAnswers, userAnswers) {\n");
fprintf(file, "    const quizContainer = document.getElementById('quizContainer');\n\n");
fprintf(file, "    for (let index = 0; index < %d; index++) {\n",numberOfQuestions);
fprintf(file, "        const qa = questionsAndAnswers[index];\n");
fprintf(file, "        const userAnswer = userAnswers[index].toUpperCase();\n");
fprintf(file, "        const correctAnswer = qa.correctAnswer.toUpperCase();\n");
fprintf(file, "        const isCorrect = userAnswer === correctAnswer;\n\n");
fprintf(file, "        const questionElement = document.createElement('div');\n");
fprintf(file, "        questionElement.innerHTML = `\\\n");
fprintf(file, "            <h3>Question: ${qa.text}</h3>\\\n");
fprintf(file, "            <p>Your answer: ${userAnswer}</p>\\\n");
fprintf(file, "            <p>Correct answer: ${correctAnswer}</p>\\\n");
fprintf(file, "  ${isCorrect ? ' <mark style=\"background-color:Green; color: white;\">Correct</mark>' : '<mark style=\"background-color:Red; color: white;\">Incorrect</mark>'}<br>`;\n");
fprintf(file, "        quizContainer.appendChild(questionElement);\n");
fprintf(file, "    }\n}\n");
fprintf(file, "    }\n)\n");
fprintf(file, "</script>\n");
fprintf(file, "\n");
fprintf(file, "</body>\n");
fprintf(file, "</html>\n");
fclose(file);
printf("THANK YOU RESULT CREATED \n");
printf("PRESS ENTER TO OPEN RESULT\n");

//https://stackoverflow.com/questions/8666378/detect-windows-or-linux-in-c-c
//DETECTING OS WITH C
//UPDATED OS_Windows to _WIN32
// if(getchar())
//   {
//WINDOES CODE UPDATED WITH SERVER .
//DISCARDED PYTHON SERVER

#ifdef _WIN32
//LINUX CODE NOT UPDATED
    system("start http://127.0.0.1:8080/");

#else

//system("python3 -m http.server 8020");
// sleep(2);

system("xdg-open http://localhost:8080");
#endif

  // }

  return 0;
}
