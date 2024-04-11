#include "./include/imoveis_utils..hpp"
#include "include/string_utils.hpp"

#include <algorithm>
#include <fstream>

// Verifica se existem imóveis associados a um determinado proprietário
bool existeImoveisProprietario(vector<Imovel *> imoveis, string prop) {
  for (Imovel *imovel : imoveis) {
    if (toUpperCase(imovel->getProprietario()) == toUpperCase(prop))
      return true;
  }

  return false;
}

// Filtra imóveis por valores menores ou iguais a um valor específico
vector<Imovel *> filtroImoveisPorValores(float value, vector<Imovel *> imoveis) {
  vector<Imovel *> aux;

  for (Imovel *imovel : imoveis) {
    if (imovel->getValor() <= value) {
      aux.push_back(imovel);
    }
  }

  return aux;
}

// Filtra imóveis por quantidade de quartos maior ou igual a um valor específico
vector<Imovel *> filtroImoveisPorNumQuartos(int numQuartos, vector<Imovel *> imoveis) {
  vector<Imovel *> aux;

  for (Imovel *imovel : imoveis) {
    if (imovel->getQuartos() >= numQuartos) {
      aux.push_back(imovel);
    }
  }

  return aux;
}

// Ordena imóveis por tipo (Casa, Chacara, Apartamento) e por valor
vector<Imovel *> ordenarImoveisDeUmTipo(vector<Imovel *> imoveis, string nameClass) {
  vector<Imovel *> aux;

  for (Imovel *imovel : imoveis) {
    if (toUpperCase(imovel->getNameClass()) == toUpperCase(nameClass)) {
      aux.push_back(imovel);
    }
  }

  if (!aux.empty()) {
    sort(aux.begin(), aux.end(), [](const Imovel *a, const Imovel *b) {
      return a->getValor() < b->getValor();
    });
  }

  return aux;
}

// Ordena imóveis filtrados por cidade em ordem decrescente por valor
vector<Imovel *> ordenarImoveisFiltradosPelaCidadeDecres(vector<Imovel *> imoveis, string cidade) {
  vector<Imovel *> aux;

  for (Imovel *imovel : imoveis) {
    if (toUpperCase(imovel->getCidade()) == toUpperCase(cidade)) {
      aux.push_back(imovel);
    }
  }

  if (!aux.empty()) {
    sort(aux.begin(), aux.end(), [](const Imovel *a, const Imovel *b) {
      return a->getValor() > b->getValor();
    });
  }

  return aux;
}

// Função para mostrar ou salvar dados de imóveis, dependendo da opção escolhida
void mostrarOuSalvarDados(int opc, vector<Imovel *> imoveis) {
  ofstream arquivo;

  if (opc == 2) {
    // Abre o arquivo para escrita
    arquivo.open("./database/arquivos_salvos.txt", ios::trunc);
    if (!arquivo.is_open())
      exit(1);
    arquivo.close();
    arquivo.open("./database/arquivos_salvos.txt", ios::app);
  }

  // Itera sobre os imóveis
  for (Imovel *imovel : imoveis) {
    Casa *imoC = dynamic_cast<Casa *>(imovel);

    if (imoC) {
      if (opc == 1) {
        // Imprime no terminal
        cout << *imoC << "\n";
        cout << "--------------------------------------------------------------"
             << endl;
      } else if (opc == 2) {
        // Salva no arquivo
        arquivo << "casa"
                << ";" << imoC->getId() << ";" << imoC->getValor() << ";"
                << imoC->getProprietario() << ";" << imoC->getRua() << ";"
                << imoC->getBairro() << ";" << imoC->getCidade() << ";"
                << imoC->getNumero() << ";" << imoC->getQuartos() << ";"
                << imoC->getBairro() << imoC->getAndares() << ";"
                << imoC->getSalaJantar() << ";"
                << "\n";
      }
    } else {
      Apartamento *imoAP = dynamic_cast<Apartamento *>(imovel);
      if (imoAP) {
        if (opc == 1) {
          // Imprime no terminal
          cout << *imoAP << "\n";
          cout << "------------------------------------------------------------"
                  "--"
               << endl;
        } else if (opc == 2) {
          // Salva no arquivo
          arquivo << "apartamento"
                  << ";" << imoAP->getId() << ";" << imoAP->getValor() << ";"
                  << imoAP->getProprietario() << ";" << imoAP->getRua() << ";"
                  << imoAP->getBairro() << ";" << imoAP->getCidade() << ";"
                  << imoAP->getNumero() << ";" << imoAP->getQuartos() << ";"
                  << imoAP->getBanheiros() << ";" << imoAP->getAndar() << ";"
                  << imoAP->getTaxaCondominio() << ";" << imoAP->getElevador()
                  << ";" << imoAP->getSacada() << ";"
                  << "\n";
        }
      } else {
        Chacara *imoCk = dynamic_cast<Chacara *>(imovel);
        if (imoCk) {
          if (opc == 1) {
            // Imprime no terminal
            cout << *imoCk << "\n";
            cout << "----------------------------------------------------------"
                    "----"
                 << endl;
          } else if (opc == 2) {
            // Salva no arquivo
            arquivo << "chacara"
                    << ";" << imoCk->getId() << imoCk->getValor() << ";"
                    << imoCk->getProprietario() << imoCk->getRua() << ";"
                    << imoCk->getBairro() << imoCk->getCidade() << ";"
                    << imoCk->getNumero() << imoCk->getQuartos() << ";"
                    << imoCk->getBanheiros() << imoCk->getSalaoFesta() << ";"
                    << imoCk->getSalaoJogos() << imoCk->getCampoFutebol() << ";"
                    << imoCk->getChurrasqueira() << imoCk->getPiscina() << "\n";
          }
        }
      }
    }
  }

  if (opc == 2) {
    // Fecha o arquivo
    arquivo.close();
  }
}

// Busca imóveis por proprietário e retorna um vetor de iteradores para os elementos correspondentes
vector<vector<Imovel *>::iterator>
buscarImoveisProprietarioIt(vector<Imovel *> &imoveis, const string &prop) {
  vector<vector<Imovel *>::iterator> aux;

  for (auto it = imoveis.begin(); it != imoveis.end(); it++) {
    if (toUpperCase((*it)->getProprietario()) == toUpperCase(prop)) {
      aux.push_back(it);
    }
  }

  return aux;
}
