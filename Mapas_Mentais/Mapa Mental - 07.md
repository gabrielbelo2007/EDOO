## Capítulo 23 - Herança

A herança permite que atributos e métodos definidos em uma **classe base** sejam herdados para uma ou mais **classes derivadas**. Assim, dois benefícios principais:

- **Abstração**: Características gerais são "mascaradas" em classes bases.
- **Re-usabilidade**: Alterações se tornam mais fáceis e menos cópia de código.
### Relações "Is" & "Has"

Dentro do conceito de classe derivada, temos a relação *is* ("**É** uma classe derivada"), que especifica que um objeto é uma extensão da classe base, por exemplo, um ônibus pode ser uma extensão da classe *carro* visto há similaridades com um carro de passeio.

Além dessa relação, também existe a *has* ("**TEM** uma classe base"), que significa que ao menos um dos seus membros é do tipo de outra classe, assim, caso não exista nenhuma extensão de uma classe base, essa classe não é considerada uma classe derivada.
### Classes derivadas
> Podem ter classes bases diretas ou indiretamente (herda classe derivada).

O acesso aos membros da classe base são definidos tanto nos próprios membros da classe base como na definição da classe derivada, através das keywords: `public`, `private` e `protect`.

- **Public**: Esses membros podem ser acessados de qualquer forma, seja por métodos públicos da classe derivada ou de forma direta pelo objeto da classe derivada.

- **Protect**: Esses membros só podem ser acessados através de métodos públicos da classe derivada.
	- Nas classes derivadas os métodos `protect` da classe base só podem ser manipulados por métodos.
	- No geral, esses métodos também podem ser manipulados por *friend functions*.

- **Private**: Esses métodos não podem ser acessados de nenhuma maneira, visto que eles não são herdados para a classe derivada.
	- Geralmente acessados através de métodos públicos da classe base.
#### Consulta de nome

Na procura do nome de um membro, o compilador segue duas regras:

- Procura o nome na classe derivada primeiro.
- Caso o nome não seja encontrado, o compilador avança para a classe base (ou a próxima derivada) e busca por um membro público com mesmo nome.

Esse processo contínua percorrendo toda a árvore de heranças até a classe base inicial.
#### Redefinição
> Alterar o valor ou função do membro

É possível redefinir os membros da classe base na classe derivada, dessa forma, ao acessar esse membro pelo objeto da classe derivada, por padrão o que será executado é o membro redefinido, ele oculta o membro da classe base.

Não acontece nenhuma alteração na classe base e o membro dessa classe ainda pode ser acessado utilizando o operador de escopo `::` e o nome da classe base (por isso não é um tipo de sobrecarga).
#### Construtores & Destrutores

A construção de um objeto de uma classe derivada começa construindo o objeto da classe base para em seguida construir o objeto da classe derivada.

Sendo assim, existem diversas opções para definir o construtor, alguns destaques para:

- **Construtor Padrão**
	- Esse construtor chama o construtor padrão da classe base, caso esse construtor não tenha parâmetros, os membros herdados pela classe derivada precisarão definir seus valores através dos métodos públicos (*set*) da classe base.
```cpp
PassCaar::PassCar(const string& tp, bool sr, int n, const string& hs)
{
	setNr(n);
	setProd)(hs);
	
	passCarType = tp;
	sunRoof = sr;
}
``` 

- **Construtor com inicializador**
	- Esse construtor chama o construtor da classe base com argumentos que já são utilizados para fazer definir os membros (possivelmente) herdados pela classe derivada.
```cpp
PassCaar::PassCar(const string& tp, bool sr, int n, const string& hs) : Car(n,hs)
{
	passCarType = tp;
	sunRoof = sr;
}
``` 

- **Construtor com múltiplos parâmetros**:
	- Esse construtor chama o construtor da classe base assim como anterior, mas além disso também é possível definir diretamente no construtor o valor dos membros criados na própria derivada.
```cpp
PassCaar::PassCar(const string& tp, bool sr, int n, const string& hs) : Car(n,hs), passCarType (tp), sunRoof (sr)
```
##### Ordem de Execução

- **Construção:**
    1. O construtor da **classe base** é chamado primeiro (para criar o sub-objeto base).
	2. O construtor da **classe derivada** é executado em seguida.

- **Destruição:**
    1. O destruidor da **classe derivada** é chamado primeiro.
    2. O destruidor da **classe base** é executado automaticamente depois.

---
## Capítulo 24 - Conversão de Tipos em Hierarquias de Classes

Essa conversão permite que a classe base funcione como um termo genérico para gerenciar múltiplos casos especiais (como tratar `PassCar` ou `Truck` simplesmente como `Car`).

- Importante principalmente para arrays de objetos derivados da mesma classe base.
### Conversões para classes bases

Objetos do tipo de classes derivadas podem ser atribuídos em objetos da classe base, isso caus uma **conversão de tipo implícita.** Isso implica em perder as características adicionais da classe derivada e manter os membros públicos herdados da classe base.
- Isso também pode ocorrer com **ponteiros** do tipo da classe base que recebe um objeto da classe derivada e com **referências**.

Essa conversão de tipos pode ocorrer na declaração dos parâmetros de uma função, aonde na sinalização do tipo de cada parâmetro, na chamada da função essa conversão pode acontecer implicitamente caso necessário.
### Conversões para classes derivadas

Nesse caso, por padrão isso ocasiona um erro, pela falta de valores para os membros adicionais da classe derivada (pressupõe-se que existam), a não ser que exista uma atribuição especificamente definida para isso ou um construtor por cópia com um parâmetro de referência para a classe base.
### Upcasts & Downcasts

#### Upcast

Ocorre quando a conversão de tipo sai da classe derivada para a classe base.
 - Sempre possível e segura.
#### Downcast

Ocorre quando a conversão de tipo sai da classe base para a classe derivada.
- Nunca ocorre de forma implícita, exigindo operador e não é recomendando na maior parte das situações.
- Só é segura quando o objeto apontado pelo ponteiro é realmente do tipo da classe derivada que está se fazendo o cast.

Duas formas de fazer o *downcast* do ponteiro da base para um ponteiro da derivada.

```cpp
Car* carPtr = &cabrio;
( (PassCar*) carPtr )-> display();

static_cast<PassCar*>(carPtr)->display();
``` 

- No primeiro caso precisou de parênteses pois o operador `->` tem precedência maior em relação ao operador de cast `(type)`. 

- Para garantir a segurança em classes polimórficas, o C++ introduz o `dynamic_cast`, que verifica a validade da conversão em tempo de execução.
### Métodos virtuais

Para lidar com essa falta de acesso aos métodos de uma classe derivada, quando elas são armazenadas em ponteiros das classes bases, existem os **métodos virtuais**.

Nesse caso, garante que o método chamado é do tipo instanciado do objeto e não do tipo declarado, ou seja:

1. .A classe base terá um método virtual.
2. Esse mesmo método irá existir na classe derivada.
3. Ao chamar esse método através do ponteiro da classe base, como o ponteiro aponta para uma instância (objeto) da derivada, o método dessa derivada é o executado.
	- Em outras palavras ocorre uma sobrescrita do método da base.

> Também é importante que o destrutor da base seja virtual, para garantir que o destrutor do objeto instanciado seja chamado ao executar o `delete` no ponteiro.
#### Classe abstrata

Essa é uma classe que não pode ter objetos diretamente, servindo como uma interface para classes derivadas, por exemplo:
- Pode ser um array de ponteiros para variados classes derivadas.

Ela é definida por conter métodos virtuais puros, que não possuem implementação, é por isso que não pode existir objetos, ela aguarda a implementação a partir da instância dos objetos das classes derivadas.
- A sobrescrita é obrigatória nesse caso.

---
## Capítulo 28 - Tratamento de Exceções

As funções geralmente trazem um retorno numérico como primeira checagem de erros:
- 0 = Tudo certo!
- 1 = Algum erro!

- **Valores de Retorno:** Funções usam valores especiais para indicar erros, exigindo verificações constantes após cada chamada.

- **Flags Globais:** Variáveis de erro globais são configuradas e devem ser checadas posteriormente.

- **Risco:** Esquecer uma dessas verificações pode levar a resultados incorretos ou ao travamento do computador.
### Conceito

Os erros são reportados para *calling enviromnet* que faz o controle dos erros, dessa forma a aplicação não precisa ficar verificando seus erros continuamente, eles são automaticamente transferidos para essa região.

Ao reportar um erro, informações específicas sobre o error podem ser adicionadas e essas informações são tratadas nas rotinas de tratamento do *calling enviroment*.
#### Throw

A declaração do *throw* cria um objeto de exceção temporário que será "jogado" no *calling enviroment*, ele pode pertencer a qualquer tipo exceto `void`.
#### Try & Catch

Esses dois blocos trabalham juntos,onde dentro do `try` temos esses lançamentos de exceções pelo `throw` e dessa vez eles são capturados pelo `catch`.

- Geralmente dentro do `try` são colocados funções que possuem retornos de erros similares ao original.

Idealmente é importante que cada exceção retorne um único erro para ser tratado por um `catch` exclusivo, o `catch` faz seu match quando:

1. Ele é idêntico ao tipo de exceção que o `throw` lançou.
2. Uma classe base do tipo da exceção.
3. Um ponteiro da classe base onde a exceção é um ponteiro para a classe derivada.
### Funcionamento e Desenrolar da Pilha (Stack Unwinding)

Quando uma exceção é lançada via `throw`, o controle do programa sai imediatamente do bloco `try`.

- **Limpeza Automática:** Ocorre o "desenrolar da pilha", onde objetos locais não estáticos criados dentro do bloco `try` são destruídos ordenadamente.

- **Busca por Handlers:** O sistema procura sequencialmente o primeiro bloco `catch` cujo tipo declarado seja idêntico ao da exceção, ou uma classe base desta.

- **Handler Genérico:** A sintaxe `catch(...)` define um manipulador para qualquer tipo de exceção e deve ser sempre a última da lista.
#### Aninhamento:

- Blocos `try` podem conter outros blocos `try`. Um handler interno pode pré-processar um erro e usar a instrução `throw;` (sem argumentos) para relançar a exceção para o bloco externo.