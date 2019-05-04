#ifndef BINARYTREE
#define BINARYTREE
#include "node.h"
class BinarySearchTree
{
private:
    Node* root;
    int quantidadeElementos;

public:
    BinarySearchTree();
    //m�todos gets e sets
    void setRoot(Node* node);
    void setQuantidadeElementos(int quantidade);
    Node* getRoot();
    int getQuantidadeElementos();
    //inser��o e remo��o
    void insertTree(int valor);
    void removeTree(int valor);
    string toString();
    int mediana();
    bool ehCheia();
    bool ehCompleta();
    void printTree(Node* r);
    int heightTree(Node* r);
};

#endif // BINARYTREE
