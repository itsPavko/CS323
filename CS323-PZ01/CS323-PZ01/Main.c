#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <stdarg.h>
#include <stdlib.h>

#include "Main.h"

#define PLAYER_USERNAME 20
#define QUESTION_LENGTH 500
#define ANSWER_LENGTH 100
#define NUMBER_OF_ANSWERS 3
#define YESNO_ANSWER_LENGTH 3


int main() {

	int numberOfQuestions;
	int numberOfQuestionsForFirstLevel;
	int numberOfQuestionsForSecondLevel;
	int numberOfQuestionsForThirdLevel;
	int playerIndex;
	int numberOfPlayers = 0;
	int answerIndexes[] = { 0, 1, 2 };

	FILE* playersFile = fopen("igraci.txt", "w");
	fclose(playersFile);

	QuestionAnswer* questions = readAllSetsOfQuestions(&numberOfQuestions);
	Player* players = readAllPlayers(&numberOfPlayers);

	int jokerFriend = 1;
	int jokerFiftyFifty = 1;
	int jokerAudience = 1;

	fflush(stdout);

	char accAnswer[YESNO_ANSWER_LENGTH];
	char username[PLAYER_USERNAME];
	Player player;

	printf("Unesite korisnicko ime:\n");
	scanf("%s", &username);

	strcpy(player.username, username);
	printf("\nKrecete sa kvizom %s! \n", &player.username);

	printf("-----------------------------------------------------\n");
	printf("Vreme je za kviz! Ukoliko zelite da odustanete potrebno je da ukucate '0' kako bi Vam se obracunao rezultat!\n");
	printf("\n");

	int* awards = readAwards();
	int currentQuestionScore = 0;
	int currentScore = 0;
	int guaranteedScore = 0;

	for (int i = 1; i <= 9; ++i) {
		QuestionAnswer questionAnswer;
		currentQuestionScore = awards[i - 1];

		printf("Pitanje broj %d za %d evra\n", i, currentQuestionScore);
		printf("\n");

		questionAnswer = getQuestion(questions, i - 1);

		printf("%s", questionAnswer.question);
		char correctAnswer[ANSWER_LENGTH];
		strcpy(correctAnswer, questionAnswer.answers[questionAnswer.correctAnswer]);

		printf("A) %s", questionAnswer.answers[answerIndexes[0]]);
		printf("B) %s", questionAnswer.answers[answerIndexes[1]]);
		printf("C) %s", questionAnswer.answers[answerIndexes[2]]);

		if (areJokersAvailable(i, jokerFriend, jokerFiftyFifty, jokerAudience)) {
			printf("\nDa li zelite neku vrstu pomoci? (da/ne)\n");

			char useJoker[YESNO_ANSWER_LENGTH];
			scanf("%s", useJoker);

			if (strcmp(useJoker, "da") == 0) {

				printf("Koju pomoc zelite?\n");
				if (jokerFriend == 1) {
					printf("1. Pomoc prijatelja\n");
				}
				if (jokerFiftyFifty == 1) {
					printf("2. 50-50\n");
				}
				if (jokerAudience == 1) {
					printf("3. Pomoc publike\n");
				}
				printf("Odgovorite rednim brojem pomoci koju zelite.\n");

				int joker;
				scanf("%d", &joker);

				switch (joker) {
				case 1:
					if (jokerFriend == 1) {
						printf("\n");
						phoneFriendJoker();
						jokerFriend = 0;
					}
					else {
						printf("Iskoristili ste ovu pomoc!\n");
					}
					break;
				case 2:
					if (jokerFiftyFifty == 1) {
						printf("\n");
						fiftyFiftyJoker(correctAnswer, &questionAnswer, answerIndexes);
						jokerFiftyFifty = 0;
					}
					else {
						printf("Iskoristili ste ovu pomoc!\n");
					}
					break;
				case 3:
					if (jokerAudience == 1) {
						askTheAudienceJoker();
						jokerAudience = 0;
					}
					else {
						printf("Iskoristili ste ovu pomoc!\n");
					}
					break;
				default:
					printf("Greska!\n");
					return -1;
				}
			}
		}
		printf("Vas konacan odgovor je?\n");

		char playerAnswerLetter;
		while (getchar() != '\n');

		printf("Moj konacan odgovor je ");
		scanf("%c", &playerAnswerLetter);

		if (playerAnswerLetter == '0') {
			printf("Zavrsili ste kviz i osvojili %d evra\n", guaranteedScore);

			player.score = guaranteedScore;
			writePlayers(player);

			break;
		}

		char playerAnswer[ANSWER_LENGTH];
		strcpy(playerAnswer, questionAnswer.answers[answerIndexes[getIndexForAnswer(playerAnswerLetter)]]);
		printf("-----------------------------------------------------\n");

		if (strcmp(playerAnswer, correctAnswer) == 0) {
			printf("Vas odgovor je tacan!\n");
			currentScore = currentQuestionScore;

			if (i == 3 || i == 6) {
				guaranteedScore = currentQuestionScore;
				printf("Osvojili ste zagarantovanu sumu %d evra! Cestitamo!\n", guaranteedScore);
			}
			else if (i == 9) {
				printf("Osvojili ste 200 000 evra!\n");
				player.score = currentQuestionScore;
				writePlayers(player);
			}
		}
		else {
			printf("Vas konacan odgovor %s je netacan!\n", playerAnswer);
			printf("\n");
			printf("Tacan odgovor je %s\n", correctAnswer);
			printf("Zaradili ste zagarantovanu sumu od %d\n", guaranteedScore);

			player.score = guaranteedScore;
			writePlayers(player);

			break;
		}
	}

	free(players);
	free(questions);
	return 0;
}


typedef struct Player {
	char username[PLAYER_USERNAME];
	int score;
} Player;

typedef struct QuestionAnswer {
	char question[QUESTION_LENGTH];
	char answers[NUMBER_OF_ANSWERS][ANSWER_LENGTH];
	int correctAnswer;
	int level; //1,2,3
} QuestionAnswer;

// igrac

Player* readAllPlayers(int* size) {
	FILE* playersFile = fopen("igraci.txt", "r");

	if (!playersFile) {
		perror("Greska pri otvaranju fajla igraci.txt");
		exit(1);
	}

	int playerCounter = 0;
	char buffer[PLAYER_USERNAME];

	while (fgets(buffer, PLAYER_USERNAME, playersFile) != NULL) {
		playerCounter++;
		fgets(buffer, PLAYER_USERNAME, playersFile);
	}

	// Citanje fajla od pocetka
	rewind(playersFile);
	*size = playerCounter;

	Player* playerList = (Player*)malloc(playerCounter * sizeof(Player));

	// Ucitavanje igrača iz datoteke
	for (int i = 0; i < playerCounter; i++) {
		Player player;
		fgets(player.username, PLAYER_USERNAME, playersFile);
		// prvo pojavljivanje str2 u str1 i menja ga za \0
		player.username[strcspn(player.username, "\n")] = '\0';
		fgets(buffer, PLAYER_USERNAME, playersFile);
		// parsiranje stringa u int
		player.score = atoi(buffer);
		playerList[i] = player;
	}

	fclose(playersFile);
	return playerList;
}

void writePlayers(Player player) {
	FILE* playersFile = fopen("igraci.txt", "w");

	if (playersFile == NULL) {
		printf("Greska pri otvaranju datoteke.\n");
		return;
	}
	
	if (fprintf(playersFile, "Igrac: %s\nSuma: %d\n", player.username, player.score) < 0) {
		printf("Greska pri pisanju podataka o igracu %s.\n", player.username);
		fclose(playersFile);
		return;
	}

	fclose(playersFile);
	printf("Uspesno ste upisani u fajl. :)\n");
}

//Awards

int* readAwards() {
	FILE* awardsFile = fopen("nagrade.txt", "r");

	if (awardsFile == NULL) {
		fprintf(stderr, "Greska pri otvaranju datoteke 'nagrade.txt'\n");
		exit(1);
	}

	// izracunavanje broja linija u fajlu
	int numberOfAwards = 0;
	char buffer[1024];
	while (fgets(buffer, sizeof(buffer), awardsFile) != NULL) {
		numberOfAwards++;
	}
	rewind(awardsFile);

	// citanje svih brojeva i smestanje u memoriju
	int* awards = (int*)malloc(numberOfAwards * sizeof(int));

	if (awards == NULL) {
		printf("Greska pri alokaciji memorije\n");
		fclose(awardsFile);
		return NULL;
	}

	int i = 0;
	while (fgets(buffer, sizeof(buffer), awardsFile) != NULL) {
		sscanf(buffer, "%d", &awards[i]);
		i++;
	}

	fclose(awardsFile);
	return awards;
}

// pitanja

QuestionAnswer* readAllSetsOfQuestions(int* size) {
	FILE* questionsFile = fopen("pitanja.txt", "r");

	if (!questionsFile) {
		perror("Greska pri otvaranju fajla pitanja.txt");
		exit(1);
	}

	int questionCount;
	fscanf_s(questionsFile, "%d\n", &questionCount);
	*size = questionCount;

	QuestionAnswer* questionList = (QuestionAnswer*)malloc(questionCount * sizeof(QuestionAnswer));

	for (int i = 0; i < questionCount; i++) {
		QuestionAnswer questionAnswer;
		fgets(questionAnswer.question, QUESTION_LENGTH, questionsFile);

		for (int j = 0; j < 3; j++) {
			fgets(questionAnswer.answers[j], QUESTION_LENGTH, questionsFile);
		}

		fscanf_s(questionsFile, "%d\n", &questionAnswer.correctAnswer);
		fscanf_s(questionsFile, "%d\n", &questionAnswer.level);

		questionList[i] = questionAnswer;
	}

	fclose(questionsFile);
	return questionList;
}


QuestionAnswer getQuestion(QuestionAnswer* questions, int numberOfQuestion) {
	return questions[numberOfQuestion];
}

//Util

int getIndexForAnswer(char letter) {
	switch (letter) {
	case 'A':
	case 'a':
		return 0;
	case 'B':
	case 'b':
		return 1;
	case 'C':
	case 'c':
		return 2;
	default:
		return -1;
	}
}

char getAnswerFromNumber(int number) {
	switch (number) {
	case 0:
		return 'A';
	case 1:
		return 'B';
	case 2:
		return 'C';
	default:
		return -1;
	}
}

int getRandomNumber(int min, int max) {
	srand(time(NULL));
	return rand() % (max - min + 1) + min;
}

int randomPercentage() {
	srand(time(NULL));
	return rand() % 101;
}

//Joker

void phoneFriendJoker() {
	printf("------------------------------------------------------\n");
	printf("Odgovor prijatelja je %c\n", getAnswerFromNumber(getRandomNumber(0, 3)));
	printf("Siguran je %d%%\n", randomPercentage());
	printf("------------------------------------------------------\n");
}

int* getRandomNumbersThatAddUpTo100() {
	int* numbers = (int*)malloc(sizeof(int) * 3);
	int sum = 0;

	// Generiši prva tri slučajna broja i dodaj ih u sumu
	for (int i = 0; i < 3; i++) {
		numbers[i] = getRandomNumber(0, 100 - sum);
		sum += numbers[i];
	}

	return numbers;
}

void askTheAudienceJoker() {
	int* arr = getRandomNumbersThatAddUpTo100();
	printf("------------------------------------------------------\n");
	printf("A) %d%%\n", arr[0]);
	printf("B) %d%%\n", arr[1]);
	printf("C) %d%%\n", arr[2]);
	printf("------------------------------------------------------\n");
}

int getIndexOfCorrectAnswer(char correctAnswer[], QuestionAnswer* question, const int answerIndexes[]) {
	for (int i = 0; i < 4; i++) {
		if (strcmp(correctAnswer, question->answers[answerIndexes[i]]) == 0) {
			return i;
		}
	}
	return -1;
}

void fiftyFiftyJoker(char correctAnswer[], QuestionAnswer* question, int answerIndexes[]) {
	int index = getIndexOfCorrectAnswer(correctAnswer, question, answerIndexes);
	int remainingIndex1;

	do {
		remainingIndex1 = getRandomNumber(0, 2);
	} while (remainingIndex1 == index);

	char letterOfCorrectAnswer = getAnswerFromNumber(index);
	char letterOfRandomAnswer = getAnswerFromNumber(remainingIndex1);

	printf("------------------------------------------------------\n");
	printf("%c) %s", letterOfCorrectAnswer, question->answers[answerIndexes[index]]);
	printf("%c) %s", letterOfRandomAnswer, question->answers[answerIndexes[remainingIndex1]]);
	printf("------------------------------------------------------\n");
}

int areJokersAvailable(int level, int jokerFriend, int jokerFiftyFifty, int jokerAudience) {
	if (level <= 3) {
		return (jokerFriend || jokerFiftyFifty || jokerAudience);
	}
	else {
		return (jokerFriend || jokerFiftyFifty || jokerAudience) ? 1 : 0;
	}
}