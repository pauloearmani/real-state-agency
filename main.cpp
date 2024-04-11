
#include "./Model/include/menu.hpp"
#include "./utils/include/loadDatas.hpp"
#include "Model/include/Apartamento.hpp"
#include "Model/include/Casa.hpp"
#include "Model/include/Chacara.hpp"
#include "Model/include/Imovel.hpp"
#include "utils/include/imoveis_utils..hpp"

#include <iostream>
#include <vector>

int main() {
  int opc = -1;
  vector<Imovel *> listaImoveis = carregarImoveis();

  do {
    cout << "Menu de Opcoes:" << endl;
    cout << " 1 - Verificar se um proprietario possui algum imovel." << endl;
    cout << " 2 - Filtrar imoveis por um valor <= ao digitado." << endl;
    cout << " 3 - Filtrar imoveis por numero de quartos >= ao digitado."
         << endl;
    cout << " 4 - Ordenar pelo valor e filtrar imoveis por tipo." << endl;
    cout << " 5 - Filtrar imoveis por cidade (em ordem decrescente de valor)."

         << endl;
    cout << " 6 - Filtrar imoveis por proprietario usando Iterador." << endl;
    cout << " 7 - Mostrar ou salvar dados." << endl;
    cout << "-1-  Para sair." << endl;
    cout << "Digite um numero inteiro de 1 a 7 ou -1 para sair: ";

    cin >> opc;

    if ((opc < 1 || opc > 7) && opc != -1) {
      cout << "Entrada invalida. Tente novamente." << endl;
    } else {
      switch (opc) {
      case -1:
        cout << "Saindo..." << endl;
        break;
      case 1:
        verificarProprietario(listaImoveis);
        cout << "----------------------------------------------------------"
             << endl;

        break;
      case 2:
        filtrarPorValor(listaImoveis);
        break;
      case 3:
        filtrarPorNumQuartos(listaImoveis);
        break;
      case 4:
        ordenarPorTipo(listaImoveis);
        break;
      case 5:
        filtrarPorCidadeDecrescente(listaImoveis);
        break;
      case 6:
        // Adicione a funcionalidade para a opcão 6 aqui
        encontrarImoveisProprietarioIt(listaImoveis);
        break;
      case 7:
        mostrarOuSalvar(listaImoveis);
        cout << "----------------------------------------------------------"
             << endl;

        break;
      default:
        cout << "Erro..." << endl;
        break;
      }
    }
  } while (opc != -1);

  for (Imovel *imovel : listaImoveis) {
    delete imovel;
  }

  return 0;
}