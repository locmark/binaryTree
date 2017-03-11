#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct node
{
  int value;
  node* left;
  node* right;

  node () 
  {
    left = NULL;
    right = NULL;
  }

  node (int val) 
  {
    value = val;
    left = NULL;
    right = NULL;
  }
};


void addElement (node*& N, int value) 
{
  if (N == NULL) 
  {
    node* newNode = new node(value);
    N = newNode;
  } 
  else 
  {
    if (value >= N->value)
      addElement(N->right, value);
    else
      addElement(N->left, value);
  }
}

void getHeightOfTree (node* N, int &heightMax, int actualHeight) 
{
  if (actualHeight > heightMax)
    heightMax = actualHeight;
  if (N->right != NULL)
    getHeightOfTree(N->right, heightMax, actualHeight+1);
  if (N->left != NULL)
    getHeightOfTree(N->left, heightMax, actualHeight+1);
}

void draw (node* N, int height, int actualHeight) 
{
  if (N != NULL) 
  {
    draw (N->right, height, actualHeight+1);
    cout << setw(actualHeight*4) <<  N->value << endl;
    draw (N->left, height, actualHeight+1);
  } 
  else if (actualHeight <= height) 
  {
    for (size_t i = 0; i < height-actualHeight+1; i++) 
    {
        cout << endl;
    }
  }
}

void drawTree (node* root) 
{
  int height = 0;
  if (root != NULL) 
  {
    getHeightOfTree(root, height, 1);
    draw(root, height, 1);
  }
}

node* findMin (node* N)
{
      while (N->left != NULL) 
            N = N->left;
      return N;
}

void removeNode(node *&N, int value)
{
     if (N == NULL)  //nothing to do, return
        return;
     if (value < N->value) //found value bigger than wanted, go left
          removeNode (N->left, value);
     else if (value > N->value) 
          removeNode (N->right, value); //found value smaller than wanted, go right
     else //found the right value, delete
     {                
         if (N->left == NULL && N->right== NULL) //no chlidren case
         {
              N = NULL;                
         }
         else if(N->left == NULL) //right child case
         {
              N = N->right;
         }
         else if(N->right == NULL) //left child case
         {
              N = N->left;
         }
         else  //both child case
         {
             node *temp = findMin(N->right);
             N->value = temp->value;
             removeNode(N->right, temp->value);
         }
     }
}

void menu (node* root)
{
     int choice, value;
     cout << "1> Add new element" << endl;
     cout << "2> Remove an element" << endl;
     cout << "3> Draw binary search tree" << endl;
     cout << "4> Show height" << endl;
     cout << "0> Quit" << endl;
     cout << "> ";
     cin >> choice;
     switch (choice) 
     {
            case 0: // end app
                 exit(0);
            break;
            case 1: // add element
                 cout << "Value of node to be added > ";
                 cin >> value;
                 addElement(root, value);
                 cout<<"Node has been added successfully!"<<endl;
            break;
            case 2: // remove element
                 cout<<"Value of node to be deleted > ";
                 cin>>value;
                 removeNode(root, value);
                 cout<<"Node has been deleted successfully!"<<endl;                  
            break;
            case 3: // draw tree
                 drawTree(root);
            break;
            case 4: // get height
                 int height = 0;
                 if (root != NULL)
                    getHeightOfTree(root, height, 1);
                 cout << "Height: " << height << endl;
            break;
  }
}

int main (int argc, const char **argv) 
{
    system("COLOR 0A");
    node* root = NULL;

    addElement(root, 15);
    addElement(root, 20);
    addElement(root, 18);
    addElement(root, 22);
    addElement(root, 6);
    addElement(root, 5);
    addElement(root, 8);
    while(true)
    {
       menu(root);
       system("PAUSE");
       system("CLS");
    }
    return 0;
}
