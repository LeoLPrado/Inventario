#ifndef OPCOES_MENU_H
#define OPCOES_MENU_H

#include <string>
#include <list>

using namespace std;

/* ====================== */
/* STRUCTS */
/* ====================== */

struct Item {
    int id;
    string nome;
    string dono;
    string propriedade_magica;
    int raridade;
};

struct Aresta {
    int id1;
    int id2;
    int peso;
};

/* ====================== */
/* VARIÁVEIS GLOBAIS */
/* ====================== */

extern int id;
extern int N;

extern Item itens[1000];
extern list<Aresta> grafo[1000];

/* ====================== */
/* FUNÇÕES */
/* ====================== */

void mostrar_opcoes();
void inserir_item();
void cadastrar_similaridade();
void buscar_similares();
void verificar_existencia();
void listar_ordem_alfabetica();
void listar_ordem_raridade();
void contar_propriedade();
void remover_menos_raros();

#endif