struct Node{
  Node *parent;
  Node *left, *right;
  int value;
};

struct Tree{
  Node *root;
}

Node* getMinimum(Node* n){
  //not empty tree
  if(n != null){
    return null;
  }
  Node* p;
  //loop invariant : p는 항상 왼쪽 최하위 노드의 부모를 가진다.
  //종료시 최 하위루트는 nil이므로 그 부모노드 p가 가장 작은 노드를 가진다.
  while(n->left != null){
    p = n;
    n = n->left;
  }
  return p;
}

Node* getSuccessor(Node *n){
  if(n->right != null){
    return getMinimum(n.right)
  }

  //loop invariant : loop가 반복됨에 따라 n은 그 부모의 오른쪽자식만을 가리킨다.
  //좀 고쳐야돼. 
  while(n->p != nil && n->p->right == n){
    n = n->p;
  }
  return n->p;
}

void in_order_walk(Node *n){
  if(n != null){
    in_order_walk(n->left);
    printf(n->value);
    in_order_walk(n->right);
  }
}

void insert_node(Node* T, int value){
  Node n;
  n.value = value;

  while(
}
