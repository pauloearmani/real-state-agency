#ifndef CASA_H
#define CASA_H

#include "Imovel.hpp"

class Casa : public Imovel {

private: 
   int andares;
   bool sala_jantar;
   
public:

  Casa();
  Casa(int id, float valor, const string &proprietario, const string &rua,
       const string &bairro, const string &cidade, int numero, int quartos,
       int banheiros, int andares, bool sala_jantar);

//Destrutor
  ~Casa();

  // Métodos Get e Set para os atributos específicos de Casa
  int getAndares() const;
  void setAndares(int andares);

  bool getSalaJantar() const;
  void setSalaJantar(bool sala_jantar);

  void show(ostream &os) const override;

  //função polimorfica que retorna o nome da classe.
  string getNameClass() const override;

  //sobrecarga do operador
  friend ostream &operator<<(ostream &os, const Casa &casa);
};

#endif // CASA_H
