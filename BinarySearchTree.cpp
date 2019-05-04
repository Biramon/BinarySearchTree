#include "BinarySearchTree.h"
#include <vector>
#include <math.h>
#include <queue>
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
        if(valor == auxiliar->getValor())
        {
            cout<<"Valor que vc deseja inserir, ja existe na arvore"<<endl;
            return;
        }
        else if(valor <= auxiliar->getValor() && auxiliar->getLeft() != NULL)
        {
            auxiliar = auxiliar->getLeft();
        }
        else if(valor >= auxiliar->getValor() && auxiliar->getRight() != NULL)
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
}
    //remo��o
void BinarySearchTree::removeTree(int valor)
{
    if(this->quantidadeElementos==0)
    {
        cout<<"Nao ha elementos para remorcao"<<endl;
        return;
    }
    if(this->quantidadeElementos==1 && root->getValor()==valor)
    {
        this->root = NULL;
        this->quantidadeElementos--;
        return;
    }
    Node* auxiliar = new Node();
    Node* auxiliarB = new Node();
    auxiliar = this->root;
    int i=0;
    int j=0;
    vector<Node*> aux;
    vector<Node*> auxB;
    while(auxiliar!= NULL)
    {
        aux.push_back(auxiliar);
        //caso n�o haja filhos
        if(auxiliar->getValor()==valor && auxiliar->getRight()==NULL && auxiliar->getLeft()==NULL)
        {
            if(aux[i-1]->getRight()==auxiliar)
            {
                aux[i-1]->setRight(NULL);
                this->quantidadeElementos--;
                return;
            }
            else
            {
                aux[i-1]->setLeft(NULL);
                this->quantidadeElementos--;
                return;
            }
        }
        //caso haja filhos apenas um filho
        if((auxiliar->getValor()==valor) && (auxiliar->getLeft()==NULL || auxiliar->getRight()==NULL))
        {
            if(auxiliar->getLeft()==NULL)
            {
                aux[i-1]->setRight(auxiliar->getRight());
                this->quantidadeElementos--;
                return;
            }
            else if(auxiliar->getRight()==NULL)
            {
                aux[i-1]->setLeft(auxiliar->getLeft());
                this->quantidadeElementos--;
                return;
            }
        }
        //caso haja filhos pela direita e esquerda
        if((auxiliar->getValor()==valor) && (auxiliar->getLeft()!=NULL) && (auxiliar->getRight()!=NULL))
        {
            //vamos pegar o n� minimo da cadeia
            auxiliarB = auxiliar->getRight();
            auxB.push_back(auxiliarB);
            while(auxiliarB!=NULL)
            {
                auxiliarB = auxiliarB->getLeft();
                auxB.push_back(auxiliarB);
                j++;
            }
            auxiliarB = auxB[j-1];
            //Mantem a sequencia da �rvore.
            if(auxB[j-1]->getRight()==NULL && auxB.size()>2)
            {
                auxB[j-2]->setLeft(NULL);
            }
            else if(auxB[j-1]->getRight()!=NULL && auxB.size()>2)
            {
                auxB[j-2]->setLeft(auxB[j-1]->getRight());
            }
            //caso que o n� � terminal
            else
            {
                auxiliar->setRight(NULL);
            }
            //Atualiza o minimo achado
            auxB[j-1]->setRight(auxiliar->getRight());
            auxB[j-1]->setLeft(auxiliar->getLeft());
            //Atualiza n� pai ao n� que vai ser removido
            if(i==0)
            {
                this->setRoot(auxB[j-1]);
            }
            else
            {
                if(aux[i-1]->getRight()==auxiliar)
                {
                    aux[i-1]->setRight(auxB[j-1]);
                }
                else if(aux[i-1]->getLeft()==auxiliar)
                {
                    aux[i-1]->setLeft(auxB[j-1]);
                }
            }
            cout<<auxB.size()<<endl;
            this->quantidadeElementos--;
            return;
        }
        //Atualizadores
        if(auxiliar->getValor()>valor)
        {
            auxiliar = auxiliar->getLeft();
        }
        else if(auxiliar->getValor()<valor)
        {
            auxiliar = auxiliar->getRight();
        }
        //iteradores
        i++;
    }
}
string BinarySearchTree::toString()
{
    string porNivel;
    queue<Node*> Queue;
    Node* aux = new Node();
    Queue.push(this->root);
    while( !Queue.empty() )
    {
        aux = Queue.front();
        Queue.pop();
        porNivel = porNivel + to_string(aux->getValor());
        if(aux->getLeft() != NULL)
        {
            Queue.push(aux->getLeft());
        }
        if(aux->getRight() != NULL)
        {
            Queue.push(aux->getRight());
        }
        porNivel = porNivel + "  ";
    }
    return porNivel;
}
int BinarySearchTree::mediana()
{
    int mediana;
    if(quantidadeElementos==0)
    {
        cout<<"N�o h� mediana, pois n�o existe elementos v�lidos da �rvore"<<endl;
        return 0;
    }

}
bool BinarySearchTree::ehCompleta()
{
    if(this->quantidadeElementos==0)
    {
        return false;
    }
    else
    {
        int altura = this->heightTree(this->root);
        int quantidadeMinima = pow(2,altura-1);
        int quantidadeMaxima = pow(2,altura) -1;
        if(this->quantidadeElementos>=quantidadeMinima&&this->quantidadeElementos<=quantidadeMaxima)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool BinarySearchTree::ehCheia()
{
    int altura = this->heightTree(this->root);
    int quantidadeMaxima = pow(2,altura) -1;
    if( this-> quantidadeElementos == 0)
    {
        return false;
    }
    else
    {
        if(this->quantidadeElementos==quantidadeMaxima)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void BinarySearchTree::printTree(Node* r)
{
    if(r!=NULL)
    {
        this->printTree(r->getLeft());
        cout<<r->getValor()<<" ";
        this->printTree(r->getRight());
    }
    else
    {
        return;
    }
}
int BinarySearchTree::heightTree(Node* r)
{
    if(r != NULL)
    {
        int heightLeft = heightTree(r->getLeft());
        int heightRight = heightTree(r->getRight());
        if (heightLeft < heightRight)
        {
            return heightRight + 1;
        }
        else
        {
            return heightLeft + 1;
        }
    }
    else
    {
       return 0;
    }
}


