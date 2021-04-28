#include "card.h"

struct q_node {
  card_type card;
  q_node *next;
};

class queue {
public:
  queue();
  ~queue();
  int enqueue(card_type &to_add);
  int dequeue(card_type &to_delete);
  int displayall();
  int display_question();

private:
  q_node *rear;
};
