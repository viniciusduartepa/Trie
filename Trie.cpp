#include <iostream>
#include <string.h>
#include <cstring>
#include <fstream>
#include <string>
#include "Trie.h"

#define CONST 28

using namespace std;

void Trie::Insert(char keys[]) {
    if(root==nullptr) {//inserção no caso da arvore vazia
        root=new Node();
        root->word=keys;
        return;
    } else {//caso arvore nao esteja vazia
        Insert(keys,root,0);
        return;
    }
}
void Trie::Insert(char keys[],Node *p,int i) {
    int index;//avalia qual o filho correspondente a determinada chave
    if(keys[i]=='\0')
        index=26;
    else if(keys[i]=='-')
        index=27;
    else
        index=keys[i]-'A';
    if(p->pNode[index]==nullptr) {//caso para aquele chave o no nao apresente filhos
        if(p->word==nullptr) {//caso nao seja um nó externo
            p->pNode[index]=new Node();
            p->pNode[index]->word=keys;
            return;
        } else {//caso seja um no externo
            if(strcmp(keys,p->word)!=0) {//palavra ja esta na lista
                Insert(keys,p->word,p,i);
                p->word=nullptr;
                return;
            } else {//caso encontre uma palavra diferente
                return;
            }
        }
    } else {//se o filho para aquela chave avalia a proxima chave
        Insert(keys,p->pNode[index],(i+1));
        return;
    }
}
void Trie::Insert(char keys[],char aux[],Node *p,int i) {//inserção no caso de uma palavra diferente encontrada
    int index;
    if(keys[i]=='\0')
        index=26;
    else if(keys[i]=='-')
        index=27;
    else
        index=keys[i]-'A';
    if(keys[i]==aux[i]) {//se as chaves da duas palavras forem iguais
        p->pNode[index]=new Node();
        Insert(keys,aux,p->pNode[index],(i+1));
        return;
    } else {//caso sejam diferentes
        int index2;
        if(aux[i]=='\0')
            index2=26;
        else if(aux[i]=='-')
            index2=27;
        else
            index2=aux[i]-'A';
        p->pNode[index]=new Node();
        p->pNode[index]->word=keys;
        p->pNode[index2]=new Node();
        p->pNode[index2]->word=aux;
        return;
    }
}
void Trie::Search(char keys[]) {//procura
    if(root==nullptr) {//caso arvore vazia
        cout << "\narvore vazia";
        return;
    } else {//caso arvore nao esteja vazia
        Search(keys,root,0);
        return;
    }
}
void Trie::Search(char keys[],Node *p,int i) {
    int index;
    if(keys[i]=='\0')
        index=26;
    else if(keys[i]=='-')
        index=27;
    else
        index=keys[i]-'A';
    if(p->pNode[index]==nullptr) {//caso o no nao tenha filhos para aquela chave
        if(p->word==nullptr) {//caso nao tenha encontrado nenhuma palavra
            Suggest(p);//sugere todas palavras que tem aquele prefixo
            return;
        } else {//caso tenha encontrado uma palavra
            if(strcmp(keys,p->word)==0) {//palavra encontrada
                cout << keys << " esta na lista";
            } else {//palavra diferente encontrada
                cout << p->word  << " encontrado no lugar de " << keys;
            }
        }
    } else {//caso o no tenha filhos para aquela chave analisa a proxima chave
        Search(keys,p->pNode[index],i+1);
        return;
    }
}
void Trie::Suggest(Node *p) {//sugere todas a palavras que compartilham daquele no
    for(int i=0; i<CONST; i++) {
        if(p->pNode[i]!=nullptr)
            Suggest((p->pNode[i]));
    }
    if(p->word!=nullptr)
        cout << " sugerir" << p->word;
}
void Trie::Creator() {
    fstream file;
    file.open("palavras.txt",fstream::in);
    if(file.is_open()) {
        string line;
        while(getline(file,line)) {
            char *c=new char;
            strcpy(c,line.c_str());
            Insert(c);
        }
        file.close();
    }
}


