
#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <iostream>

#define CONST 28//n� de filhos do no

using namespace std;

class Trie {
private:
    class Node {// no da arvore
    public:
        Node *pNode[CONST];//filhos
        char *word;//palavra(somente nos externos tem palavra)
        Node() {//construtor do no
            for(int j=0; j<CONST; j++)
                pNode[j]=nullptr;
            word=nullptr;
        };
    };
    Node *root;//ponteiro da raiz
    void Insert(char keys[],Node *p,int i);//segunda etapa da fun��o insert
    void Insert(char keys[],char aux[],Node *p,int i);//terceira etapa da fun��o insert
    string Search(char keys[],Node *p,int i);//segunda etapa da fun��o search
    void Suggest(Node *p);//fun��o de sugest�o de palavras
    void Creator();
public:

    void Insert(char keys[]);//primeira etapa da fun��o insert
    string Search(char keys[]);//primeira etapa da fun��o search

    Trie() {//construtor da raiz
        root=nullptr;
        Creator();
    };
};



#endif // TRIE_H_INCLUDED
