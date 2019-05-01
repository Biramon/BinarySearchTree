#include "BinarySearchTree.h"
//construtor
BinarySearchTree::BinarySearchTree()
{
    this->setRoot(NULL);
    this->setQuantidadeElementos(0);
}
//m�todos sets
void BinarySearchTree::setQuantidadeElementos(int quantidade)
{
    this->quantidadeElementos = quantidade;
}
void BinarySearchTree::setRoot(Node* node)
{
    this->root = node;
}
//m�todos gets
Node* BinarySearchTree::getRoot()
{
    return this->root;
}
int BinarySearchTree::getQuantidadeElementos()
{
    return this->quantidadeElementos;
}
//inser��o
void BinarySearchTree::insertTree(int valor)
{
    Node* inserir = new Node(valor);
    if(this->root==NULL)
    {
        this->root = inserir;
        this->quantidadeElementos++;
        return;
    }
    Node* auxiliar = new Node();
    auxiliar = this->root;
    while(auxiliar!=NULL)
    {
        if(valor < auxiliar->getValor() && auxiliar->getLeft() != NULL)
        {
            auxiliar = auxiliar->getLeft();
        }
        else if(valor > auxiliar->getValor() && auxiliar->getRight() != NULL)
        {
            auxiliar = auxiliar->getRight();
        }
        else if(valor < auxiliar->getValor() && auxiliar->getLeft() == NULL)
        {
            auxiliar->setLeft(inserir);
            this->quantidadeElementos++;
            return;
        }
        else if(valor > auxiliar->getValor() && auxiliar->getRight() == NULL)
        {
            auxiliar->setRight(inserir);
            this->quantidadeElementos++;
            return;
        }
    }
    //remo��o

}
