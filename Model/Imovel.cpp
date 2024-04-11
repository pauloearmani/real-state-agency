#include "./include/Imovel.hpp"

Imovel::Imovel() {}

Imovel::Imovel(int id, float valor, const string &proprietario,
               const string &rua, const string &bairro, const string &cidade,
               int numero, int quartos, int banheiros)
    : id(id), valor(valor), proprietario(proprietario), rua(rua),
      bairro(bairro), cidade(cidade), numero(numero), quartos(quartos),
      banheiros(banheiros) {}

Imovel::~Imovel() {
  // Operações de limpeza, se necessário
}
/*Get e Set*/

int Imovel::getId() const { return id; }

void Imovel::setId(int id) { this->id = id; }

float Imovel::getValor() const { return valor; }

void Imovel::setValor(float valor) { this->valor = valor; }

string Imovel::getProprietario() const { return proprietario; }

void Imovel::setProprietario(const string &proprietario) {
  this->proprietario = proprietario;
}

string Imovel::getRua() const { return rua; }

void Imovel::setRua(const string &rua) { this->rua = rua; }

string Imovel::getBairro() const { return bairro; }

void Imovel::setBairro(const string &bairro) { this->bairro = bairro; }

string Imovel::getCidade() const { return cidade; }

void Imovel::setCidade(const string &cidade) { this->cidade = cidade; }

int Imovel::getNumero() const { return numero; }

void Imovel::setNumero(int numero) { this->numero = numero; }

int Imovel::getQuartos() const { return quartos; }

void Imovel::setQuartos(int quartos) { this->quartos = quartos; }

int Imovel::getBanheiros() const { return banheiros; }

void Imovel::setBanheiros(int banheiros) { this->banheiros = banheiros; }


//função polimorfica que retornar o nome da classe
string Imovel::getNameClass() const { return "Imovel"; };

//Sobrecarga
void Imovel::show(ostream &os) const {
  os << getProprietario() << '\n'
     << '\t' << getValor() << '\n'
     << '\t' << getQuartos() << '\n'
     << '\t' << getRua() << '\n'
     << '\t' << getBairro() << '\n'
     << '\t' << getCidade();
}

ostream &operator<<(ostream &os, const Imovel &imovel) {
  imovel.show(os);
  return os;
}