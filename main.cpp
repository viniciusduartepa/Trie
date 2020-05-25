#include <iostream>
#include <string.h>
#include <cstring>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Trie.h"

using namespace std;
void gotoxy(int x, int y) {//funcao de organizar a interface
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}
int menu() {//menu principal
    int n;
    system("cls");
    cout << "###################################################################################################";
    gotoxy(45,2);
    cout << "MENU";
    cout << "\n\n###################################################################################################";
    cout << "\n\n\t\t[ 1 - CORRETOR ORTOGRAFICO ] [ 2 - BUSCAR POR PREFIXO ] [ 3 - SAIR ]";
    gotoxy(43,10);
    cout << "OPCAO -> ";
    cin>>n;
    return n;
}
int main() {
    Trie t;
    int n;
    n = menu();
    while(n!=3) {
        switch(n) {
        case 1: {
            system("cls");
            cout << "\n############################################################################################\n\n";
            cout << "\t\t\t\tCORRETOR ORTOGRAFICO\n\n";
            cout << "############################################################################################";
            cout << "\n\n\tDIGITE O DIRETORIO DO ARQUIVO: ";
            cout << "\n\tTEXTO: ";
            gotoxy(0,12);
            cout << "############################################################################################";
            cout << "\n\n\tTEXTO CORRIGIDO(corrigido.txt): ";
            gotoxy(0,20);
            cout << "############################################################################################";
            cout << "\n\n\tSUGESTAO DE CORRECAO: ";
            gotoxy(39,7);
            string dir,word;
            cin >> dir;//leitura do diretorio
            fstream file;
            fstream file1;
            file1.open("corrigido.txt",fstream::out);
            if(file1.is_open()) {//limpando o arquivo corrigido
                file1 << "";
                file1.close();
            } else
                cout << "arquivo correcao nao aberto";
            file1.open("corrigido.txt",fstream::out|fstream::app);//
            file.open(dir);
            gotoxy(15,8);
            if(file.is_open()) {
                string str;
                while(getline(file,str)) {
                    cout << str;//mostra o conteudo do arquivo a ser corrigido
                }
                file.close();
            }
            gotoxy(5,25);
            file.open(dir.c_str());
            if(file.is_open()) {//correcao das palavras do arquivo
                while(file>>word) {//leitura do arquivo palavra pro palavra
                    char c[50];
                    strcpy(c,word.c_str());
                    string aux=t.Search(c);
                    file1 << aux << " ";
                }
                file.close();
                file1.close();
            } else
                cout << "arquivos nao foram abertos";
            gotoxy(5,16);
            file1.open("corrigido.txt");
            if(file1.is_open()) {//mostra o conteudo do arquivo corrigido
                string auxi;
                while(getline(file1,auxi)) {
                    cout << auxi;
                }
                file1.close();
            }
            gotoxy(0,0);
            system("pause");
        }
        break;
        case 2: {

            system("cls");
            char ch[50];
            gotoxy(0,1);
            cout << "###################################################################################################";
            gotoxy(40,2);
            cout << "CONSULTA POR PREFIXO";
            cout << "\n\n###################################################################################################";
            gotoxy(5,7);
            cout << "DIGITE O PREFIXO -> ";
            cin>> ch;//entrada do prefixo
            gotoxy(35,10);
            cout << "ENCONTRAMOS ESSES RESULTADOS PARA VOCE\n\n\n";
            t.Prefix(ch);//essa funçao mostra os resultados
            gotoxy(0,0);
            system("pause");
        }
        break;
        case 3:
            break;

        default:
            cout << "\t\t\t\t\tOPCAO INVALIDA\n\t\t\t";
            system("pause");
        }
        n=menu();
    }
    return 0;
}
