## Capítulo 4 - Entrada e Saída com "Streams"

### Streams (Fluxos)
> Classe que gerência instâncias (objetos) de entrada e saída

- `cin`: Objeto da classe *istream* para controle de [^1]entrada padrão (leitura).
- `cout`: Objeto da classe *ostream* para controle de [^2]saída padrão (escrita).
- `cerr`: Objeto da classe *ostream* para controle de saídas de erro sem [^3]buffer.
- `clog`: Objeto a classe *ostream* para controle de saídas de erro com buffer.
#### Classes de Entrada & Output (I/O)

As classes *streams* seguem uma lógica de herança, que começa com a classe `ios`:
- Gerencia a conexão do fluxo de dados físico (hardware) que escreve os dados do programa executado para um arquivo ou impressão na tela.
- Contém as funções básicas necessárias para formatação de dados.

A classe `iostream`é uma junção das classes `istream`e `ostream` que lidam respectivamente com a leitura e escrita de dados, permitindo gerenciar ambas as tarefas a partir dessa classe.
### Formatação e Manipulação (Dados)

Manipuladores são funções que chamam métodos (recebem flags) das classes definidas pela classe pai `ios`, e que manipulam a formatação do dado que está sendo escrito ou lido.

> Eles substituem o uso direto da implementação das flags com os métodos `setf()` e `unsetf()`.

```cpp
cout << showpos<< 123; // Output: +123

// Desse momento em diante, os números positivos serão impressos com o sinal na frente, pela ativação da flag no objeto "cout"
```

As [^4]**flags de formatação** mais usuais são as que possuem esses manipuladores, que exercem o mesmo efeito de forma mais prática. 

As opções de formatação incluem:
- Definir qual sistema numérico será utilizado (o programa realiza a conversão).
- Usar letras maiúsculas ou minusculas
- Adicionar sinal em números positivos
- Mudar a precisão de um número de ponto flutuante
- Forçar uma impressão em ponto flutuante e cortar ou não zeros não-significativos
- Definir o tamanho de um dado
- Selecionar carácter de preenchimento
- Alterar a saída dos valores booleanos (inteiros $\to$ string)
#### Extras: 

1. A utilização de `const`com os [^5]protótipos de métodos, significa que o método irá realizar apenas efeitos de leitura (leitura de argumentos e retorno de função).

2. A utilização de manipuladores que precisam de argumentos, exige a importação de outra classe filha da `ios`que é a `iomanip`.

3. Os métodos `sync()` & `clear()`são utilizados para limpar o *input buffer* e *error flags*.
### Campos de texto

O operador `>>` tem como função a leitura do **primeiro input** inserido, convertendo para o tipo de dado referenciado na definição da variável e atribuindo esse input na variável.

- Ele termina sua leitura no encontro do primeiro espaço vazio, por isso só pode ser usado para ler uma única palavra no máximo.
- Contudo, em um mesmo input com tipos de dados diferentes, o restante do que não foi salvo na variável, permanece registrado no *buffer*, e é lido na próxima operação de leitura (importância dos métodos de limpeza).

```cpp
int i;
cin >> i; //123FF

// int = 123
// Próxima operação de leitura, "FF\n" salvo no buffer

string s;
cin >> s; //oi

// ch = FF
// Próxima operação de leitura, "oi\n" salvo no buffer
```

Também existem os métodos `get()` e `put()`que fazem a leitura ou escrita de um único carácter.
- O `get()` salva até mesmo espaços em branco caso estejam no buffer.
- O `put()` faz um output não formatado.

Para a leitura de uma linha inteira de texto, é preciso utilizar o `getline(cin, text)`.

---
## Capítulo 5 - Operadores para os tipos fundamentais

### Operadores Aritméticos

- `+`: Adição
- `-`: Subtração
- `*`: Multiplicação
- `/`: Divisão
- `%`: Resto da divisão
- `++`: Operador de incremento
- `--`: Operador de decremento
#### Especificações

 - Divisões entre números inteiros (*int*) gera um inteiro também, a menos que um dos valores seja do tipo *float*.
 
- O operador de resto, só pode ser utilizado entre dois inteiros.

- A hierarquia de operadores é a mesma da matemática, sendo o de resto da mesma categoria e multiplicação e divisão.

- Os operadores de incremento e decremento no prefixo, significa que a variável tem seu valor incrementado antes da compilação, e no sufixo é após compilar.

- O operador de subtração pode ser usado como operador de sinal, invertendo o sinal do valor.
### Demais operadores (Lógicos e Relacionais)

- `=`: Operador de atribuição (menor precedência, última execução)
	- Existem operadores de atribuição composto com os aritméticos, que é uma *syntatic sugar*, para aplicar o cálculo e atribuir o valor na variável.

- `<` & `>` & `< =` & `> =`: Operadores de relação numéricas.

- `==`& `! =`: Igualdade e diferença (relacionais).

- `&&`: O *AND* lógico.

- `||`: O *OR* lógico.

---
## Capítulo 6 - Controle de Fluxo

### Instruções de repetição ou gerenciamento de ação

#### while

Em síntese, enquanto a expressão booleana recebida como argumento for *True* o programa vai repetir o processo interno dessa instrução.

> Não é necessário criar um corpo do processo com `{}` caso só haja uma linha de ação.
#### for

Similar ao anterior no quesito de repetição de um processo, contudo, nessa situação existe uma quantidade pré-definida de vezes que esse processo interno vai ser repetido, então, em tese, existe uma garantia de quê o loop irá se encerrar.

```cpp
// Esses casos são bem similares entre si

while (expressao)
for (; expressa ; )
```

A vírgula pode ser utilizado na declaração de um **FOR**, para fazer varias inicializações de variáveis, na primeira expressão do cabeçalho do loop (a separação das expressões ocorre pelo ponto e vírgula):

```cpp
for (i = 0, limit = 0; i < limit; i+= 2)
{
	// processo
}
```
#### do-while

Aqui o controle do loop (cabeçalho) fica na verdade no final (rodapé), isso significa que, mesmo que a expressão seja falsa, o processo vai rodar pelo menos uma vez antes de ser feito a checagem da expressão.
#### if-else

Aqui é um controle de fluxo padrão que utiliza condicionais simples para execução direta de apenas um processo.

Caso a expressão seja verdadeira, ação *X* é executada, caso contrário (não há necessidade de especificar uma expressão), ação *Y* é executada.

> É possível inicializar variáveis dentro da expressão do **IF**.

Além disso, existe o `else if`que serve para executar apenas se a etapa anterior não for *True*, assim criando expressões encadeadas.
#### Expressão condicional 

Frequentemente associado com o **Operador Ternário**, trata-se da utilização do operador `?` que constrói uma condição para decidir qual valor será definido.

```cpp
condicao ? expressao1 : expressao2

// Expressao1 = True
// Expressao2 = False
```
#### switch

Aqui é um gerenciamento similar ao *if*, porém com expressões apenas de comparação. Na qual, é definido um valor e criado casos de *match* com esse valor, assim são testados os casos até que seja encontrado um que seja igual.

É preciso finalizar o processo de busca dentro desse primeiro caso que deu *match* para que ele não procure outros matchs, além disso também há o caso *default* para o cenário onde não há nenhum match.
### Pulos nas instruções

Existem instruções que permitem avançar ou encerrar etapas dentro das instruções anteriores:

- `break`: Encerra imediatamente o processo dentro da instrução.
- `continue`: Interrompe a execução processo atual para seguir diretamente para a próxima iteração do mesmo processo.
- `goto`: Cria uma espécie de atalho para um ponto pré-definido do processo.

---
## Capítulo 7 - Constantes simbólicas e Macros

### Definição de Macros

A etapa de pré-processamento ocorre antes da compilação, e é útil para o programa pois faz a implementação dos *headers files*, como também pode realizar a substituição de variáveis ou instruções muito utilizadas no programa, diminuindo o consumo de memória.

Isso funciona através do `#define name substitutetext`, esses são os chamados **MACROS**, quando eles substituem valores constantes são as *constantes simbólicas*.
> Uma boa prática é escrever o nome dessas variáveis constantes com letras maiúsculas.

É possível construir até estruturas de funções com os macros:
```cpp
#define SQUARE(a) ((a) * (a))
```

Também é permitido, "desativar" o macro em certas regiões do código, utilizando a "flag" `#undef macro-name`, toda a região após essa diretiva não tem mais acesso ao macro.

Além disso, é possível criar regiões no código que só são executadas caso um macro específico esteja definido, utilizando as diretivas `ifddef macro-name`& `endif`.

---
## Capítulo 8 - Conversão de Tipos Aritméticos

O compilador consegue realizar conversões de tipagem implícitas que permitem que operadores de diferentes tipos de dados possam ser utilizados entre si, logicamente, se a conversão entre esses dados for possível de ser feita pelo compilador.

Existe uma técnica da linguagem conhecida como **Integer Promotion**, na qual quando necessário os dados são convertidos para `int` na execução de cálculos (isso para dados menores que o `int`).

- `char` / `signed char` / `unsigned char`
- `short` / `unsigned short`
- `bool`

Além disso, os resultados de expressões aritméticas são sempre que possíveis convertidos para o tipo definido na variável.
> O mesmo ocorre para argumentos de chamadas de funções

Existe o operador *(type)*, colocado antes de uma expressão para fazer a troca do tipo da expressão, para o tipo dentro dos parênteses.
> Ele possui uma precedência alta entre os operadores aritméticos (ou seja a troca acontece antes do cálculo).

---

[^1]: leitura de dados, geralmente do teclado.

[^2]: envio de dados, geralmente para o terminal.

[^3]: Memória temporária de pré-carregamento.

[^4]: Determinam como caracteres são recebidos ou retornados pelo programa.

[^5]: Declarações sem definição (Pré-processamento).
