#include "card.h"
#include <cctype>
#include <cstring>
#include <iostream>

card_type::card_type() {
  question = NULL;
  answer = NULL;
}

card_type::~card_type() {
  delete[] question;
  delete[] answer;
}

int card_type::create_card(char *question_source, char *answer_source) {
  if (question_source) {
    question = new char[strlen(question_source) + 1];
    strcpy(question, question_source);
  }
  if (answer_source) {
    answer = new char[strlen(answer_source) + 1];
    strcpy(answer, answer_source);
  }
  return 1;
}

int card_type::copy_card(card_type &copy_from) {
  if (copy_from.question) {
    question = new char[strlen(copy_from.question) + 1];
    strcpy(question, copy_from.question);
  }
  if (copy_from.answer) {
    answer = new char[strlen(copy_from.answer) + 1];
    strcpy(answer, copy_from.answer);
  }
  return 1;
}

int card_type::get_card(card_type &current) {
  current.question = new char[strlen(question) + 1];
  strcpy(current.question, question);
  current.answer = new char[strlen(answer) + 1];
  strcpy(current.answer, answer);
  return 1;
}

int card_type::display_card() {
  if (display_question() == 1 && display_answer() == 1)
    return 1;
  return 0;
}

int card_type::display_question() {
  if (question != NULL) {
    cout << "Q:" << question << endl;
    return 1;
  }
  return 0;
}

int card_type::display_answer() {
  if (answer != NULL) {
    cout << "A:" << answer << endl;
    return 1;
  }
}

int card_type::evaluate(char *user_answer) {
  if (answer != NULL) {
    if (strcmp(answer, user_answer) == 0)
      return 1;
    else
      return 0;
  } else
    return 0;
}
