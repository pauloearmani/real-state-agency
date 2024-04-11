#include "./include/menu.hpp"
#include "include/Imovel.hpp"
#include <cstdlib>
#include <iostream>

// Função para imprimir informações sobre os imóveis
void imprimir(const vector<Imovel *> &imoveis) {
  for (Imovel *imo : imoveis) {
    cout << *imo << endl;
    cout << "--------------------------------------------------------------"
         << endl;
  }
}

// Função para verificar se um proprietário possui imóveis na lista
void verificarProprietario(const vector<Imovel *> &listaImoveis) {
  string prop;
  cout << "Digite o nome do proprietario: ";

  cin.ignore();  // Limpa o buffer do teclado
  getline(cin, prop);

  cout << "--------------------------------------------------------------"
       << endl;

  if (existeImoveisProprietario(listaImoveis, prop)) {
    cout << prop << ", possui imovel." << endl;
  } else {
    cout << prop << " nao possui imovel." << endl;
  }
}

// Função para filtrar imóveis por valor
void filtrarPorValor(const vector<Imovel *> &listaImoveis) {
  float valor;
  cout << "Digite um valor: ";
  cin >> valor;
  cout << "--------------------------------------------------------------"
       << endl;

  vector<Imovel *> imoveisFiltrados = filtroImoveisPorValores(valor, listaImoveis);

  if (imoveisFiltrados.empty()) {
    cout << "Nao existem imoveis com valores <= " << valor << endl;
  } else {
    imprimir(imoveisFiltrados);
  }
}

// Função para filtrar imóveis por número de quartos
void filtrarPorNumQuartos(const vector<Imovel *> &listaImoveis) {
  int numQuartos;
  cout << "Digite a quantidade de quartos: ";
  cin >> numQuartos;
  cout << "--------------------------------------------------------------"
       << endl;

  vector<Imovel *> imoveisFiltrados = filtroImoveisPorNumQuartos(numQuartos, listaImoveis);

  if (imoveisFiltrados.empty()) {
    cout << "Nao existem imoveis com a quantidade de quartos maior ou igual a " << numQuartos << endl;
  } else {
    imprimir(imoveisFiltrados);
  }
}

// Função para ordenar imóveis por tipo
void ordenarPorTipo(const vector<Imovel *> &listaImoveis) {
  string tipo;
  cout << "Digite o tipo do Imovel (Casa, Chacara, Apartamento): ";
  cin >> tipo;
  cout << "--------------------------------------------------------------"
       << endl;

  vector<Imovel *> imoveisFiltrados = ordenarImoveisDeUmTipo(listaImoveis, tipo);

  if (imoveisFiltrados.empty()) {
    cout << "Nao existem imoveis do tipo " << tipo << endl;
  } else {
    imprimir(imoveisFiltrados);
  }
}

// Função para filtrar imóveis por cidade em ordem decrescente
void filtrarPorCidadeDecrescente(const vector<Imovel *> &listaImoveis) {
  string cidade;
  cout << "Digite a cidade do Imovel: ";

  cin.ignore();  // Limpa o buffer do teclado
  getline(cin, cidade);

  cout << "--------------------------------------------------------------"
       << endl;

  vector<Imovel *> imoveisFiltrados = ordenarImoveisFiltradosPelaCidadeDecres(listaImoveis, cidade);

  if (imoveisFiltrados.empty()) {
    cout << "Nao existem imoveis na cidade " << cidade << endl;
  } else {
    imprimir(imoveisFiltrados);
  }
}

// Função para encontrar imóveis de um proprietário iterativamente
void encontrarImoveisProprietarioIt(vector<Imovel *> imoveis) {
  string prop;
  cout << "Digite o nome do proprietario: ";
  cin.ignore();  // Limpa o buffer do teclado
  getline(cin, prop);

  vector<vector<Imovel *>::iterator> aux = buscarImoveisProprietarioIt(imoveis, prop);

  if (!aux.empty()) {
    for (auto it = aux.begin(); it != aux.end(); it++) {
      Casa *imoC = dynamic_cast<Casa *>(**it);

      if (imoC) {
        cout << *imoC << "\n";
        cout << "--------------------------------------------------------------"
             << endl;
      } else {
        Apartamento *imoAP = dynamic_cast<Apartamento *>(**it);
        if (imoAP) {
          cout << *imoAP << "\n";
          cout << "------------------------------------------------------------"
                  "--"
               << endl;
        } else {
          Chacara *imoCk = dynamic_cast<Chacara *>(**it);
          if (imoCk) {
            cout << *imoCk << "\n";
            cout << "----------------------------------------------------------"
                    "----"
                 << endl;
          }
        }
      }
    }
  } else {
    cout << "Nao existe imoveis desse proprietario" << endl;
  }
}

// Função para mostrar ou salvar informações sobre os imóveis
void mostrarOuSalvar(const vector<Imovel *> &listaImoveis) {
  int opc = 0;
  cout << "Digite: \n 1 - Imprimir no terminal \n 2 - Salvar no arquivo " << endl;
  cin >> opc;
  cout << "--------------------------------------------------------------"
       << endl;

  mostrarOuSalvarDados(opc, listaImoveis);

  if (opc == 2) {
    cout << "Sucesso ao salvar no arquivo..." << endl;
  }
}
