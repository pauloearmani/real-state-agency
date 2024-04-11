#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Imovel.hpp"

class Apartamento : public Imovel {
private:
  int andar;
  float taxa_condominio;
  bool elevador;
  bool sacada;

public:
  Apartamento();
  Apartamento(int id, float valor, const string &proprietario,
              const string &rua, const string &bairro, const string &cidade,
              int numero, int quartos, int banheiros, int andar,
              float taxa_condominio, bool elevador, bool sacada);

  ~Apartamento();

  // Métodos Get e Set para os atributos específicos de Apartamento
  int getAndar() const;
  void setAndar(int andar);

  float getTaxaCondominio() const;
  void setTaxaCondominio(float taxa_condominio);

  bool getElevador() const;
  void setElevador(bool elevador);

  bool getSacada() const;
  void setSacada(bool sacada);

  // Função polimórfica que retorna o nome da classe
  string getNameClass() const override;

  // Sobrecarga do operador para mostrar as informações do tipo Apartamento.
  void show(ostream &os) const override;
  friend ostream &operator<<(ostream &os, const Apartamento &apt);
};

#endif // APARTAMENTO_H
