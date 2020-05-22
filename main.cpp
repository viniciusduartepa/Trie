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
public:
    void Insert(char keys[]);
    void Search(char keys[]);
    void Suggest(Node *p);
    void Show(){
    cout << root->pNode[12]->pNode[4]->pNode[20]->word << " " << root->pNode[24]->word << " " << root->pNode[12]->pNode[8]->word;
    cout << " " << root->pNode[12]->pNode[4]->pNode[11]->word << " " << root->pNode[1]->word << " " << root->pNode[12]->pNode[4]->pNode[26]->word;
    cout << " " << root->pNode[12]->pNode[4]->pNode[27]->word;
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
    }
    Node *p=root;
    for(int i=0; i<=strlen(keys); i++) {
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
                if(strcmp(keys,p->word)==0)
                    return;
                Node *p2=p;
                int index1,index2;
                for(int j=i; j<=strlen(keys); j++) {
                    if(*(p->word+j)==keys[j]) {
                        if(keys[i]=='\0')
                            index1=26;
                        else if(keys[i]=='-')
                            index1=27;
                        else
                            index1=keys[i]-'a';
                        p2->pNode[index1]=new Node();
                        p2=p2->pNode[index1];
                    } else {
                        if(keys[i]=='\0')
                            index1=26;
                        else if(keys[i]=='-')
                            index1=27;
                        else
                            index1=keys[i]-'a';
                        if(*(p->word+j)=='\0')
                            index2=26;
                        else if(*(p->word+j)=='-')
                            index2=27;
                        else
                            index2=*(p->word+j)-'a';
                        p2->pNode[index1]=new Node();
                        p2->pNode[index1]->word=keys;
                        p2->pNode[index2]=new  Node();
                        p2->pNode[index2]->word=p->word;
                        p->word=nullptr;
                        return;
                    }
                }
            }
        } else {
            p=p->pNode[index];
        }
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
            if(p->word==nullptr){
                Suggest(p);
                return;
            }
            else {
                if(strcmp(p->word,keys)==0){
                    cout << "\n" << keys << " esta na arvore";
                    return;
                }
                else{
                    cout << "\n" << p->word << " encontrado no lugar de " << keys;
                    return;
                }
            }
        } else
            p=p->pNode[index];
    }
}
void Trie::Suggest(Node *p){
    for(int i=0;i<CONST;i++){
        if(p->pNode[i]!=nullptr)Suggest((p->pNode[i]));
    }
    if(p->word!=nullptr)cout << " sugerir" << p->word;
}

int main() {
    Trie t;
    t.Insert("meu");
    t.Insert("you");
    t.Insert("mio");
    t.Insert("melhor");
    t.Insert("bosta");
    t.Insert("me");
    t.Insert("me-");
    t.Insert("bosgo");
    t.Insert("meu");
    t.Search("bos");

    //t.Show();
    return 0;
}
