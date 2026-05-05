## Capítulo 13: Definição de Classes e Encapsulamento
> Classes: estruturas que definem os atributos e métodos dos objetos para OOP.
### Abstração e Encapsulamento

A abstração é utilizada para controlar problemas complexos, simplificando-os em termos básicos e descrições generalistas.

No *C++* a classe é um tipo definido pelo usuário, que contém atributos que descrevem as características do objeto inicializado pela classe, além de conter métodos que representam as funções que o objeto consegue executar.

> Pode-se dizer que objetos são variáveis de classes.

O encapsulamento tem como objetivo garantir que os atributos de uma classe sejam acessados corretamente, para isso geralmente todos os atributos são definidos com o escopo de `private` e os métodos são definidos como `public`.

> O acesso direto aos atributos, sem uso de private, é raro e não aconselhado, mas pode ser feito.

A importância dessa técnica de encapsulamento, é a capacidade de modificar as estruturas internas dos objetos de uma determinada classe, sem influenciar na aplicação como um todo, a modularização dos elementos públicos em relação aos privados permite melhoria de versões de forma fácil e controlada.
### Definindo Classes, Métodos e Objetos

```cpp
#ifndef _ACCOUNT_  // Evitar múltiplas inclusões
#define _ACCOUNT_

#include <iostream>
#incluide <string>
using namespace std;

class Acount
{
	private:
		string name;
		unsigned long nr;
		double balanced;
		
	
	public:
		bool init(const string&, unsigned long, double);
		void display();
}

#endif
```

- Os atributos e métodos podem ser do tipo de outras classes definidas anteriormente.

-  O `ifndef` é utilizado para evitar que a classe seja escrita mais de uma vez, caso essa classe esteja incluída em mais de um arquivo de uma mesma compilação.

- O tipo padrão de disponibilidade dos dados de uma classe é `private`.
#### Nomeação

A convenção padrão para nomear as classes e seus membros:
- Nomes de classes começam com letras maiúsculas.
- Nomes dos membros começam com letras minúsculas

Uma definição de classe não está definida até que os métodos estejam definidos, visto que apenas eles podem utilizar os objetos da classe.
- Acessar membros privados, só é possível para métodos que pertençam a mesma classe.

Assim, para definir um método é necessário utilizar o nome da classe separado do nome do método pelo operador de resolução de escopo `::`.
- Sem adicionar esses dois elementos, resulta em uma definição de uma função global.
#### Modularização

Usualmente a definição de uma classe é colocado em um header file, para que seja facilitado o re-uso da classe em diferentes arquivos do programa. Além disso, os métodos precisam sempre estar em um arquivo `.cpp`, arquivo esse que também deve ser diferente dos arquivos do programa.

A respeito dos objetos, eles são instâncias definidas pelas classes construídas, ou seja, no tipo do objeto ao invés dos tipos primitivos da linguagem, será colocado a classe. Ao fazer isso todos os atributos definidos na classe são inicializados.
### Objetos

As aplicações que manipulam os objetos inicializados, podem acessar apenas os membros públicos desses objetos, esses que geralmente são métodos que possuem como objetivo garantir a manipulação correta desses atributos privados.

Esses métodos são acessados, utilizando o operador `.` após os seus nomes, seguidos pelo método público em específico.

```cpp
Account current;
current.init("Jones, Tom", 1234567, -1200.99)
```

O operador de atribuição `=` é o único operador definido para todas as classes por padrão, com a condição que ambos os objetos pertençam a mesma classe. Sua função é atribuir todos os membros da origem (pré-operador) para o alvo (pós-operador).

```cpp
Account current1, current2
current2.init("Marley, Bob", 350213, 1000.0)
current1 = current2 // Os dados de current2 foram sobrescritos pelo de target 1
```
#### Ponteiros

As instâncias das classes como qualquer outro objeto possuem um endereço de memória que podem ser atribuídos a um ponteiro.

```cpp
Account *ptrCurrent1 = &current1;

(*ptrCurrent1).display();
```

Nesse caso, inicialmente definimos o ponteiro e após isso utilizando o operador de desreferenciação `*`, entre parênteses pois o operador `.` tem maior precedência, podemos acessar o valor apontado e executar seus métodos.

Para evitar essa sintaxe mais elaborada e a confusão entre o uso do asterisco na definição do ponteiro e como operador de acesso ao valor apontado, existe uma *syntatic sugar* que é o operador de flecha `->`.

```cpp
Accont *ptrCurrent1 = &current1;

ptrCurrent1 -> display(); // Mesma função que o código anterior
```

Os ponteiros para objetos costumam ser utilizados como argumentos para funções, permitindo que essas funções possam utilizar dos métodos dos objetos para fazer manipulações a nível de atributos privados.
### Structs & Onions

Como herança do C, temos que o *struct* é um agrupamento de dados que logicamente fazem sentido juntos, é como se fosse uma classe apenas com membros públicos.
- Por definição utilizado como um *record*, que agrupa dados como uma lista.

Por uma questão de compatibilidade de códigos com C, ela também pode ser utilizada para definir classes, mas com o padrão de acesso aos membros como `public`, diferente do `private` do *class*.

Já para as *unions*, temos um agrupamento de variáveis de tipos diferentes que possuem como finalidade representar argumentos similares.
- Os membros possuem o mesmo endereço de memória (só carrega um valor por vez).
- O tamanho da *union* é o maior tipo de dado que ela contém.
- Todos os seus dados são públicos por padrão como na *struct*.
- Permite mudar o tipo de uma variável durante a execução.

```cpp
union Number
{
	long n;
	double x;
};

Number number1, number2;

number1.n = 12345;
number2.x = 2.77;
```

---
## Capítulo 14: Métodos

### Construtores e Destrutores

As linguagens de programação tradicionais só alocam memórias para as variáveis quando elas são definidas. O problema disso é que no caso das classes, geralmente seus membros só são definidos após o método `init` e isso pode ocasionar problemas.

Para evitar esses problemas é feito uma inicialização implícita pelo uso de um método especial, os *construtores*, que garante que os atributos já sejam criados com valores iniciais e com seus recursos alocados adequadamente na memória.
- Os atributos não definidos são inicializados na forma padrão (não recomendado).

O nome de um construtor é a própria classe e ele não tem nenhum tipo de retorno, nem mesmo `void`. Costumam ser declarado na *seção pública* de uma classe, permitindo que você "construa" essa classe em qualquer lugar que ela esteja definida.

> Como nas funções, esses construtores também pode ser *sobrecarregados*, sendo a *assinatura* deles a ordem, quantidade e tipo dos parâmetros que ele recebe.

```cpp
Class_name::Class_name(const string& a_name)
{
	name = a_name;
	nr = 111111;
	state = 0.0
}
```
#### Inicialização

Na inicialização de uma classe o compilador analisa os argumentos passados no parênteses e faz a verificação dos construtores associados a essa classe, para utilizar o construtor que tiver a mesma assinatura e então utiliza-ló.

```cpp
Class_name object("Gabriel") // Vai utilizar o construtor do exemplo anterior
``` 

> Construtores padrões são criados, caso não haja um na definição da classe.

Já o destrutor, só existe um por classe e ele não pode ser sobrecarregado, ele deve desfazer tudo que tiver sido realizado pelo construtor. 

Em geral, caso não seja definido explicitamente a linguagem também constrói um padrão, mas para certos casos mais complexos esse destrutor não vai realmente desfazer todas as ações do construtor.

Sua definição é similar ao construtor com a adição de um `~` antes do nome da classe:
```cpp
Class_name::~Class_name(){}
```
#### Chamado

O destrutor é chamado automaticamente no final da vida de um objeto, caso não seja chamado explicitamente:
- Para objetos locais exceto os que pertençam ao campo `static`, eles são chamados ao final do bloco de código local.
- Para objetos globais ou do campo `static`, eles são chamados ao final do programa.
#### "Inline"

Métodos *inline* são métodos definidos no arquivo header da classe utilizando a palavra *inline* antes da construção do método e funcionam da mesma forma que as funções.

Os construtores e destrutores são métodos implicitamente *inline*, ou seja, na definição de um objeto de uma classe, mesmo que não haja a passagem de argumentos, esse objeto será inicializado pelo construtor definido na classe.
- Implicitamente, pois não precisam do *inline* na definição deles.
### Acesso de métodos

Tendo em mente a questão do encapsulamento, o acesso de métodos é algo imprescindível para garantir que a estrutura da classe pode ser modificada, sem que a interface de acesso a essa classe seja modificada.

A partir disso são construídos métodos de acesso aos atributos privados: `getName()`, `getNr()`, `getState()` e também são construídos métodos que permitem definir os valores desses atributos `setName()`, `setNr()` e `setState()`.

Os do tipo `get`sem conter nenhum argumento e os do tipo `set` contendo o argumento relacionado ao atributo, garantindo que a classe seja manipulada corretamente.
#### Apenas Leitura

Para os casos de objetos definidos como `const`, nenhum dos métodos anteriores irão funcionar, visto que esse objeto não pode ser alterado, mesmo os métodos do tipo `get` se tornam indisponíveis, pois o compilador não sabe que um método é *read-only* a menos que isso esteja explícito.

Para sinalizar que um método é *read-only* é necessário adicionar a palavra chave *const* após o nome do método na sua declaração. 

> Eles podem ser usados em objetos que não são do tipo *const*.

O *const* faz parte da assinatura de um método, portanto é possível utilizar do sobrecarregamento, para fazer um método do tipo *read-only* e outro normal.

Todas as classes possuem por padrão quatro métodos:
- Construtor padrão
- Destrutor
- Construtor de cópia
- Atribuição

O construtor padrão é substituído se houver algum construtor definido manualmente, sobre o construtor de cópia ele é um construtor que pode receber um outro objeto da mesma classe como argumento e ao fazer isso ele atribui os atributos do objeto passado como argumento para o novo objeto.

A diferença entre isso e utilizar o operador de atribuição `=`, é que antes de fazer a atribuição o segundo objeto já precisaria existir, para depois ter seus atributos igualados ao primeiro objeto.
#### Ponteiro *this*

O `this` é um ponteiro que aponta para o próprio objeto ao qual ele foi automaticamente inicializado, sendo sua principal utilização a diferenciação entre parâmetros de métodos e dos atributos do próprio objeto.

Ou seja. garante que o compilador entenda que:
```cpp
Class_name& setName(string name)
{
	this->name = name; // O atributo "name" recebe o argumento "name"
	return *this;
}
```

Além disso, pode ser utilizado para permitir o uso de métodos em sequência, pelo retorno do próprio objeto ao fim de um método.

---
## Capítulo 15: Objetos membros & Membros estáticos

### Objetos Membros

Um membro de uma classe, pode ser um objeto de outra classe. Um exemplo disso é a utilização de membros do tipo *string* que são essencialmente um objeto da classe *String*.
> Essa relação entre classes é chamada de "Has-A".

Nesses casos múltiplos construtores são chamados, o do objeto principal e os construtores de cada membro, na ordem onde primeiro os membros são inicializados e após isso o construtor geral une todas as peças.

A inicialização dos membros por construtores padrões pode afetar o desempenho do programa, visto que inicialmente eles são inicializados com valores padrões para depois terem seus valores substituídos pelo construtor do objeto final.

Além disso, para o caso de objetos membros do tipo *const* se faz obrigatório o uso de construtores específicos, pois os seus valores não podem ser modificados após a inicialização.

Para fazer a inicialização desses membros é utilizado o carácter `:` seguido pelos membros e os seus argumentos para a inicialização.

```cpp
Class_name::Class_name(/*Parameters*/)
: val(w), time(hr, min, sec)
{/* Constructor block */}
```

### Membros estáticos

Cada objeto primariamente tem suas próprias características, ou seja, todos os membros de um objeto serão armazenados em uma posição única da memória.

Porém, em algumas situações é importante armazenar dados comuns para todos os objetos pertencentes a uma mesma classe, uma única vez, independente da quantidade de objetos inicializados.

Esse tipo de dado ocupa um espaço na memória, mesmo que não haja nenhum objeto dessa classe, sua declaração é:

```cpp
static double min, max; // Dois atributos estáticos declarados
```

Os membros estáticos costumam ser definidos no mesmo arquivo que os métodos e são definidos e inicializados em arquivos externos:

```cpp
double Class_name::min = 0.0;
```

O encapsulamento continua a funcionar normalmente para os membros estáticos, ou seja, em caso de declaração como `public` é possível acessar diretamente seus valores:

```cpp
cout << temperature.max;
cout << Class_name::max;
``` 

> Ambas dão no mesmo resultado, porém a segunda é mais recomendada, pois demonstra que se trata de um membro estático, sem objeto específico.

Para acessar membros estáticos do tipo `private` é preciso de métodos estáticos, que só podem acessar membros estáticos.

```cpp
static void setMax(double b);

Class_name::setMax(42.4);
```
### Enumeration

Define um *range* de variáveis integrais (números do tipo `int`), seus valores seguem por padrão o valor do índice ao qual o elemento pertence na lista.

```cpp
enum Shape{Line, Rectangle, Ellipse}
``` 

Nesse caso, *line* representa o valor 0, *rectangle* e *ellipse* os valores 1 e 2 respectivamente, caso houvesse outros números continuaria seguindo essa lógica de progressão.

A ideia aqui é criar "apelidos" para valores numéricos específicos, que pode ser utilizado para atribuir a outras variáveis, tornando o código mais auto-explicativo.

É possível atribuir valores explicitamente para esses apelidos, além de permitir valores implícitos e explícitos misturados.

```cpp
enum Bound { Lower = -100, Upper = 100}

enum { OFF, OUT=0, ON, IN=1} // OFF = 0 e ON = 1 implicitamente
```

Ele funciona como se fosse um elemento estático da classe, ou seja, todos os objetos da classe compartilham a mesma definição do `enum` e sua inicialização ocorre independente dos objetos da classe.

---
## Capítulo 16 - Arrays

### Definição e Inicialização

Um array é uma "lista" que contém múltiplos objetos de um mesmo tipo armazenados **sequencialmente** na memoria. Esse sequenciamento permite o acesso dos seus elementos através de números chamados de índices.
> Um array é um vetor.

Sua definição é o tipo dos dados armazenados o nome e a quantidade de itens a ser armazenado.

```cpp
type name[count];
```

- Perceba que o array ocupa uma quantidade contínua de espaço na memória, então o tamanho de bytes do tipo armazenado vezes a quantidade de itens é o espaço consumido, mesmo que não seja preenchido todos os espaços.
#### Operador **[]**

O operador de *subscript* `[]` é utilizado para acessar valores individuais dentro do array, começando em 0 até o fim dos elementos, ou seja, 10 elementos, seria do 0 a 9.
- Esse operador tem a maior precedência entre todos.

O array pode ser inicializado informando o tamanho dele (quantos elementos serão armazenados) ou apenas atribuindo os elementos e o tamanho é definido pela quantidade de elementos armazenados.
- O não uso de espaços armazenados também ocupa memória e atribui lixo a esses espaços "vazios".
#### C Strings

São um conjunto de elementos do tipo *char* que funcionam similar as *Strings* porém sem as funcionalidades da classe, por exemplo as atribuições e comparações não estão definidas por padrão.

Mas existem funções padrões do C, que possuem manipulações para esse tipo de array. Sendo assim, esse tipo de array é preferível para situações que apenas algumas operações são necessárias e deseja-se evitar coisas desnecessárias da classe *String*.
### Class Arrays

Um *array* também pode ser um objeto de uma classe, um array de classe. A sua inicialização ocorre através de uma lista de inicialização, com uma chamada de construtor para cada elemento, sendo ele o construtor padrão ou um construtor declarado.

```cpp
Result temperatureTab[24] = 
{
	Result(-2.5, 0, 30, 30),
	Result(3.5),
	4.5, // Chama construtor de apenas um argumento
	Result( temp1),
	temp2
};
```

### Matrix

Também pode ser feito arrays multidimensionais, geralmente de duas dimensões, chamados de matrizes:

```cpp
float number[3][10]; // 3 x 10 matrix

int arr[][3] = { {5}, {6}};
```

> Na definição de um array o tamanho da primeira dimensão pode ser omitido, 

### Encapsulamento de Arrays

Arrays são muito bem vindo para o encapsulamento das classes, visto que ele permite o acesso direto a valores individuais, agrupando todos os de mesmo tipo.

É uma forma fácil de controle de memória, permitindo utilizar métodos para operações simples de arrays, como retirar ou inserir valores.

---
## Capítulo 17 - Arrays & Ponteiros

> Por definição um array é um ponteiro que aponta para o primeiro elemento do array.

Essa definição explica muitas coisas sobre o funcionamento de um array, por exemplo, por qual motivo os elementos precisam estar de forma contínua na memória e qual a necessidade de todos eles pertencerem ao mesmo tipo.

Diferentemente de um ponteiro convencional, um array é um ponteiro constante que não pode ser modificado, porém pode ser atribuído a uma variável ponteiro.
#### Typeless Pointer

Se refere a um ponteiro que não possui um tipo definido, dessa forma é possível acessar o endereço de memória armazenado pelo ponteiro, nesse caso pelo array.

```cpp
cout << (void *)town;
```

O *cast* com `void *` é o que permite tornar um ponteiro sem tipo e assim printar o endereço de memória do ponteiro/array.
### Aritmética de Ponteiros

Como dito anteriormente, um dos motivos para que todos os elementos de um array sejam do mesmo tipo é garantir o acesso a cada elemento através do uso de índices.

Para isso é calculado nativamente quantos bytes o ponteiro precisa se mover do primeiro elemento do array, baseado no valor do índice, ou seja *index 1* de um array de *int* é uma movimentação de 8 bytes após o endereço do primeiro elemento.

```cpp
int v[3] = {2, 4, 6}, *pv, x;

pv = v + 1 // pv aponta para v[1] = 4
*pv = 5 // v[1] agora é 5
pv -= 1 // pv aponta para v[0]
++pv // pv aponta para v[1]

x = *pv++ // x recebe 5 e pv aponta para v[2]
```

- Perceba que é possível manipular os elementos de um array, através de um ponteiro externo e além disso os números inteiros computados em `pv`são automaticamente interpretados como deslocamento de bytes do tamanho de um *int*.

> Essas manipulações feitas com `pv` não são possíveis com `v` pois ele é um ponteiro constante, que sempre aponta para o primeiro elemento.

Além disso, é possível realizar a subtração entre ponteiros do mesmo tipo, por exemplo para saber quantos elementos existem entre dois ponteiros.
- Entre `pv` e `v` existem 2 elementos. 

Também é possível fazer a comparação de ponteiros do mesmo tipo.

```cpp
for ( pv = v + 2; pv >= v; --pv)
	cout << setw(10) << *pv* // Conta os valores do array de trás pra frente
```
###  Arrays como argumentos

Quando ocorre a passagem de um array como argumento de uma função, a função recebe o endereço do primeiro elemento do array, permitindo que essa função possa manipular o array de qualquer maneira.

Um array pode ser declarado como parâmetro:
- `char str[]` ou `char  *str`

E no caso de arrays multidimensionais pode ser utilizado:
- `int num[][10]`ou `int *num[10]`
#### Read-only pointers

São ponteiros que podem ser utilizados para apontar para objetos constantes ou objetos não constantes, porém para o caso de objetos constantes apenas ponteiros constantes podem apontar para eles.

Além disso, como o nome sugere eles só podem ser utilizados para métodos de leitura. Costumam ser muito comuns nos parâmetros de funções, para garantir que tais funções não vão alterar os elementos de um objeto.

> Funções podem retornar ponteiros, geralmente para funções que procuram elementos em um objeto em específico.
#### Arrays de ponteiros

É possível fazer um array de ponteiros, onde o primeiro elemento é um ponteiro que pode ser um ponteiro para um objeto qualquer ou outro array.

```cpp
Class_name *accPtr[5] = { &depo, &save, NULL}
```
- Os demais ponteiros são todos preenchidos com *NULL*
### Argumentos de linha de comando

É possível definir argumentos para a principal função do programa, `main()`.

Essa definição é feita utilizando uma variável do tipo *int* que contém o número de argumentos passados na linha de comando, na hora da execução do programa. Após isso tem um array de *char pointer* que aponta para cada argumento passado.

```cpp
int main(int argc, char* argv[])
{}
```

- `argc`: Armazena a quantidade de argumentos
- `argv[0]`: Aponta para o nome do programa e seu caminho
- `argv[1]`: Aponta para o primeiro argumento real passado na linha de comando
- `argv[n]`: Sucede-se os argumentos passados para a linha de comando
- `argv[argc - 1]`: Aponta para o último argumento
- `argv[argc]`: É um *NULL pointer* 
