#include "queue.h"
#include <cctype>
#include <cstring>

queue::queue() { rear = NULL; }

queue::~queue() {
  if (rear != NULL) {
    q_node *head = rear->next;
    rear->next = NULL;
    q_node *temp = head->next;
    while (head != NULL) {
      delete head;
      head = head->next;
    }
  }
}

int queue::enqueue(card_type &to_add) {
  if (rear == NULL) {
    rear = new q_node;
    rear->card.copy_card(to_add);
    rear->next = rear;
    return 1;
  }
  q_node *temp = new q_node;
  temp->card.copy_card(to_add);
  temp->next = rear->next;
  rear->next = temp;
  rear = temp;
  return 1;
}

int queue::dequeue(card_type &to_delete) {
  if (rear != NULL) {
    if (rear->next == rear) {
      rear->card.get_card(to_delete);
      delete rear;
      rear = NULL;
      return 1;
    }
    q_node *temp = rear->next;
    temp->card.get_card(to_delete);
    rear->next = temp->next;
    delete temp;
    return 1;
  }
  return 0;
}

int queue::displayall() {
  if (rear == NULL)
    return 0;
  else if (rear->next == rear) {
    rear->card.display_question();
    rear->card.display_answer();
    return 1;
  }
  q_node *temp = rear->next;
  while (temp != rear) {
    temp->card.display_question();
    temp->card.display_answer();
    temp = temp->next;
  }
  rear->card.display_question();
  rear->card.display_answer();
  return 1;
}

int queue::display_question() {
  if (rear != NULL) {
    rear->next->card.display_question();
    return 1;
  }
  return 0;
}
