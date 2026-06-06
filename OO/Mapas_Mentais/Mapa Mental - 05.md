## Capítulo 19: Sobrecarga de Operadores

Operadores podem ser sobrecarregados por classes, permitindo que sejam definidos comportamentos customizados para os operadores padrões, quando eles são utilizados com os objetos da classe.

Porém existem algumas regras a serem seguidas:
- Não se pode criar novos operadores, apenas alterar o comportamento dos existentes.
- Não se pode alterar comportamento de operadores, se todos os operandos forem de um tipo fundamental: *int*, *float*, *double*, *char*...
- A precedência original dos operadores sempre será mantida.
- Não se pode modificar quantos valores um operador manipula.
- Operadores sem sobrecarga: `.`, `::`, `?:`, `.*` e `sizeof`.

Naturalmente, muitos operadores já são sobrecarregados como o `/`, que caso os dois valores sejam inteiros ele retorna um inteiro e nos casos onde pelo menos um valor é de ponto flutuante, o retorno é de ponto flutuante também.

> O uso dessa sobrecarga é tornar mais intuitivo ações dentro de classes, do que o padrão da chamada de métodos.
### Funções de Operadores

> Geralmente os funções de operadores são definidas como métodos de classes.

Na definição de um operador binário como um método, o operador da esquerda sempre precisa ser um objeto da classe na qual essa função de operador está definida (`*this`), assim o operador da direita é passado como argumento para a função.

Para fazer a definição dessa função, geralmente é utilizado a palavra *operator* seguida pelo operador que se deseja alterar.

```cpp
bool operador< ( const DayTime& t) const;
```

Nesse caso o operador `<` está sendo sobrecarregado, para permitir uma comparação melhor dos objetos de dias da classe *DayTime*.

```cpp
depart1 < depart2 // Equivalente -> depart1.operator<1(depart2)
```
#### Operadores similares

No caso de sobrecarga de operadores como `+` e `-` isso não significa que os operadores `+=` e `-=` são sobrecarregados, eles não possuem relação direta entre si.
#### Operadores de Negação, Adição e Subtração

O operador unário de negação não altera o operando, ele costuma ser do tipo *const* que cria um objeto temporário para retornar o seu valor.

Além disso, os operadores de adição e subtração também não alteram diretamente seus operandos, salvando objetos temporários para fazer o retorno do resultado preservando os valores iniciais dos operandos.
### Uso de Funções de Operadores

Caso os construtores da classe criem objetos de tipos específicos, esses tipos podem ser utilizados com operadores para objetos dessa classe, mesmo que não haja operadores definidos diretamente para esses tipos.
- O que acontece é que o construtor realiza a transformação desse valor em um objeto da classe e então o operador utiliza a função definida para dois objetos.

Para os casos onde é necessária uma simetria entre a ordem dos operandos, onde um dos operandos não é um objeto da classe, é preciso utilizar funções globais, que conseguem receber ambos os operando como argumentos e fazer a conversão para objetos da classe antes de realizar a operação.
- Isso sem precisar garantir que o objeto da classe esteja sempre na esquerda.

Isso só não é válido para os seguintes operadores: `+=`, `-=`, `*=`, `/=` e `%=`.

Definição:
```cpp
net + 1.2 and 1.2 + net

// Equivalentes

operator+ (net, 1.2) and operator+(1.2, net)
```
### Funções & Classes "amigas"

Como as funções globais não possuem acesso aos dados privados de uma classe, utiliza-se a palavra-chave *friend* para dar uma permissão especial as funções de acesso a dados privados.

Já as classes do tipo *friends*, significa que todos os membros privados de uma classe podem ser acessados pelo classe que recebeu a permissão de "amizade".

>  Importante tomar cuidado com essas propriedades, pois podem comprometer diretamente a tese de encapsulamento.

```cpp
class Result
{
	friend class ControlPoint;
}

class A
{
	friend void globFunc(A* objPtr);
}
```
### Operadores **<<** e **>>**

Para permitir que os objetos das classes sejam usados diretamente com `cout`e `cin`, é necessário sobrecarregar os operadores de deslocamentos de bits.

- Eles devem ser funções globais, pois o operando da esquerda sempre pertence as classes de `ostream`ou`istream.
- Geralmente são definidos como *friend* para ter acesso aos objetos privados que serão impressos.
- A função precisa retornar uma referência de fluxo (stream) para permitir o uso encadeado: `cout << obj1 << obj2`.

> Esse é um exemplo de operador que atua sobre um objeto de uma classe não manipulada pelo usuário, para esses casos o uso recomendado são funções globais.

---
## Capítulo 20: Conversão de tipos para classes

### Construtores de conversão

Construtores que são chamados com um único parâmetro, exceto o construtor de cópia, são considerados construtores de conversão.

Por exemplo, se uma classe *Euro* tiver um construtor *Euro(double x)* então o compilador pode transformar automaticamente o valor *double* em um objeto dessa classe sempre que precisar. 

> Similar ao que ocorre quando existe o uso de funções de operadores definidos apenas para dois objetos da mesma classe e um dos elementos é transformável por um construtor, essa transformação acontece automaticamente.
### Funções de conversão

São métodos especiais que definem como um objeto pode ser transformado em outro tipo.

```cpp
operator type_destination() const;
```
- Essas funções não precisam declarar um tipo de retorno, pois está implícito no nome da função, para qual tipo de destino aquela função leva.
### Ambiguidades das conversões de tipo

O C++ realiza conversões implícitas para facilitar a compilação de expressões onde há incompatibilidade de tipos. 

Por exemplo, se tentarmos somar `objetoEuro += 10.5`, o compilador busca um construtor de conversão para transformar 10.5 em um objeto da classe *Euro* antes da soma.

> No entanto, conversões implícitas automáticas podem levar a erros lógicos difíceis de detectar. 

Para evitar isso, o programador pode usar a palavra-chave **explicit** antes da declaração do construtor. Isso impede que o compilador use esse construtor para conversões automáticas, exigindo que o programador faça a conversão manualmente (ex: `static_cast<Euro>(valor) ou Euro(valor)`).
#### Falha por ambiguidade

Um dos problemas para o caso da conversão implícita é a **falha por ambiguidade**, que ocorre quando o compilador encontra mais de uma maneira válida de resolver uma expressão e não consegue decidir qual utilizar.

Para prevenir desses erros:

- **Usar explicit:** Marcar construtores de parâmetro único como explicit para evitar surpresas no comportamento do programa.
- **Métodos Nomeados:** Em vez de sobrecarregar o operador de conversão (como operator double()), é aconselhável criar métodos com nomes claros, como `asDouble()` ou `to_string()`. Isso elimina ambiguidades, pois a conversão só ocorrerá quando chamada explicitamente.