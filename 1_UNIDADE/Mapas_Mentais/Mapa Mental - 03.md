## Capítulo 09 - A classe "String"

### Definindo e Atribuindo Strings

O termo **String** se refere a classe e ao objeto dessa classe, que possui duas formas de inicialização:

1. Inicialização **direta**

```cpp
string message("Hello world!");
```

- Na qual o objeto é criado diretamente no local da memória da variável `message`, utilizando o ponteiro de caracteres padrão da linguagem (`const char*`).

2. Inicialização **por cópia**

```cpp
string message = "Hello World!";
```

- Na qual o compilador tem o trabalho de converter o *String Constant* (ou string literal) em um objeto temporário e depois mover esse valor para a variável.
	- Em tese ocupa mais espaço e é mais lento, porém hoje em dia já é muito otimizado.

A inicialização é atribuir um valor para essa string e de acordo com o valor, o espaço na memória é ajustado automaticamente.

> Para registros de input, o operador `>>` só armazena uma palavra até o primeiro espaço, então para frases completas é utilizado o `getline()`.

### Operadores

Os operadores aritméticos e lógicos padrões mudam um pouco para este tipo de dado, enquanto `+` e `+=` são para *concatenação*, os demais `==`, !=, `<` ... são utilizados para comparação de strings.
- A principal precedência é o operador de `+`, depois os lógicos e por último atribuição.

### Inserção e Exclusão

Os métodos **insert** e **erase** são utilizados recebendo argumentos de posição na string, para realizar a manipulação do tamanho e caracteres presentes nesse "array".

- **Insert**: recebe um argumento do tipo *int*, com o Índice da string e o valor a ser inserido.
```cpp
string s1("Miss Summer");
s1.insert(5, "Ashely "); //Miss Ashely Summer
```

- **Erase**: recebe dois argumentos do tipo *int*, indicando a posição inicial e quantos caracteres após serão removidos da string.
```cpp
string s2("The summer-time");
s2.erase(4,6); //Output: "The Time"
``` 

### Pesquisa e Realocação

Os métodos **find** e **replace** recebem argumentos mais variados, um deles faz apenas a leitura e cópia da string e o outro mescla a remoção e adição dos anteriores.

- **Find**: recebe um valor em string para procurar dentro da string. 
```cpp
string youth("Bill is so young, so young!");
int first = youth.find("young");
```
> Em caso de não encontrar nenhum valor, é retornando -1 pelo método.

- O método find tradicional sinaliza a posição do primeiro carácter da primeira ocorrência, mas também existe o **rfind** que faz isso para a última ocorrência. 

- **Replace**: Os dois primeiros argumentos são a posição inicial e o tamanho da "substring" a ser realocada e o último argumento contém a nova "substring" em si.
```cpp
string s1("There they go again!"), s2("Bob and Bill");

int pos = s1.find("they");

if (pos != string::npos){
	s1.replace(pos, 2, s2); // "Here comes my love!
}
``` 
### Acesso de caracteres

O operador de subscrição `[]`é utilizado para acessar caracteres únicos em uma string, a partir do índice (posição do carácter na string), colocado dentro do operador e permitindo fazer comparações ou substituições.
- O índice `s.legth() - 1`é sempre o último carácter da string *s*.

> O método `at()` faz a mesma função desse compilador, mas não apresenta erros quando o índice estoura o tamanho da string.

---
## Capítulo 10 - Funções

### O que são funções em C++

Nas implementações de classes, existem **funções-membro** mais conhecidas como métodos que são as ações que as instâncias das classes podem executar (objetos).
> Nem toda função é um método

Mas no geral são blocos de código, que são implementações de algoritmos ou manipulações de dados, que por uma questão lógica de praticidade não precisa ser sempre escrita manualmente, sendo parte de muitas bibliotecas.

### Definindo uma função

Estrutura:
```cpp
[type] name([declaration_list])
{
	Actions
}
```

- A parte de *declaration_list* contém os nomes e tipos dos parâmetros da função, que também pode ser vazio, ou seja a função não recebe argumentos.
- Esses parâmetros ==costumam== ser variáveis locais, que só funcionam no escopo da função e copiam os valores dos argumentos.

> Parâmetros é o que a função pede, argumentos é o que a função recebe.

Para a definição de várias funções é comum a utilização de **protótipos**, ela segue toda a lógica anterior porém sem o bloco de código, tendo o objetivo de informar ao compilador qual são as funções que serão esperadas no código.
> Os nomes dos parâmetros podem ser omitidos, nesse caso.
#### Retorno da função

O tipo da função serve para indicar o tipo do *retorno* dessa função, ou seja, funções do tipo *int* ao final da sua execução devem retornar um valor inteiro que geralmente é utilizado para ser atribuído a alguma variável ou lógica booleana.
> Quando o valor retornando não corresponde ao tipo, o compilador tenta aplicar uma conversão, antes de sinalizar erro.
### Passagem de Argumentos

Primeiramente, os argumentos não precisam ser passados com o seu tipo, na definição da função é sinalizado o tipo de cada parâmetro, e é preciso que esse tipo e ordem seja preservado no chamado da função.

Além disso, existem duas formas de passar argumentos para uma função:

- **Passagem por valor**: Nesse estilo, a função recebe os valores dos argumentos, realiza uma cópia dos mesmos e atribui aos argumentos da função, ou seja, não altera exatamente as variáveis passadas como argumento.
> "Read-only" = Gera um maior uso de memória.

- **Passagem por referência**: Nesse caso, a função recebe a localização na memória dos argumentos, permitindo assim que ela tenha acesso aos seus dados e possa realizar modificações diretamente.

Existem vantagens para cada forma de passagem de valores, isso tudo dependendo do uso da função, por exemplo, na passagem por valor é possível utilizar variáveis do tipo `const` e fazer manipulações, já que a cópia não preserva essa propriedade do argumento.
### Funções em linhas

As chamadas de funções padrões, fazem uma transição do programa geral, para uma *sub-rotina* que é onde a função é realmente executada, inicializando seus parâmetros e o endereço de retorno ao código geral.

Assim, é executado todo o bloco de código da função e ao final retorna-se para o endereço original da função no código do programa.

> Por isso, os escopos das funções são locais, o que significa que não há relação entre o *function block* e o código geral.

Os objetos locais da função são colocados em uma estrutura de dados chamada *stack*, que funciona no principio LIFO (Last In First Out). Assim, toda a execução da função ocorre antes de se chegar novamente ao endereço de retorno.

Por isso, temos as *inline functions* que possuem um bloco de código de no máximo uma linha e portanto não precisam de toda essa transição para uma sub-rotina.

```cpp
inline int max(int x, int y)
{ return (x >= y ? x : y); }
```

Também, existe a possibilidade de construir o protótipo da função com valores padrões, o que significa que na falta de receber esses argumentos, a função utiliza os valores padrões na execução.

```cpp
double capital(double k0, double p = 3.5, double  n=1.0)
double endcap;

endcap = capital(1, 2, 3) // Ok
endcap = capital(1, 2)  // Ok
endcap = capital(1)  // Ok

endcap = capital()  // O primeiro parâmetro não tem valor padrão
endcap = capital(10, ,3)  // Not ok
endcap = capital(,,4)  // Not ok
```

- Regras:
	- Os valores padrões costumam ser inseridos no protótipo.
	- Se a definição da função acontecer no mesmo arquivo que o protótipo e antes da função ser chamada, os valores padrões podem ser colocados.
	- Ao definir um valor padrão para um parâmetro, todos os posteriores precisam ter um valor padrão também.
	- É preciso inserir os valores que não possuem valores padrões no chamado.
	- Pode substituir qualquer valor padrão no chamado.
	- Ao omitir um argumento, precisa omitir todos os posteriores.

> As funções podem ter o mesmo nome (*overload*), e a diferença entre elas é a assinatura, que consiste nos tipos e quantidade de parâmetros.
### Recursão

Uma função que chama a si mesma, é conhecida por **Função Recursiva**. Basicamente, ela possui uma condição de quebra, que é quando ela encerra o chamado a si mesma, e a partir disso ela retrocede seguindo o principio LIFO e continuando a execução do bloco de código de cada chamada, onde o valor de cada chamada é passado para a chamada anterior.

> Utiliza muito profundamente o sistema de stack, portanto é preciso ter segurança de que há memória suficiente nessa stack.

---
## Capítulo 11 -  Classes de Armazenamento e Namespaces

### Classes de armazenamento de objetos

Elas são determinadas, baseada na posição da sua declaração no arquivo de origem e no *specifier* que pode ou não estar presente (`extern`, `static`, `auto`, `register`).

Essas classes delimitam o tempo de vida do objeto e quais regiões do código podem acessar tal objeto (escopo), sendo ele de bloco, de arquivo ou de programa.

Os objetos com tempo de vida automático (criados em funções), são excluídos ao fim do bloco de código caso não haja uma definição direta, como a `static` (escopo de arquivos e programas) que mantém o objeto na memória até o fim da execução do código.

Objetos definidos fora de funções, são do tipo `extern`e portanto podem ser acessados e modificados (sem ser `const`) inicialmente por qualquer região do arquivo.

Ao declarar objetos utilizando o specifier `extern`no topo do código, temos um objeto global que pode ser acessada por outros arquivos.
```cpp
extern int global_score:
```
- Objetos globais, são definidos somente uma vez dentro do código origem, antes da primeira função do programa, e poderão ser declarados quantas vezes necessárias e em qualquer posição do programa.
### Classes de função

> Funções externas possuem escopo de programa & Funções estáticas possuem escopo de arquivo.

As funções por padrão são do tipo `extern`, então elas podem ser declaradas utilizando esse especificador ou não, e por padrão já podem ser definidas em outros arquivos.
```cpp
extern bool getPassword(void);
```

Já as funções estáticas, que realmente precisam ser declaradas com o especificar `static`possuem um escopo de arquivo.
### Namespaces

Quando se tem essa grande junção de diferentes objetos e funções de variados arquivos, começa a se ter problemas com nomes globais, entre saber a qual é exatamente a função ou objeto que esse nome se refere.

Para resolver esse problema, existe os **namespaces**, que são identificadores que permitem que os itens de escopo global sejam subdivididos em grupos.
```cpp
namespace myLib
{
	int count;
	double calculate(double, int);
}
```

Dessa forma a variável *count* e a função *calculate* pertencem ao **namespace: myLib**, dessa forma para referenciar esses elementos é preciso sinalizar o namespace deles.
```cpp
myLib::count = 7;
```

Isso permite diferenciar nomes iguais com diferentes funções. Para casos de nomes globais, basta omitir o namespace.

- Eles não são imutáveis e podem ser expandidos em qualquer ponto do código.
- Eles podem ser conectados, definir um namespace a partir de outro.

É possível fazer o uso de declarações dos namespaces com o *using*, como também fazer o uso de diretivas para referencias todos os identificadores para o mesmo namespace.
- Pode fugir um pouco da proposta de impedir conflitos e necessitar de usar operadores de escopo para definir a abrangência da diretiva.

---
## Capítulo 12 - Referências e Ponteiros

### Referência

Uma referência é um "apelido" para um objeto que já existe na memória, ou seja, ele não ocupa memória adicional.
> São uteis como argumentos e retornos de funções

O carácter `&`é utilizado para definir uma referência.
```cpp
float  x = 10.7;
float& rx = x; // or float &rx = x;
```

Assim temos a variável *x* e *rx* que apontam e manipulam o mesmo local na memória.

Importante perceber que esse `&` é diferente da utilização dele como operador de endereço, que tem a função de retornar o endereço de um objeto.
```cpp
&rx // Adress of x
```

Quando é feito uma passagem por referência de valores do tipo `const` de forma padrão, a variável se torna do tipo *read-only*.

O retorno de uma função pode ser do tipo referência, permitindo que o valor retornado seja manipulado como um objeto qualquer.
> É importante que o valor retornado existe, para que a referência dele possa ser retornada.

- Os operadores `+=` e `*=` também utilizam referência de valores na implementação.
### Ponteiros

O ponteiro representa o endereço e o tipo de outro objeto, a partir do operador de endereço `&`, dado um objeto é criado um ponteiro para esse objeto.

As *variáveis de ponteiro* possuem como tipo, o tipo do dado para o qual elas apontam, ou seja um *int pointer* é um ponteiro que aponta para um int. 

Na declaração dessas variáveis o `*` significa: "aponta para". Criando essa variável e atribuindo um endereço a ele temos:
```cpp
int *ptr;
int var = 100;

ptr = &var;
```

- Diferente da referência que era como se fosse um apelido, para uma região que já estava apontando para uma região na memória. o ponteiro ele ocupa memória, armazenando o endereço do objeto que ele aponta.

Depois de atribuir um endereço a variável de ponteiro, pode-se acessar o valor ao qual o ponteiro aponta, utilizando o *indirection operator* `*`.
#### Passagem por ponteiro

É possível que os argumentos passados para uma função sejam ponteiros, assim os parâmetros precisam ser declarados como variáveis de ponteiro.
