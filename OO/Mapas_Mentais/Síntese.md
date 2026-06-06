## Conceitos
### Inline
> É uma forma de economizar processamento para execução de funções pequenas.

Como exemplo, temos as funções que apenas retornam um valor, os métodos públicos `get...()` de uma classe.

O que acontece na prática, é que o compilador substitui a chamada da função pelo código real dela naquela posição, sem fazer o processo de chamada de função tradicional.

Diferente dos métodos tradicionais de uma classe, quando se trata de métodos que utilizarão da propriedade *Inline*, é preciso que esses métodos sejam definidos no próprio arquivo `.h` da classe. 
- O compilador precisa ver o corpo da função no exato momento em que compila o arquivo que a declara.

```cpp
class Fraction{
	private:
		long numerator;
	
	public:
		Fraction(long numerator = 0, long denominator = 1);
		long get_numerator() const;
}

inline long Fraction::get_numerator() const{
	return numerator;
}
```

---
### Const
> É utilizada para declarar objetos e funções que são do tipo *Read-Only*
#### Antes de um método / função

Significa que o retorno da função é *const*, ou seja, após a execução da função o valor retornado não pode mais ser alterado.
```cpp
const T& func() 
``` 
#### Depois de um método

Significa que o método é *const*, ou seja, o método não pode modificar os membros do objeto que o chamou (`*this`).

```cpp
int getValue() const { return value; }
```
#### Casos gerais

1. **Ponteiros para tipos constantes**
   Ponteiros do tipo constante, não permitem que os valores apontados sejam alterados diretamente através do ponteiro.

```cpp
int x{10};
const int* i = &x;
*i = 6 // VAI APRESENTAR ERRO
```

2. **Ponteiros constantes**
   Os endereços desses ponteiros não podem ser alterado, ou seja, não podem apontar para outros valores além do valor declarado.

```cpp
const int* i = &x;
*i = 9

int z{6};
i = &z // VAI APRESENTAR ERRO
```

3. **Ponteiros constantes para tipos constantes**
   Esse aqui nada pode ser alterado, nem o valor que ele aponta através dele, nem o endereço para o qual ele aponta.

4. **Parâmetros constantes**
   Caso o parâmetro de uma função / método **não** seja constante, passar um valor que seja do tipo constante vai retornar um erro.
	- Caso seja um ponteiro, não terá problema, pois será criado uma cópia do ponteiro apontando para o mesmo endereço.

```cpp
int foo(int *y){
	return y*;
}

int main(){
	int x{10};
	int* const i = &x; // Ponteiro Constante
	const int* j = &x; // Ponteiro que aponta para valor constante
	foo(i) // SEM ERRO
	foo(j) // GERA ERRO
}
``` 
> Ler de trás para frente auxilia na percepção

---
### Static

#### Variáveis estáticas

Ao utilizar essa keyword para variáveis inicializadas dentro de funções, elas são inicializadas apenas uma vez, ou seja, ao fim da execução da função o valor armazenado por elas continua na memória e na próxima chamada da função esse valor pode ser acessado como foi deixado na chamada anterior.

```cpp
void contador() {
	static int x = 0;
	x++;
	std::cout << x << std:endl;
}

contador() // Printa 1
contador() // Printa 2
```
#### Membros estáticos 
> Eles podem ser acessados sem instanciar o objeto.

```cpp
MinhaClasse::metodo();
MinhaClasse::i++; // Isso com o atributo já inicializado
``` 
##### Atributos estáticos

Nesse caso, todos os objetos dessa classe possuem acesso ao mesmo atributo, ou seja, a modificação realizada em um objeto, reflete em todos os objetos.
> Visto que variáveis estáticas só são inicializadas uma vez, por isso também não podem ser inicializadas por construtores.

```cpp
class GfG {
	public:
		static int i;
		GtG(){};
}

// Static member inintialization (Geralmente no arquivo .cpp da classe)
int GfG::i = 1;
```
##### Métodos estáticos

Eles só podem acessar membros ou funções estáticas da classe, visto que os métodos não estáticos precisam do ponteiro *this*, que o estático não possui.
#### Funções Estáticas Globais

Declarar uma função ou variável como *static* no início de um arquivo `.cpp` limita a visibilidade dela para apenas esse arquivo.
- Serve como uma forma de encapsulamento.

---
### Friend

#### Friend Function

Uma *Friend Function* é uma função que não é um membro da classe (não possui o ponteiro `this`) na qual ela é declarada, pois ela é sempre definida fora da classe, porém ela tem a permissão especial de acessar os atributos privados/protegidos da classe.

```cpp
Classe Employee {
	private:
		 int salary;
		 
	public:
	    Employee(int s) {
	      salary = s;
	    }
	
	    friend void displaySalary(Employee emp);
};

void displaySalary(Employee emp) {
  cout << "Salary: " << emp.salary; // Tem permissão de acesso
}
```

Utilizada quando se precisa de uma função externa acessando atributos da classe, muito utilizada na **sobrecarga de operadores**.
#### Friend Class

Uma *Friend Class* permite que todos os membros da classe que teve a amizade definida no seu escopo, seja acessada pela classe amiga.

```cpp
class Motor {
	private:
	    int temperatura;
	
	public:
	    Motor() : temperatura(90) {}
	    
	    friend class Painel; // Painel acessa Motor -> Motor não acessa Painel
};

class Painel {
	public:
	    void exibirStatus(const Motor& m) {
	        // Acesso direto ao membro privado 'temperatura'
	        cout << "Temperatura do motor: " << m.temperatura << "°C" << endl;
	    }
};
```

- **IMPORTANTE**: A amizade é definida em uma única direção, ou seja, a classe onde a amizade é definida não pode acessar os membros da classe amiga.

Também é possível definir métodos específicos para conceder a permissão de *Friend* para uma classe externa ter acesso.

```cpp
class Motor; // Declaração da classe que "concede" a amizade

class Painel {
	public:
		void diagnosticar(Motor& m);
};

class Motor {
	private:
		int codigoErro = 404;
	
	public:
		// Coloca o método da outra classe que vai acessar o atributo privado 
		// dessa classe. 
		friend void Painel::diagnosticar(Motor& m);
};

// Implementa o "Frient method"
void Painel::diagnosticar(Motor& m){
	cout << "Status " << m.codigoErro << endl;
}
```

---
### Operator (Sobrecarga de operadores)

Essa é uma *keyword* utilizada para  sobrecarga de operadores, que significa dar um novo significado para um operador em relação aos objetos construídos pelo desenvolvedor.

Os operadores funcionam como uma espécie de função, então o elemento a esquerda é o responsável por chamar o operador e o elemento a direita é o "parâmetro do operador"

- Operadores podem ser sobrecarregados como membros ou *friend functions*, além disso um dos operandos precisa ter sido um objeto definido pelo usuário.

```cpp
class Ponto
{
	private:
	    int x, y;
	
	public:
		Ponto operator+(const Ponto& outro) { 
			return Ponto{this->x + outro.x, this->y + outro.y}; 
		}
};
```

- Nessa definição, o objeto a esquerda sempre precisa ser o objeto da classe onde essa sobrecarga foi definida.

Para utilizar operadores onde o objeto da esquerda seja de qualquer tipo, é utilizado as *friend functions*:

```cpp
// Class Ponto
public:
	friend ostream& operador<<(ostream& os,  const Ponto& p);
};

std::ostream& operator<<(std::ostream& os, const Ponto& p) {
	os << "(" << p.x << ", " << p.y << ")"; 
	return os; 
};
```

- Caso mais comum de sobrecarga com friend function é os operadores de inserção visto que eles são executados em objeto de outra classe (`iostream`).

---
### Private, Public e Protected
> Especificadores de acesso

- **Public**: 
	O especificador `public` permite que seus membros sejam acessíveis de qualquer lugar onde o objeto seja visível, ou seja, própria classe, classes filhas e funções externas (fora da classe).

- **Private**:
	O especificador `private` impossibilita acessos dos seus membros que não sejam através de funções que pertençam a própria classe ou *friend functions*.

- **Protected**:
	O especificador `protected` é um meio-termo, ele é privado para o mundo exterior (funções externas), porém permite que suas classes herdeiras tenham acesso aos seus membros.

---
### Override (Function Overriding)

É utilizado em métodos virtuais, para o caso de polimorfismo, ou seja, mudar a ação de um método em uma classe derivada.

A *keyword* `override` é opcional, mas sua utilização é uma verificação de erros, que checa se o método está com a assinatura correta em relação ao método virtual. 

Visto que, em caso de tentativa de override utilizando assinatura diferente, ocorre um caso de *function hiding*, onde o método da classe base é ocultado pelo método de mesmo nome da classe derivada, porém o *dynamic binding* não ocorre nesse caso.

- **Dynamic binding**: É a checagem do tipo instanciado em tempo de execução ao invés do tipo declarado, o que permite que um ponteiro da classe base, que armazena um objeto da classe derivada, consiga executar um método da classe derivada que sofreu um override corretamente (sendo esse um método virtual na classe base).

```cpp
class Base{
    public:
        virtual void display(){ // Para o override o método precisa ser virtual
            cout<<"Display from Base class"<<endl;
        }
};

class Derived: public Base{
    public:
        void display() override{
            cout<<"Display from derived class"<<endl;
        }
};

	int main() {
    Base * basePtr;
    Derived derivedObj;
    basePtr=&derivedObj;
    basePtr->display(); // "Diplay from derived class"
    return 0;
}
```

---
### New & Delete
> Operadores de alocação dinâmica de memória
#### Array de Objetos

Para alocar um array de objetos dinamicamente, utilizamos: `new Objeto[n]`, com n sendo o número de objetos alocados.

Para deletar esses elementos da heap, utilizamos: `delete[]` que chama o destrutor de todos os objetos alocados no array.
#### Array de Ponteiros 

Para o caso de array de ponteiros, a alocação dinâmica é: `new Objeto*[n]`, nesse caso os construtores não são chamados automaticamente, sendo necessário dar um `new`individual para cada objeto alocado em cada posição do array.

> O *new* já retorna um ponteiro, então na alocação dos objetos não precisa passar por referência, a atribuição padrão já vai armazenar um ponteiro na posição do array.

Para deletar esses elementos da heap, é preciso fazer um laço que percorra o array dando `delete` em cada objeto e por fim fazer um `delete[]`no array de ponteiros.

- Importante, o delete não se dá bem com lixo na memória, então para fazer o loop é bom garantir que as posições sem objeto alocado estejam com ponteiros nulos.

- Além disso, para o caso mais comum de uso de array de ponteiros, que é um array de ponteiro do tipo da classe base, para armazenar qualquer objeto das classes derivadas, é necessário que o destrutor da classe base seja do tipo virtual.

```cpp
class Entidade {
	private: 
		string nome;
	public:
	    Entidade(std::string n) : nome(n) {
	        cout << "Construtor: " << nome << " criado.\n";
	    }
	    ~Entidade() { // Destrutor virtual por segurança
	        cout << "Destrutor: " << nome << " destruido.\n";
	    }
};

int main() {
    int tamanho = 3;
    Entidade** arrayDePonteiros = new Entidade*[tamanho];
   
    for (int i = 0; i < tamanho; i++) { // Instanciar todas as posições
        arrayDePonteiros[i] = new Entidade("Objeto " + to_string(i));
    }
    
    for (int i = 0; i < tamanho; i++) { 
        delete arrayDePonteiros[i]; // Chama o destrutor de cada Entidade
    }
    
    // Por fim, deletamos o array de ponteiros em si
    delete[] arrayDePonteiros;
    return 0;
}
```

---
### Dynamic Cast &  Static Cast

Com uma sintaxe similar ao *static_cast* sua diferença é que ele ocorre em tempo de execução, sendo muito utilizado para *downcasting* seguros, ou seja, transição da classe base para uma classe derivada.

Ele faz a verificação do tipo instanciado, exigindo que o tipo declarado (classe base) tenha ao menos um método virtual (ou dá erro de compilação), se for feita a conversão de um ponteiro e falhar ele retorna um ponteiro nulo, já se for uma referência, no caso de falha ele lança uma exceção.

Seu caso de uso clássico, é quando se tem um ponteiro da classe base apontando para um objeto da classe derivada que possui um método único, dessa forma, para executá-lo é preciso fazer o casting.

> Da derivada para a base, é mais performático utilizar o static_cast, visto que essa conversão é sempre segura.

```cpp
struct Animal { 
    virtual ~Animal() {}
};

struct Cachorro : public Animal {
    void latir() { std::cout << "Au Au!"; }
};

struct Gato : public Animal {
    void miar() { std::cout << "Miau!"; }
};

void fazerBarulhoEspecifico(Animal* a) {
    
    Cachorro* c = dynamic_cast<Cachorro*>(a); // Se for cachorro converte
	// Cachorro& c = dynamic_cast<Cachorro&>(a);
	
    if (c) { 
        c->latir(); // Sucesso! Era um cachorro.
    } else {
        std::cout << "Nao e um cachorro, operacao ignorada.";
    }
}

void Upcasting(Cachorro* c1){
	Animal* a1 = static_cast<Animal*>(c1); // Esse casting é sempre seguro
}
```

> A referência também pode ser usada no lugar dos ponteiros.
---
### Tratamento de Exceções

#### Throw

Essa é a keyword responsável por "lançar" o erro, geralmente ela vem dentro de uma condicional que verifica um possível erro que pode acontecer se o valor que vai no denominador de uma fração for 0 por exemplo, dessa forma ela ao lançar o erro encerra a execução do restante da função.

```cpp
#include <stdexcept>
double dividir(double a, double b){
	if (b == 0){
		throw std::invalid_argument("Divisão por zero detectada!");
	}
	return a / b;
}
```
#### Try & Catch

O *try* é onde ficam as funções definidas com o `throw` que podem apresentar alguma exceção, em caso de exceção lançada o *catch* é o responsável por receber essa exceção e executar alguma ação, como armazenar o log de erro.

```cpp
#include <stdexcept>
int main(){
	try{
		double resultado = dividir(10, 0);
	}
	catch (std::exception& e){ // exception pega todos os erros padrões
		std::cerr << "Erro: " << e.what() << std::endl;
	}
	
	return 0;
}
```

- O `.what()` retorna o texto definido no *throw*.
#### Class Exception (Inner Class)

É possível criar uma função dentro de outra função (*Inner Class*), para que essa função interna lide com os erros.

Ela deve ser declarada como um membro público da classe principal e não precisa conter membros próprios, visto que cada classe desse tipo, geralmente lida com apenas um tipo de exceção, então a chamada dela já indica o erro que ocorreu.

- **Exception Specification**: É o uso da função *noexcept()*, colocada ao final dos métodos para indicar se esses métodos podem ou não lançar exceções, por padrão ao não colocar nada, o parâmetro interno vai como `false`, podendo lançar exceções.

`Fraction.h`
```cpp
class Fraction {
	private:
		int numerador;
		int denominador;
	
	public:
		
		class DivError{}
		
		// Construtor com especificação de exceção 
		Fraction(int num = 0, int den = 1) noexcept(false);
		
		// Operadores com especificação 
		Fraction operator/(const Fraction& other) const noexcept(false);
		
		// O operador >> geralmente é uma função amiga (friend) 
		friend istream& operator>>(istream& in, Fraction& f) noexcept(false);
}
```

`Fraction.cpp`
```cpp
Fraction::Fraction(int num, int den) { 
	if (den == 0) { 
		// Lança a exceção
		throw Fraction::DivError();
	}
	numerator = num; 
	denominator = den;
}

Fraction Fraction::operator/(const Fraction& other) const { 
	if (other.numerator == 0) { 
		throw Fraction::DivError(); 
	} 
	return Fraction(numerator * other.denominator, denominator * other.numerator); 
}

```

`main.cpp`
```cpp
try {
    Fraction f1(1, 0); // Isso vai disparar a exceção
} 
catch (Fraction::DivError) {
    cerr << "Erro: Tentativa de divisão por zero em uma fração!" << endl;
}
```
---
### Templates

O compilador substitui o tipo T genérico, pelo tipo definido na instanciação.

```cpp
template <typename T>
T somar(T a, T b){
	return a + b;
}

somar<int>(5, 10) // Gera uma versão de somar para int
somar<double>(5.5, 2.1) // Gera uma versão de somar para double
```

Também pode ser feito o template de uma classe, onde o tipo de dado que essa classe armazena é definido na instanciação.

```cpp
template <class T> // Pode definir quantos parâmetros quiser
class Caixa{
	private:
		T conteudo;
	public:
		Caixa(T item) : conteudo(item){}
		T getConteudo() { return conteudo; }
}
```

Além disso, pode-se criar um template com parâmetros pré-instanciados, sendo geralmente proibido que esses parâmetros sejam do tipo `float` ou `double`.

```cpp
template <typename U, int V = 10> 
class MinhaClasse { 
	U dado; 
	int tamanho = V; 
};
```
#### Template Especialization

Serve para lidar com um tipo de dado que não consegue ser generalizado como os demais.

```cpp
// Template genérico
template <class T> 
bool eIgual(T a, T b){
	return a == b; 
} 

// Especialização para caracteres
template <> 
eIgual<const char*>(const char* a, const char* b) { 
	return strcmp(a, b) == 0; 
}
```