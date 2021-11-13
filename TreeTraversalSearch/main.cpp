#include <iostream>
#include <list>
#include <queue>
using namespace std;

#define SPACE 8

class Node {
  public:  
  Node *left;
  Node *right;
  int value;  
    Node (int value) {
      this->left = NULL;
      this->right = NULL;
      this->value = value;
    }
};

class Tree {
  public:
    Node *root;
    Tree () {
      this->root = NULL;
    }
    void insert (int value);
    bool lookup (int value);
    void display (Node *currNode, int space);
    void remove (int value);
    list<int> breadthFirstSearch();
    list<int> breadthFirstSearchRec(queue<Node*> tmpQueue, list<int> retList);
    list<int> depthFirstSearchInOrder (Node* currNode, list<int> &retList);
    list<int> depthFirstSearchPreOrder (Node* currNode, list<int> &retList);
    list<int> depthFirstSearchPostOrder (Node* currNode, list<int> &retList);
};

void Tree::insert(int value) 
{
  Node *newNode = new Node (value);
  if (this->root == NULL) {
    this->root = newNode;
  }
  else {
    Node *currNode = this->root;
    while (true) {
      if (value < currNode->value) {
        if (!currNode->left) {
          currNode->left = newNode;
          return;
        }
        currNode = currNode->left;
      }
      else {
        if (!currNode->right) {
          currNode->right = newNode;
          return;
        }
        currNode = currNode->right;
      }
    }
  }
}

bool Tree::lookup(int value) 
{
  if (this->root) {
    Node *currNode = this->root;

    while (currNode) {
      if (value < currNode->value) {
        currNode = currNode->left;
      }
      else if (value > currNode->value) {
        currNode = currNode->right;
      }
      else {
          return true;
      }
    }
  }
  return false;  
}

void Tree::display(Node *currNode, int space) 
{
  if (currNode == NULL)
    return;
  space += SPACE;
  display(currNode->right, space);
  cout << endl;
  for (int i = SPACE; i < space; i++)
    cout << " "; 
  cout <<currNode->value << "\n";
  display(currNode->left, space);
    
}

void Tree::remove(int value) 
{

  if (this->root) {
    Node *currNode = this->root;
    Node *parentNode = NULL;
    while (currNode) {
      
      if (value < currNode->value) {
        parentNode = currNode;
        currNode = currNode->left;
      }
      else if (value > currNode->value) {
        parentNode = currNode;
        currNode = currNode->right;
      }
      else {
        // Delete leaf node
        if ((!currNode->left) && (!currNode->right)) {
          if (currNode == parentNode->left){
            parentNode->left = NULL;
          }
          else {
            parentNode->right = NULL;
          }
          return;
        }
        //delete parent node which has one child
        else if ((!currNode->left) || (!currNode->right)) {
          if (currNode == parentNode->left){
            if (currNode->left){
              parentNode->left = currNode->left;
            }
            else {
              parentNode->left = currNode->right;
            }
          }
          else {
            if (currNode->left){
              parentNode->right = currNode->left;
            }
            else {
              parentNode->right = currNode->right;
            }
          }
          return;
        }
        //delete parent node which has two child        
        else {
          Node *temp = currNode->right;
          if (temp->left == NULL && temp->right == NULL)
          {
              currNode->value = temp->value;
              currNode->right = NULL;
              return;
          }
          else if (temp->left == NULL && temp->right != NULL)
          {
              currNode->value = temp->value;
              currNode->right = temp->right;
              return;
          }
          while (temp->left != NULL)
          {
           
              parentNode = temp;
              temp = temp->left;
          }
          currNode->value = temp->value;
          parentNode->left = NULL;
          return;
        }
      }
    }
  }
}

list<int> Tree::breadthFirstSearch()
{
  Node *currNode = this->root;
  list<int> returnList;
  queue<Node*> queueForSearch;

  queueForSearch.push(currNode);
  while (!queueForSearch.empty())
  {
    currNode = queueForSearch.front();
    queueForSearch.pop();
    returnList.push_back(currNode->value);

    if (currNode->left) 
    {
      queueForSearch.push(currNode->left);
    }
    if (currNode->right) 
    {
      queueForSearch.push(currNode->right);
    }    
  }

  return returnList;
}

list<int> Tree::breadthFirstSearchRec(queue<Node*> tmpQueue, list<int> retList)
{
  if (tmpQueue.empty())
  {
    return retList;
  }

  Node *currNode = tmpQueue.front();
  tmpQueue.pop();
  retList.push_back(currNode->value);

  if (currNode->left) 
  {
    tmpQueue.push(currNode->left);
  }
  if (currNode->right) 
  {
    tmpQueue.push(currNode->right);
  }     

  return breadthFirstSearchRec (tmpQueue, retList);
}

list<int> Tree::depthFirstSearchInOrder (Node* currNode, list<int> &retList) 
{
  if (currNode->left)
  {
    depthFirstSearchInOrder(currNode->left, retList);
  }
  retList.push_back(currNode->value);
  if (currNode->right) 
  {
    depthFirstSearchInOrder(currNode->right, retList);
  }

  return retList;
}

list<int> Tree::depthFirstSearchPreOrder (Node* currNode, list<int> &retList) 
{
  retList.push_back(currNode->value);
  if (currNode->left)
  {
    depthFirstSearchPreOrder(currNode->left, retList);
  }
  if (currNode->right) 
  {
    depthFirstSearchPreOrder(currNode->right, retList);
  }

  return retList;
}

list<int> Tree::depthFirstSearchPostOrder (Node* currNode, list<int> &retList) 
{
  if (currNode->left)
  {
    depthFirstSearchPostOrder(currNode->left, retList);
  }
  if (currNode->right) 
  {
    depthFirstSearchPostOrder(currNode->right, retList);
  }
  retList.push_back(currNode->value);

  return retList;
}

void display (list<int> myList)
{ 
  for (auto i : myList)
    cout<<i<<" ";
  cout<<endl;
}


int main() {
  Tree myTree;
  list<int> bfsRec, bfs, dfsInOrder, dfsPreOrder, dfsPostOrder;
  myTree.insert(41);
  myTree.insert(20);
  myTree.insert(11);
  myTree.insert(29);
  myTree.insert(32);
  myTree.insert(65);
  myTree.insert(50);
  myTree.insert(91);
  myTree.insert(72);
  myTree.insert(99);
  myTree.insert(5);
  myTree.insert(19);
  myTree.insert(75);
  myTree.insert(26);
  myTree.insert(55);

  cout<<endl<<endl;
  myTree.display(myTree.root, 3); 

  bfs = myTree.breadthFirstSearch();

  queue<Node*> queueForRec;
  queueForRec.push(myTree.root);  

  bfsRec = myTree.breadthFirstSearchRec(queueForRec, bfsRec);

  dfsInOrder = myTree.depthFirstSearchInOrder(myTree.root, dfsInOrder);
  dfsPreOrder = myTree.depthFirstSearchPreOrder(myTree.root, dfsPreOrder);
  dfsPostOrder = myTree.depthFirstSearchPostOrder(myTree.root, dfsPostOrder);


  display (bfs);
  display (bfsRec);
  display (dfsInOrder);
  display (dfsPreOrder);
  display (dfsPostOrder);
} 