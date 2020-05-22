#ifndef TRIE_H_INCLUDED
#define TRIE_H_INCLUDED

#define CONST 28//n° de filhos do no

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
    void Search(char keys[],Node *p,int i);//segunda etapa da função search
    void Suggest(Node *p);//função de sugestão de palavras
public:
    void Insert(char keys[]);//primeira etapa da função insert
    void Search(char keys[]);//primeira etapa da função search

    Trie() {//construtor da raiz
        root=nullptr;
    };
};



#endif // TRIE_H_INCLUDED
