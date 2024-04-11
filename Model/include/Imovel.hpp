#ifndef IMOVEL_H
#define IMOVEL_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Imovel {
private:
  int id;
  float valor;
  string proprietario;
  string rua;
  string bairro;
  string cidade;
  int numero;
  int quartos;
  int banheiros;

public:
  Imovel();
  Imovel(int id, float valor, const string &proprietario, const string &rua,
         const string &bairro, const string &cidade, int numero, int quartos,
         int banheiros);

  virtual ~Imovel();
  // Métodos Get e Set para cada atributo
  int getId() const;
  void setId(int id);

  float getValor() const;
  void setValor(float valor);

  string getProprietario() const;
  void setProprietario(const string &proprietario);

  string getRua() const;
  void setRua(const string &rua);

  string getBairro() const;
  void setBairro(const string &bairro);

  string getCidade() const;
  void setCidade(const string &cidade);

  int getNumero() const;
  void setNumero(int numero);

  int getQuartos() const;
  void setQuartos(int quartos);

  int getBanheiros() const;
  void setBanheiros(int banheiros);

  virtual string getNameClass() const = 0;
  virtual void show(ostream &os) const;
  friend ostream &operator<<(ostream &os, const Imovel &imovel);
};

#endif // IMOVEL_H
