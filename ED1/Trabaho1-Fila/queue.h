struct Node{
  int num;
  struct Node *prox;
};

typedef struct Node node;

node* start(node *first, node *last);

node* push(int value, node *first, node *last);

int pop(node *last, node *first);

int full(node *first, node *last);

int empty(node *first);
