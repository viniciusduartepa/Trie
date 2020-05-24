#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#include <iostream>
#include <map>
#define CONST 28//n° de filhos do no

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
    void Insert(char keys[],Node *p,int i);//segunda etapa da função insert
    void Insert(char keys[],char aux[],Node *p,int i);//terceira etapa da função insert
    string Search(char keys[],Node *p,int i);//segunda etapa da função search
    string Suggest(char keys[],Node *p);//função de sugestão de palavras
    void Creator();
    void Suggest(char keys[],Node *p,map<int,string> &mp);
    int indice;
public:
    void Insert(char keys[]);//primeira etapa da função insert
    string Search(char keys[]);//primeira etapa da função search

    Trie() {//construtor da arvore
        indice=3;
        root=nullptr;
        Creator();
    };
};



#endif // TRIE_H_INCLUDED
