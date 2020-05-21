#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;
#define ALPHABET_SIZE 26

class Trie {
private:
    class Node {
    public:
        Node *pNode[ALPHABET_SIZE];
        char *word;
        Node() {
            for(int j=0; j<ALPHABET_SIZE; j++)
                pNode[j]=nullptr;
                word=nullptr;
        };
    };
    Node *root;
public:
    void Insert(char keys[]);
    /*void Show(){
    cout << root->pNode[12]->pNode[4]->word << " " << root->pNode[24]->word << " " << root->pNode[12]->pNode[8]->word;
    };*/
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
    for(int i=0; keys[i]!='\0'; i++) {
        int index=keys[i]-'a';
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
                for(int j=i; keys[j]!='\0'; j++) {
                    if(*(p->word+j)==keys[j]) {
                        index1=keys[j]-'a';
                        p2->pNode[index1]=new Node();
                        p2=p2->pNode[index1];
                    } else {
                        index1=keys[j]-'a';
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
        }else{
        p=p->pNode[index];
        }
    }
}
int main() {
   /* Trie t;
    t.Insert("meu");
    t.Insert("you");
    t.Insert("mio");
    t.Show();*/
    return 0;
}
