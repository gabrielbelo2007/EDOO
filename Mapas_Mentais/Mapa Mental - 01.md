## Capítulo 1 - Fundamentos

### Características básicas

Linguagem multiparadigma, orientação a objetos e imperatividade, consegue utilizar a maior parte dos códigos em C, herdando funcionalidades como:

- Usabilidade universal de programas modulares
- Eficiente, perto da linguagem de máquina
- Programas portáveis para variadas plataformas

Além disso, na parte de "OOP", temos os conceitos de:

- Abstração de dados (criação de classes para descrever objetos)
- Encapsulamento (Controle de acesso aos dados)
- Herança (Criação de classes derivadas)
- Polimorfismo (Instruções que podem ter efeitos variados)

### Programação Procedural X  POO

Na programação procedural os dados e as funções são mantidos separados, o código segue uma sequência lógica: coleta o dado, insere na função e obtém uma saída.

- É necessário garantir que o tipo de dado esperado pela função, realmente seja o tipo de dado que será passado para a função.
- Se o tipo de dado se altera, a função precisa ser alterada.

Na programação orientada a objetos os dados e as funções são combinados, a classe define um tipo de objeto, construindo as suas propriedades (dados) e capacidades (funções).

### Tradução C++

1.  O código em C++ é salvo em um arquivo (*source code*).
2.  O arquivo é compilado em linguagem de máquina (*module*).
3.  O *linker* combina o arquivo compilado (*module*) com outros arquivos (*modules*) que contém funções básicas ou partes do programa compiladas anteriormente.
4. É gerado um arquivo executável.

### Elementos do C++

- `//`: Comentário
- `/* */`: Bloco de comentário
- `#include <filename>`: *Preprocessador* copia o conteúdo do arquivo
- `main()`: Função global do programa
- `cout`: É um objeto que gerencia o fluxo de saída
- `<<`: Operador de inserção de fluxo (envia dados)
- `endl`: Insere uma quebra de linha no fluxo de saída
- `return`: Retorna um valor para uma função

```cpp
#include <iostream>
using namespace std; 
// Determina o escopo para as palavras reservadas utilizadas no código

// "Prototypes" são esqueletos de funções que irão ser definidas
void line(), message()

// Funções determinam o tipo retornado na sua inicialização
int main()
{
	cout << "Hello" << endl;
	line()
	message()
	
	return 0;
}

void line()
{
	cout << "_______" << endl;
}

void message()
{
	cout << "In function message()" << endl;
}
```
---
## Capítulo 2 - Tipos, Constantes e Variáveis

### Tipos de dados

- `bool`: Dados booleanos (True or False)
- `char`: Caracteres de um byte
- `wchar_t`: Caracteres de até 4 bytes
- `short`: Valores numéricos de até 2 bytes
- `int`: Valores numéricos de até 4 bytes
- `long`: Valores numéricos de até 8 bytes
- `float`: Valores de ponto flutuante com até 4 bytes (Acurácia decimal: 6 dígitos)
- `double`: Valores de ponto flutuante com até 8 bytes (Acurácia decimal: 15 dígitos)
- `long double`: Valores de ponto flutuante com até 10 bytes (Acurácia decimal: 19 dígitos)

> A quantidade de bytes pode variar se o dado é do tipo *signed* ou *unsigned*, ou se a máquina é de 32 ou 64 bits.

O operador `sizeof`é útil para saber a quantidade de memória necessária para armazenar um objeto de determinado tipo (quanto ocupa na memória).

Também existe todos os valores possíveis para cada tipo de dado, chamado de **constantes literais**, são as representações únicas para cada valor específico dentro de um tipo de dado.

Por exemplo:
```cpp
if (letra == 'A')

// Esse valor de 'A' especificamente com aspas simples, se refere a uma constante literal, e tem o seu valor armazenado diretamente no código fonte.
```
- No caso do tipo `char`, as constantes literais são representadas com aspas simples.

### Sequência de Escape

Servem para representar caracteres que são muito complicados de escrever no código fonte, assim, permite que sejam escritos "instruções especiais", nas constantes literais de caracteres `' '` ou de uma string `" text "`. 

O uso da barra invertida `\`faz o compilador não ler o texto da forma convencional, permitindo que ele interprete o próximo caractere como um comando especial.
### Nomes

Existem regras e convenções no que diz a respeito de designar nomes para funções e variáveis:

- *Case sensitive*: palavras maiúsculas se diferenciam das minúsculas.
- O ideal é que o primeiro caractere seja uma letra (embora também possa ser `_`)
- Sem espaços ou números
#### Convenções: 

- c, ch
	- Para nomes de caracteres

- i, j, k, l, m, n
	- Para inteiros, especialmente os índices

- x, y, z
	- Para números de ponto flutuante

### Variáveis

A variável é definida a partir do seu tipo de dado (que também define o espaço na memória) e seu nome, múltiplas variáveis podem ser definidas de uma vez só, para um mesmo tipo.

```cpp
type name1, name2, name3
``` 

- Uma variável definida fora de uma função, é global e pode ser utilizada por todas as funções
- Uma variável definida dentro de uma função só pode ser manipulada pela mesma função
- A variável não precisa ter seu valor inicializado na sua definição (variáveis globais não inicializadas terão valor padrão de 0)

Uma variável pode ser criada na forma padrão, que permite alterações dentro do código, respeitando os escopos das funções, como também pode ser criada como *const*, na qual ela assume uma categoria de apenas leitura, sem poder sofrer alterações. 
> Além disso, também há *volatile* que permite que a variável seja alterada por outros programas e eventos externos.

---
## Capítulo 3 - Funções e Classes

### Funções

#### Declaração

As funções seguem regras de declaração:

```cpp
long func (int, double);
```

1. Tipo do valor retornado pela função
2. Nome da função
3. Nos parênteses os tipos dos argumentos recebidos, argumentos esses que podem ser nomeados.

> A nomeação dos argumentos não faz diferença para o compilador.

Essas declarações de nomes de variáveis, funções e classes, é imprescindível para o compilador, visto que os nomes que não são padrões da linguagem (*keywords*) causam mensagens de erro.

> Funções declaradas nos arquivos de cabeçalho do código (#include) não precisam ser declaradas e definidas antes de serem utilizadas.

No entanto, perceba que no exemplo acima a função foi **DECLARADA** mas não **DEFINIDA** isso significa que o compilador sabe da existência da função, evitando mensagens de erros, mas a função ainda precisa ter sua lógica implementada.
#### Chamada de função

Essa é a expressão para quando utilizamos o retorno de uma função para algum processo (representa um valor), seja para armazenar em uma variável ou até mesmo para um output direto.

Qualquer expressão pode ser passada como argumento de uma função desde que esteja de acordo com o tipo de dado esperado pela função, em caso de não ser exatamente o mesmo, o compilador tentará se possível fazer uma conversão de tipo. 

- `cin`: É um objeto padrão de entrada para tipos de inteiros (também captura caracteres ignorando espaço).
- `getline(cin, variavel)`: É a construção para entrada de dados do tipo string.

```cpp
int variavel;

cout << "Insira um valor: ";
cin >> variavel;

cout << question;
getline(cin, name);
```

Podem ter funções do tipo *void* que não possuem nenhum tipo de retorno, ou que não precisa de argumentos, que são declaradas com *void* na área de argumentos ou apenas com a região vazia.
### Arquivos de Cabeçalho

Esses arquivos de texto contém declarações e macros, na qual através do `#include` esse manual de instrução é disponibilizado para o código atual e permite utilizar suas funções, definições de classes, variáveis externas...

- Precisam ser incluídos no topo do arquivo de programa
- Só pode ser adicionado um arquivo por `#include`
- O arquivo precisa estar entre `< >` ou `" "`
- Para arquivos construídos manualmente, se utiliza o `.h` como sufixo

Por padrão, quando o arquivo está entre `< >`, ele costuma ser procurado pelo compilador na pasta do *include*, assim, para os arquivos construídos manualmente é utilizado as aspas duplas para sinalizar que a procura deve acontecer no diretório do programa.
#### Cabeçalhos do C

Para utilizar arquivos de cabeçalhos provenientes da biblioteca padrão do C, evitando conflitos, é preciso utilizar o prefixo `c` no nome do arquivo:

```cpp
#include <math.h>

#includde <cmath> // Correto
using namespace std;
``` 
#### Propriedades da Classe

Uma classe é definida pelo seus atributos e seus métodos, sendo esses métodos, funções que pertencem a classe e funcionam em conjunto com os atributos para executar determinadas operações.
> Métodos são as  *funções dos atributos*
### Objetos
> Uma variável do tipo de uma classe, uma **instância de classe**.

Todos os métodos que são definidos como públicos em um aclasse, podem ser chamados pelo objeto dessa classe. Diferentemente das funções globais, um método só pode ser chamado pela classe ao qual ele pertence, sendo:

```cpp
object.method();
``` 