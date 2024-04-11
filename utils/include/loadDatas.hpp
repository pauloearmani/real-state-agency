#ifndef LOAD_DATAS
#define LOAD_DATAS

#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>

#include <vector>

#pragma once

#include "../../Model/include/Imovel.hpp"

using namespace std;

// Função para carregar dados de imóveis a partir de um arquivo
vector<Imovel *> carregarImoveis();

#endif
