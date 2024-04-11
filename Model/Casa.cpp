#include "./include/Casa.hpp"

Casa::Casa() {}

Casa::Casa(int id, float valor, const string &proprietario, const string &rua,
           const string &bairro, const string &cidade, int numero, int quartos,
           int banheiros, int andares, bool sala_jantar)
    : Imovel(id, valor, proprietario, rua, bairro, cidade, numero, quartos,
             banheiros),
      andares(andares), sala_jantar(sala_jantar) {}

Casa::~Casa() {
  // Operacões de limpeza, se necessário
}

int Casa::getAndares() const { return andares; }

void Casa::setAndares(int andares) { this->andares = andares; }

bool Casa::getSalaJantar() const { return sala_jantar; }

string Casa::getNameClass() const { return "Casa"; };

void Casa::setSalaJantar(bool sala_jantar) { this->sala_jantar = sala_jantar; }

void Casa::show(ostream &os) const {
  os << getProprietario() << '\n'
     << '\t' << "Preco: " << getValor() << '\n'
     << '\t' << "N Quartos: " << getQuartos() << '\n'
     << '\t' << "Rua: " << getRua() << '\n'
     << '\t' << "Bairro: " << getBairro() << '\n'
     << '\t' << "Cidade: " << getCidade() << '\n'
     << '\t' << "N Andares: " << getAndares() << '\n'
     << '\t' << "Sala/Jantar: " << (getSalaJantar() ? "SIM" : "NAO");
}
ostream &operator<<(ostream &os, const Casa &casa) {
  casa.show(os);
  return os;
}