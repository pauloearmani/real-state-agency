#include "./include/loadDatas.hpp"
#include "../Model/include/Apartamento.hpp"
#include "../Model/include/Casa.hpp"
#include "../Model/include/Chacara.hpp"

// Função para carregar os dados dos imóveis a partir de um arquivo
vector<Imovel *> carregarImoveis() {
  vector<Imovel *> imoveis;
  string linha;
  int id = 1; // Como o arquivo não possui um id, foi criada uma variável que
              // vai recebendo um para cada Imovel

  string nomeArquivo = "./database/dados.txt";
  ifstream arquivo(nomeArquivo);

  if (!arquivo.is_open()) {
    cerr << "Erro ao abrir o arquivo." << endl;
    exit(1);
  }

  // Lê cada linha do arquivo
  while (getline(arquivo, linha)) {
    vector<string> tokens;
    stringstream ss(linha);
    string token;

    // Divide a linha em tokens usando ';' como delimitador
    while (getline(ss, token, ';')) {
      tokens.push_back(token);
    }

    // Converte os tokens e cria instâncias apropriadas de imóveis
    if (tokens[0] == "casa") {
      imoveis.push_back(new Casa(id, stof(tokens[1]), tokens[2], tokens[3],
                                 tokens[4], tokens[5], stoi(tokens[6]),
                                 stoi(tokens[7]), stoi(tokens[8]),
                                 stoi(tokens[9]), stoi(tokens[10])));
      id++;
    } else if (tokens[0] == "apartamento") {
      imoveis.push_back(new Apartamento(
          id, stof(tokens[1]), tokens[2], tokens[3], tokens[4], tokens[5],
          stoi(tokens[6]), stoi(tokens[7]), stoi(tokens[8]), stoi(tokens[9]),
          stof(tokens[10]), stoi(tokens[11]), stoi(tokens[12])));
      id++;
    } else if (tokens[0] == "chacara") {
      imoveis.push_back(
          new Chacara(id, stof(tokens[1]), tokens[2], tokens[3], tokens[4],
                      tokens[5], stoi(tokens[6]), stoi(tokens[7]),
                      stoi(tokens[8]), stoi(tokens[9]), stoi(tokens[10]),
                      stoi(tokens[11]), stoi(tokens[12]), stoi(tokens[13])));
      id++;
    }
  }

  return imoveis;
}
