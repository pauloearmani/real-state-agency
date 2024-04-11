#ifndef MENU_H
#define MENU_H

#include "../../utils/include/imoveis_utils..hpp"  // Corrigido o caminho do arquivo de inclusão
#include "./Imovel.hpp"

using namespace std;

// Função para imprimir informações sobre os imóveis
void imprimir(const vector<Imovel *> &imoveis);

// Função para verificar o proprietário de cada imóvel na lista
void verificarProprietario(const vector<Imovel *> &listaImoveis);

// Funções para filtrar e exibir imóveis com base em diferentes critérios
void filtrarPorValor(const vector<Imovel *> &listaImoveis);
void filtrarPorNumQuartos(const vector<Imovel *> &listaImoveis);
void ordenarPorTipo(const vector<Imovel *> &listaImoveis);

// Função para filtrar imóveis por cidade em ordem decrescente
void filtrarPorCidadeDecrescente(const vector<Imovel *> &listaImoveis);

// Função para encontrar imóveis de um proprietário específico iterativamente
void encontrarImoveisProprietarioIt(vector<Imovel *> imoveis);

// Função para mostrar ou salvar informações sobre os imóveis
void mostrarOuSalvar(const vector<Imovel *> &listaImoveis);

#endif // MENU_H
