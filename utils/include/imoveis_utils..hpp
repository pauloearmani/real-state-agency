#ifndef IMOVEIS_UTILS
#define IMOVEIS_UTILS

#include "../../Model/include/Apartamento.hpp"
#include "../../Model/include/Casa.hpp"
#include "../../Model/include/Chacara.hpp"
#include "../../Model/include/Imovel.hpp"

#include "./string_utils.hpp"
#include <algorithm>
#include <fstream>

#pragma once

// Verifica se existem imóveis associados a um determinado proprietário
bool existeImoveisProprietario(vector<Imovel *> imoveis, string prop);

// Filtra imóveis por valores menores ou iguais a um valor específico
vector<Imovel *> filtroImoveisPorValores(float value, vector<Imovel *> imoveis);

// Filtra imóveis por quantidade de quartos maior ou igual a um valor específico
vector<Imovel *> filtroImoveisPorNumQuartos(int numQuartos, vector<Imovel *> imoveis);

// Ordena imóveis por tipo (Casa, Chacara, Apartamento)
vector<Imovel *> ordenarImoveisDeUmTipo(vector<Imovel *> imoveis, string nameClass);

// Ordena imóveis filtrados por cidade em ordem decrescente
vector<Imovel *> ordenarImoveisFiltradosPelaCidadeDecres(vector<Imovel *> imoveis, string cidade);

// Função para mostrar ou salvar dados de imóveis, dependendo da opção escolhida
void mostrarOuSalvarDados(int opc, vector<Imovel *> imoveis);

// Busca iterativa por imóveis de um determinado proprietário
vector<vector<Imovel *>::iterator> buscarImoveisProprietarioIt(vector<Imovel *> &imoveis, const string &prop);

#endif
