#include <iostream>
using namespace std;

// Estoque
string estoque[] = {
    "Refrigerante",       "Salgadinho", "Chocolate", "Água",      "Café",
    "Barrinha de cereal", "Biscoito",   "Chiclete",  "Sanduíche", "Sorvete"};

int quantidadeProduto[] = {3, 5, 8, 10, 5, 1, 5, 3, 6, 2};

struct produtos {
  string nome;
  double preco;
  int qtd;
};

int retirarProduto(string produtoEscolhido, int quantidadeEscolhida) {

  int quantidadeRestante = -1;

  for (int i = 0; i < 10; i++) {
    if (produtoEscolhido == estoque[i]) {
      if (quantidadeProduto[i] >= quantidadeEscolhida) {
        quantidadeProduto[i] -= quantidadeEscolhida;
        quantidadeRestante = quantidadeProduto[i];
      }

      break;
    }
  }
  return quantidadeRestante;
}

// MODO USUÁRIO

// Verifica se têm o produto na loja
bool isAvailable(string produtoExiste) {
  for (int i = 0; i <= 9; i++) {
    if (produtoExiste == estoque[i]) {
      return true;
      break;// Produto encontrado
    } 
      
  }

  return false; // Produto não encontrado
}

// Valor entregue ao caixa
// Troco deu certo
double informaTroco(double valorEntregue, int quantidade,
                    produtos produtoPreco) {
  double troco;

  troco = valorEntregue - (quantidade * produtoPreco.preco);

  return troco;
}

int main() {
  struct produtos produto;
  double troco;
  double valorInserido;
  struct produtos precoProduto;
  int quantidade;
  bool produtoDisponivel;
  int quantidadeRestante;

  // TROCO E SE ESTÁ DISPONÍVEL ESTÃO CERTOS
  // O que falta fazer no modo usuário
  // Falta fazer a função retirar funcionar
  // Criar uma lista para armazenar todos os dados
  // E ao retirar as informações desse dado são excluídas

  cout << "Qual o produto desejado: ";
  cin >> produto.nome;

  cout << "Qual o valor inserido na máquina: ";
  cin >> valorInserido;

  cout << "Qual o preço do produto: ";
  cin >> precoProduto.preco;

  cout << "Qual a quantidade desejada: ";
  cin >> quantidade;

  produtoDisponivel = isAvailable(produto.nome);

  troco = informaTroco(valorInserido, quantidade, precoProduto);

  quantidadeRestante = retirarProduto(produto.nome, quantidade);

  // Parte de diminuir do estoque deu certo
  // Parte do troco deu certo
  // Parte de verificar se tá disponível deu certo(verificar dps devido a função
  // do estoque) Usuário praticamente pronto
  // Se não tiver disponível for verdadeiro
  if (!produtoDisponivel) {
    cout << "Produto indisponível"<<endl;
  } else {

    if (produtoDisponivel) {
      if (quantidadeRestante > 0 && troco > 0) {
        cout << "O troco é de: R$ " << troco << "\n";
        cout << "Sobrou: " << quantidadeRestante;
      } else if (quantidadeRestante < 0 && troco < 0) {
        cout << "Quantidade indisponível"<<endl;
      } else if (quantidadeRestante > 0 && troco < 0) {
        cout << "Valor insuficiente"<<endl;;
      } else if (troco == 0) {
        cout << "Sem troco"<<endl;;
      }
    }
  }
}