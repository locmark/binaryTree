#include <iostream>
#include <cstdlib>
#include <iomanip>


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


void getHeightOfTree (leaf* l, int &heightMax, int actualHeight) {
  if (actualHeight > heightMax)
    heightMax = actualHeight;
  if (l->right != NULL)
    getHeightOfTree (l->right, heightMax, actualHeight+1);
  if (l->left != NULL)
    getHeightOfTree (l->left, heightMax, actualHeight+1);
}


void draw (leaf* l, int height, int actualHeight) {
  if (l != NULL) {
    draw (l->right, height, actualHeight+1);
    cout << setw(actualHeight*4) <<  l->value << endl;
    draw (l->left, height, actualHeight+1);
  } else if (actualHeight <= height) {
    for (size_t i = 0; i < height-actualHeight+1; i++) {
      cout << endl;
    }
  }
}


void drawTree (leaf* root) {
  int height = 0;
  if (root != NULL) {
    getHeightOfTree(root, height, 1);
    draw(root, height, 1);
  }
}


void menu (leaf* &root, bool &endApp) {
  int choice;
  cout << "1> Add new element" << endl;
  cout << "2> Remove an element" << endl;
  cout << "3> Draw bin tree" << endl;
  cout << "4> height" << endl;
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
      drawTree(root);
      break;
    case 4: // get height
      int height = 0;
      if (root != NULL)
        getHeightOfTree(root, height, 1);
      cout << "height: " << height << endl;
      break;
  }
}


int main (int argc, char const *argv[]) {
  leaf* root = NULL;
  bool endApp = false;
  addElement(10, root);
  addElement(5, root);
  addElement(4, root);
  addElement(80, root);
  addElement(7, root);
  while (!endApp) {
    menu(root, endApp);
    system("pause");
    system("cls");
  }

  // root = new leaf();


  return 0;
}
