#include "./include/Apartamento.hpp"

// Construtor padrão
Apartamento::Apartamento() {}

// Construtor com parâmetros
Apartamento::Apartamento(int id, float valor, const string &proprietario,
                         const string &rua, const string &bairro,
                         const string &cidade, int numero, int quartos,
                         int banheiros, int andar, float taxa_condominio,
                         bool elevador, bool sacada)
    : Imovel(id, valor, proprietario, rua, bairro, cidade, numero, quartos,
             banheiros),
      andar(andar), taxa_condominio(taxa_condominio), elevador(elevador),
      sacada(sacada) {}

// Destrutor
Apartamento::~Apartamento() {
  // Operações de limpeza, se necessário
}

// Métodos Get e Set para os atributos específicos de Apartamento
int Apartamento::getAndar() const { return andar; }

void Apartamento::setAndar(int andar) { this->andar = andar; }

float Apartamento::getTaxaCondominio() const { return taxa_condominio; }

void Apartamento::setTaxaCondominio(float taxa_condominio) {
  this->taxa_condominio = taxa_condominio;
}

bool Apartamento::getElevador() const { return elevador; }

void Apartamento::setElevador(bool elevador) { this->elevador = elevador; }

bool Apartamento::getSacada() const { return sacada; }

void Apartamento::setSacada(bool sacada) { this->sacada = sacada; }

// Função polimórfica que retorna o nome da classe
string Apartamento::getNameClass() const { return "Apartamento"; }

// Sobrecarga do operador << para mostrar as informações do tipo Apartamento
ostream &operator<<(ostream &os, const Apartamento &apartamento) {
  apartamento.show(os);
  return os;
}

// Função para mostrar as informações do tipo Apartamento
void Apartamento::show(ostream &os) const {
  os << getProprietario() << '\n'
     << '\t' << "Preco: " << getValor() << '\n'
     << '\t' << "N Quartos: " << getQuartos() << '\n'
     << '\t' << "Rua: " << getRua() << '\n'
     << '\t' << "Bairro: " << getBairro() << '\n'
     << '\t' << "Cidade: " << getCidade() << '\n'
     << '\t' << "Andar: " << getAndar() << '\n'
     << '\t' << "Taxa/Condominio: " << getTaxaCondominio() << '\n'
     << '\t' << "Elevador: " << (getElevador() ? "SIM" : "NAO") << '\n'
     << '\t' << "Sacada: " << (getSacada() ? "SIM" : "NAO");
}
