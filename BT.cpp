#include <iostream>


using namespace std;


struct leaf {
  int value;
  leaf* left;
  leaf* right;

  leaf () {
    left = NULL;
    right = NULL;
  }

  leaf (int val) {
    value = val;
    left = NULL;
    right = NULL;
  }
};


void addElement (int value, leaf* &l) {
  if (l == NULL) {
    leaf* newLeaf = new leaf(value);
    l = newLeaf;
  } else {
    if (value >= l->value)
      addElement(value, l->right);
    else
      addElement(value, l->left);
  }
}


void menu (leaf* &root, bool &endApp) {
  int choice;
  cout << "1> Add new element" << endl;
  cout << "2> Remove an element" << endl;
  cout << "3> Draw bin tree" << endl;
  cout << "0> End app" << endl;

  cout << "> ";
  cin >> choice;

  switch (choice) {
    case 0: // end app
      endApp = true;
      break;
    case 1: // add element
      int value;
      cout << "value > ";
      cin >> value;
      addElement(value, root);
      break;
    case 2: // remove element

      break;
    case 3: // draw tree

      break;
  }
}



int main (int argc, char const *argv[]) {
  leaf* root = NULL;
  bool endApp = false;
  while (!endApp)
    menu(root, endApp);
  // root = new leaf();


  return 0;
}
