using namespace std;

class card_type {
public:
  card_type();
  ~card_type();
  int create_card(char *question_source, char *answer_source);
  int copy_card(card_type &copy_from);
  int get_card(card_type &current);
  int display_card();
  int display_question();
  int display_answer();
  int evaluate(char *user_answer);

private:
  char *question;
  char *answer;
};
