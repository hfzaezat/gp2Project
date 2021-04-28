#include "stack.h"
#include <cctype>
#include <cstring>
#include <iostream>

stack::stack() {
  top_index = 0;
  head = NULL;
}

stack::~stack() {
  s_node *temp;
  while (head != NULL) {
    temp = head->next;
    delete[] head->card;
    delete head;
    head = temp;
  }
}

int stack::push(card_type &to_add) {
  if (head == NULL) {
    top_index = 0;
    head = new s_node;
    head->card = new card_type[MAX];
    head->next = NULL;
    head->card[top_index].copy_card(to_add);
    ++top_index;
    return 1;
  } else if (top_index < 5) {
    head->card[top_index].copy_card(to_add);
    ++top_index;
    return 1;
  } else {
    top_index = 0;
    s_node *temp = new s_node;
    temp->card = new card_type[MAX];
    temp->card[top_index].copy_card(to_add);
    ++top_index;
    temp->next = head;
    head = temp;
    return 1;
  }
  return 0;
}

int stack::pop(card_type &to_pop) {
  if (head == NULL) {
    return 0;
  } else if (top_index > 0) {
    --top_index;
    head->card[top_index].get_card(to_pop);
    return 1;
  } else if (top_index == 0) {

    s_node *temp = head->next;
    temp->card[4].get_card(to_pop);
    delete[] head->card;
    delete head;
    head = temp;
    top_index = 5;
    return 1;
  }
  return 0;
}

int stack::peek() {
  if (!head)
    return 0;
  else if (top_index > 0) {
    head->card[top_index - 1].display_question();
    return 1;
  }
  s_node *temp = head->next;
  if (temp != NULL) {
    temp->card[4].display_question();
    return 1;
  }
  return 0;
}

int stack::displayall() {
  int current = top_index;
  for (s_node *temp = head; temp != NULL; temp = temp->next) {
    for (int i = current; i > 0; --i) {
      temp->card[i - 1].display_question();
      temp->card[i - 1].display_answer();
    }
    current = 5;
  }
  return 1;
}
