#include "./include/Chacara.hpp"
#include <iostream>

// Construtor padrão
Chacara::Chacara() {}

// Construtor com parâmetros
Chacara::Chacara(int id, float valor, const string &proprietario,
                 const string &rua, const string &bairro, const string &cidade,
                 int numero, int quartos, int banheiros, bool salao_festa,
                 bool salao_jogos, bool campo_futebol, bool churrasqueira,
                 bool piscina)
    : Imovel(id, valor, proprietario, rua, bairro, cidade, numero, quartos,
             banheiros),
      salao_festa(salao_festa), salao_jogos(salao_jogos),
      campo_futebol(campo_futebol), churrasqueira(churrasqueira),
      piscina(piscina) {}

// Destrutor
Chacara::~Chacara() {
  // Operações de limpeza, se necessário
}

// Métodos Get e Set para os atributos específicos de Chacara
bool Chacara::getSalaoFesta() const { return salao_festa; }

void Chacara::setSalaoFesta(bool salao_festa) {
  this->salao_festa = salao_festa;
}

bool Chacara::getSalaoJogos() const { return salao_jogos; }

void Chacara::setSalaoJogos(bool salao_jogos) {
  this->salao_jogos = salao_jogos;
}

bool Chacara::getCampoFutebol() const { return campo_futebol; }

void Chacara::setCampoFutebol(bool campo_futebol) {
  this->campo_futebol = campo_futebol;
}

bool Chacara::getChurrasqueira() const { return churrasqueira; }

void Chacara::setChurrasqueira(bool churrasqueira) {
  this->churrasqueira = churrasqueira;
}

bool Chacara::getPiscina() const { return piscina; }

void Chacara::setPiscina(bool piscina) { this->piscina = piscina; }

// Função polimórfica que retorna o nome da classe
string Chacara::getNameClass() const { return "Chacara"; }

// Função para mostrar as informações do tipo Chacara
void Chacara::show(ostream &os) const {
  os << getProprietario() << '\n'
     << '\t' << "Preco: " << getValor() << '\n'
     << '\t' << "N Quartos: " << getQuartos() << '\n'
     << '\t' << "Rua: " << getRua() << '\n'
     << '\t' << "Bairro: " << getBairro() << '\n'
     << '\t' << "Cidade: " << getCidade() << '\n'
     << '\t' << "Salao/Festa: " << (getSalaoFesta() ? "SIM" : "NAO") << '\n'
     << '\t' << "Salao/Jogos: " << (getSalaoJogos() ? "SIM" : "NAO") << '\n'
     << '\t' << "Campo/Futebol: " << (getCampoFutebol() ? "SIM" : "NAO") << '\n'
     << '\t' << "Churrasqueira: " << (getChurrasqueira() ? "SIM" : "NAO")
     << '\n'
     << '\t' << "Piscina: " << (getPiscina() ? "SIM" : "NAO");
}

// Sobrecarga do operador << para mostrar as informações do tipo Chacara
ostream &operator<<(ostream &os, const Chacara &chacara) {
  chacara.show(os);
  return os;
}
