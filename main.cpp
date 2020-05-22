#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;
#define CONST 28

class Trie {
private:
    class Node {
    public:
        Node *pNode[CONST];
        char *word;
        Node() {
            for(int j=0; j<CONST; j++)
                pNode[j]=nullptr;
            word=nullptr;
        };
    };
    Node *root;
    void Insert(char keys[],Node *p,int i);
    void Insert(char keys[],char aux[],Node *p,int i);
    void Suggest(Node *p);
public:
    void Insert(char keys[]);
    void Search(char keys[]);
    void Show() {
        cout << root->pNode[12]->pNode[4]->pNode[26]->word<< " " << root->pNode[14]->word;
        cout << " " << root->pNode[12]->pNode[4]->pNode[20]->word;
    };
    Trie() {
        root=nullptr;
    };
};
void Trie::Insert(char keys[]) {
    if(root==nullptr) {
        root=new Node();
        root->word=keys;
        return;
    } else {
        Insert(keys,root,0);
        return;
    }
}
void Trie::Insert(char keys[],Node *p,int i) {
    int index;
    if(keys[i]=='\0')
        index=26;
    else if(keys[i]=='-')
        index=27;
    else
        index=keys[i]-'a';
    if(p->pNode[index]==nullptr) {
        if(p->word==nullptr) {
            p->pNode[index]=new Node();
            p->pNode[index]->word=keys;
            return;
        } else {
            if(strcmp(keys,p->word)==0) {
                return;
            } else {
                char *aux=p->word;
                p->word=nullptr;
                Insert(keys,aux,p,i);
                return;
            }
        }
    } else {
        Insert(keys,p->pNode[index],(i+1));
        return;
    }
}
void Trie::Insert(char keys[],char aux[],Node *p,int i) {
    int index;
    if(keys[i]=='\0')
        index=26;
    else if(keys[i]=='-')
        index=27;
    else
        index=keys[i]-'a';
    if(keys[i]==aux[i]) {
        p->pNode[index]=new Node();
        Insert(keys,aux,p->pNode[index],(i+1));
        return;
    } else {
        int index2;
        if(aux[i]=='\0')
            index2=26;
        else if(aux[i]=='-')
            index2=27;
        else
            index2=aux[i]-'a';
        p->pNode[index]=new Node();
        p->pNode[index]->word=keys;
        p->pNode[index2]=new Node();
        p->pNode[index2]->word=aux;
        return;
    }
}
void Trie::Search(char keys[]) {
    if(root==nullptr) {
        cout << "\narvore vazia";
        return;
    }
    Node *p=root;
    for(int i=0;; i++) {
        int index;
        if(keys[i]=='\0')
            index=26;
        else if(keys[i]=='-')
            index=27;
        else
            index=keys[i]-'a';
        if(p->pNode[index]==nullptr) {
            if(p->word==nullptr) {
                Suggest(p);
                return;
            } else {
                if(strcmp(p->word,keys)==0) {
                    cout << "\n" << keys << " esta na arvore";
                    return;
                } else {
                    cout << "\n" << p->word << " encontrado no lugar de " << keys;
                    return;
                }
            }
        } else
            p=p->pNode[index];
    }
}
void Trie::Suggest(Node *p) {
    for(int i=0; i<CONST; i++) {
        if(p->pNode[i]!=nullptr)
            Suggest((p->pNode[i]));
    }
    if(p->word!=nullptr)
        cout << " sugerir" << p->word;
}

int main() {
    Trie t;
    t.Insert("me");
    t.Insert("ola");
    t.Insert("meu");
    t.Search("o");
    return 0;
}
