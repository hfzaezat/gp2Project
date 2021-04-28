#include "stack.h"
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

int const SIZE = 100;
int main() {
  stack pile;
  queue deck;
  char temp[SIZE];
  char temp1[SIZE];
  char *question;
  char *answer;
  ifstream file_in;
  file_in.open("trivial.txt");
  if (file_in) {
    file_in.get(temp, SIZE, '?');
    while (!file_in.eof()) {
      file_in.ignore(SIZE, '?');
      file_in.get(temp1, SIZE, '\n');
      file_in.ignore(SIZE, '\n');
      question = new char[strlen(temp) + 1];
      strcpy(question, temp);
      answer = new char[strlen(temp1) + 1];
      strcpy(answer, temp1);
      card_type acard;
      acard.create_card(question, answer);
      deck.enqueue(acard);
      delete[] question;
      delete[] answer;
      file_in.get(temp, SIZE, '?');
    }
    file_in.close();
  }
  int score = 0;
  card_type receiver;
  char user_answer[SIZE];
  char response;
  while (score < 5) {
    if (pile.peek() == 0) {
      cout << "stack is empty\n" << endl;
      deck.display_question();
      deck.dequeue(receiver);
    } else {
      cout << "Do you want to answer this question(Y/N)?";
      cin >> response;
      cin.ignore(SIZE, '\n');
      if (toupper(response) == 'N') {
        deck.display_question();
        deck.dequeue(receiver);
      } else
        pile.pop(receiver);
    }
    cout << "Enter your answer:";
    cin.get(user_answer, SIZE, '\n');
    cin.ignore(SIZE, '\n');
    if (receiver.evaluate(user_answer) == 1) {
      ++score;
      cout << "\n___________" << endl;
      cout << "Right!" << endl;
      cout << "your score is: " << score << endl;
      deck.enqueue(receiver);
    } else {
      cout << "\n___________" << endl;
      cout << "Wrong!\nContinue." << endl;
      pile.push(receiver);
    }
  }
  if (score == 5)
    cout << "You win!" << endl;
  else
    cout << "Game over." << endl;
  return 0;
}
