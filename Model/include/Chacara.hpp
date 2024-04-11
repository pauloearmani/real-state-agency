#ifndef CHACARA_H
#define CHACARA_H

#include "Imovel.hpp"

class Chacara : public Imovel {
private: 
  bool salao_festa;
  bool salao_jogos;
  bool campo_futebol;
  bool churrasqueira;
  bool piscina;
  
public:
  // Construtores
  Chacara();
  Chacara(int id, float valor, const string &proprietario, const string &rua,
          const string &bairro, const string &cidade, int numero, int quartos,
          int banheiros, bool salao_festa, bool salao_jogos, bool campo_futebol,
          bool churrasqueira, bool piscina);

  // Destrutor
  ~Chacara();

  // Métodos Get e Set para os atributos específicos de Chacara
  bool getSalaoFesta() const;
  void setSalaoFesta(bool salao_festa);

  bool getSalaoJogos() const;
  void setSalaoJogos(bool salao_jogos);

  bool getCampoFutebol() const;
  void setCampoFutebol(bool campo_futebol);

  bool getChurrasqueira() const;
  void setChurrasqueira(bool churrasqueira);

  bool getPiscina() const;
  void setPiscina(bool piscina);

  // Função polimórfica que retorna o nome da classe
  string getNameClass() const override;

  // Sobrecarga do operador para mostrar as informações do tipo Chacara.
  void show(ostream &os) const override;
  friend ostream &operator<<(ostream &os, const Chacara &chacara);
};

#endif // CHACARA_H
