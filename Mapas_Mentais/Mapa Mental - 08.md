## Capítulo 25 - Polimorfismo

### Conceito

A ideia do polimorfismo é que os métodos possam assumir diferentes comportamentos a depender das circunstâncias.

- **Polimorfismo de Sobrescrita**: As classes derivadas podem alterar o comportamento de métodos da classe base, executando uma ação condizente a sua individualidade, com esse método tendo a mesma assinatura (nome, parâmetros de mesmo tipo e na mesma ordem e se ele é do tipo const ou não).

- **Polimorfismo de Sobrecarga**: Nesse caso, dentro de uma mesma classe podem ter vários métodos com o mesmo nome, mas com assinaturas diferentes, assumindo diferentes comportamentos.
### Métodos Virtuais

Isso é relevante nos casos onde se quer ter a liberdade de armazenar qualquer objeto das classes derivadas, armazenando em ponteiros do tipo da classe base. 

Mas ao fazer isso, você não quer perder o acesso ao comportamento único do método presente na classe derivada, para isso são utilizados os **métodos virtuais**.

O compilador através de uma **Tabela de Métodos Virtuais** consegue identificar em tempo de compilação qual é objeto verdadeiramente instanciado, mesmo que a declaração seja da classe base, executando o método da classe derivada.

> Nesse caso a classe base precisa ter o método declarado como virtual e a classe derivada um método com a mesma assinatura.

```cpp
class Base {
	virtual void display() const{
		cout << "Hello!";
	}
}

Class Derivate {
	void display() const{ // Implicitamente virtual
		cout << "Hi!";
	}
}
```

- Construtores **não** podem ser virtuais.
#### Redefinição

Na redefinição, ao escrever um método de mesmo nome na classe derivada com assinatura e/ou retorno diferentes do método da derivada, o da base fica oculto, quando o método é chamado através do próprio objeto da classe derivada.

- Quando não há declaração de um método na derivada que existe na base, ao chamar o método pelo objeto da base, o compilador automaticamente procura na base.

Já para o caso de ser um ponteiro/referência da classe base, o método criado na classe derivada é inacessível por não existir na classe base.
#### Destrutor

Ao utilizar a classe base para construir um array de ponteiros para os objetos da classe derivada alocados dinamicamente na memória, é preciso definir o destrutor da classe base como virtual, mesmo que ele não tenha corpo (*dummy*).

```cpp
virtual ~Base(){}
```
### Dynamic Cast

Para acessar métodos exclusivos seja da classe base (*upcast*) ou da classe derivada (*downcast*), é possível realizar o *dynamic cast*, ele garante a segurança ao realizar esses casts (principalmente o downcast), visto que em caso de não ser possível fazer esse cast ele retorna um ponteiro nulo.

Dessa forma, é possível fazer condicionais para testar possíveis casts até encontrar o que se encaixa e poder acessar o método da classe derivada.

---
## Capítulo 26 - Classes Abstratas

### Métodos virtuais puros

Esses são os métodos que definem uma classe abstrata, a ideia é que alguns métodos não fazem sentido se não forem chamado através de classes derivadas, portanto, eles são definidos como **virtuais puros**.

- Dessa forma, na classe base esses métodos não possuem nenhum comportamento definido.

```cpp
virtual void demo() = 0; // A declaração do virtual puro é atribuir 0
```
### Classes Abstratas X Classes Concretas
> Uma classe que possui ao menos um método virtual puro, é tida como **Classe Abstrata**.

Classes abstratas não podem instanciar objetos diretamente, evitando a chamada de métodos que não possuem comportamento definido.

O contraponto é que as classes concretas são as que podem instanciar objetos, ou seja, não possuem métodos virtuais puros. Para os casos em que elas são derivadas de classes abstratas, é necessário que elas implementem todos os métodos virtuais puros herdados.

- Classes abstratas podem ser derivadas de classes concretas.
#### Construtor Protegido

O conceito de abstração está relacionado a impossibilidade de criar instâncias diretas de uma classe, nessa lógica, outra forma de construir uma classe abstrata é definir um construtor do tipo *protected*, visto que dessa forma apenas classes derivadas podem chamar esse construtor.

> Métodos protegidos só podem ser acessados pela própria classe, por classes derivadas e funções do tipo *Friend*
#### Ponteiros & Referências

Embora, não seja possível criar objetos diretos de uma classe abstrata, as técnicas de utilizar ponteiros ou array de ponteiros para armazenar objetos das classes derivadas funcionam da mesma forma que na classe concreta.
### Atribuição Virtual

Ao lidar com essa relação de ponteiros de classes bases para armazenar objetos das classes derivadas, é muito importante realizar a sobrecarga do operador de atribuição `=` e tornar essa sobrecarga do tipo virtual.

Isso serve para evitar que ao fazer a atribuição de um objeto da classe derivada para uma referência da classe base, os membros exclusivos da classe derivada não sejam descartados, um fenômeno conhecido como *Slicing*.

Assim é necessário redefinir esse operador para cada classe derivada duplamente, visto que:

- A versão padrão de um operador de atribuição espera um objeto do seu próprio tipo, ou seja, o método virtual da classe base esperaria um objeto do tipo da classe base.

- Porém, ao lidar com sobrescrita de métodos virtuais a assinatura do método que vai sobrescrever o método virtual da base precisa ser a mesma.

- Para isso, é feito uma definição de um operador de atribuição que recebe um objeto do tipo da classe base, mesmo que essa classe seja do tipo abstrata, além de ser feito uma segunda definição do operador mantendo sua própria atribuição (recebendo um objeto do seu próprio tipo).

> No caso específico de sobrescrita de métodos, o C++ permite que um método sobrescrito retorne um ponteiro ou referência para uma classe derivada, isso que garante essa implementação acima

---
## Capítulo 32 -  Templates

### Conceito

É uma ferramenta utilizada para evitar a construção de códigos de funções ou classes muitos semelhantes mas que funcionam para tipos diferentes, como se fosse uma "virtualização" completa das classes e funções.
### Definição

Sua definição é sempre precedida pela keyword `templace <class T>` (o "T" é uma convenção) onde `T` é o parâmetro que recebe o tipo futuro que o template vai assumir.

- **Template de Função**: Recebe um grupo de instruções usando um parâmetro em vez de um tipo concreto.

- **Template de Classe**: Define uma classe parametrizada:
	- Os métodos de uma classe template também são parametrizados.
	- Se os métodos forem definidos fora da classe precisam utilizar a sintaxe de template de função e o operador de escopo `::`.
	- Os métodos normalmente são definidos no mesmo arquivo `.h`.

### Instanciar

A definição de um template não cria código de máquina antes da instanciação.

- **Instanciação de Funções**: Ocorre na primeira chamada da função, onde o compilador determina o tipo de `T` com base nos argumentos passados.

- **Instanciação de Classes**: Ocorre implicitamente na definição de um objeto dessa classe.
#### Parâmetros

- **Múltiplos Parâmetros:** É possível definir algo como `template<class U, class V>`.

- **Parâmetros que não são tipos:** Além de nomes de tipos, pode-se usar parâmetros "normais" como inteiros, ponteiros ou referências.
    - **Exemplo:** Um parâmetro inteiro `n` para definir o tamanho de um array fixo dentro do template, eliminando a necessidade de alocação dinâmica.

- **Restrições**: Parâmetros que não são tipos (como o `n` mencionado) não podem ser modificados dentro do template e não podem ser tipos de ponto flutuante (como `double`), a menos que sejam passados como referência ou ponteiro.
#### Argumentos
> Precisam coincidir exatamente com os parâmetros definidos

- **Sem Conversão Implícita:** Diferente de funções normais, o compilador não converte `float` para `double` automaticamente em templates.

- **Restrições de Argumentos:**
    - **Referências:** Devem ser objetos globais ou estáticos.
    - **Ponteiros:** Devem ser endereços de objetos ou funções com escopo global.
    - **Valores comuns:** Devem ser expressões constantes.

> Assim como em funções normais, você pode definir valores padrão para os parâmetros de um template