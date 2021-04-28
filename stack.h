#include "queue.h"
int const MAX = 5;

struct s_node {
  card_type *card;
  s_node *next;
};

class stack {
public:
  stack();
  ~stack();
  int push(card_type &to_add);
  int pop(card_type &to_pop);
  int peek();
  int displayall();

private:
  s_node *head;
  int top_index;
};
