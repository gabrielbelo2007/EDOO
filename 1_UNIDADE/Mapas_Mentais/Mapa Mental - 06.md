## Capítulo 21: Alocação de Memória Dinâmica

### Operadores  *New* e *Delete*

Os operadores `new` e `delete` são utilizados para alocar e liberar memória respectivamente, com essa memória sendo manipulada na região da memória chamada de *heap*, a qual os programas conseguem acessar uma grande quantidade de espaço livre para execução.
#### New

O operador `new` espera o tipo do objeto a ser criado como argumento e ao criar esse objeto na memória retorna o endereço desse objeto, que é normalmente atribuído a um ponteiro de mesmo tipo (caso contrário apresentará erros).

A sintaxe por padrão, incluindo a inicialização direta do objeto:
```cpp
long double *pld = new long double(10000.99);
```
#### Delete

Ao fazer alocação direta de memória da heap para instanciar um objeto com `new` é preciso tomar cuidado para não deixar essas ocupações de memória permanecerem na *heap* após o fim da execução do programa, causando impactos na performance do computador.

Para fazer essa limpeza, é utilizado o operador `delete` com uma simples sintaxe, antes do ponteiro relacionado ao objeto instanciado com o `new`: 
```cpp
delete pld;
``` 

Dois pontos importantes sobre esse operador é:
- Não chame o `delete` duas vezes para o mesmo objeto.
- Não use o `delete` para liberar memória estaticamente (em tempo de compilação) alocada.
### Alocação dinâmica

#### Classes

Os dois operadores anteriores podem ser utilizados para alocação de memória dinâmica para classes, para isso utilizando de construtores para inicialização dos atributos e suas alocações na memória.

Na parte da limpeza, é recomendado utilizar inicialmente o destrutor para encerrar as instâncias da classe, logo após utilizar o `delete`, mesmo que em teoria ele consiga lidar com a limpeza de forma geral.

```cpp
Euro* pEuro = new Euro;
```

> Isso faz a alocação do objeto inteiro da classe Euro, caso exista memória suficiente para tal no sistema, esse objeto é instanciado e seu endereço é retornado.
#### Arrays

Para compilar um programa que vai armazenar uma quantidade indefinida de elementos em um array, a melhor forma de lidar com isso é permitir a alocação dinâmica dessa memória a medida que o programa necessite, esse é o *Dynamic Array*.

A sintaxe é bem similar a tradicional:
```cpp
Account *pk = new Account[n]
``` 

- No caso acima, o valor de n pode ser atribuída de uma variável, a qual o usuário selecione o valor da mesma.
- Para esse tipo de `new` não é possível utilizar um construtor que não seja o *default*, visto que não é possível enviar parâmetros para a inicialização.
- Também é possível fazer uma alocação de memória com `new` que seja com um valor fixo de elementos, a diferença é que esse array será alocado na *heap*.

O delete nessa situação é feito: `delete[] pk;`.
### Listas encadeadas

Esse é um exemplo de estrutura dinâmica, na qual permite uma fácil inserção e remoção de elementos. Diferentemente de uma estrutura estática, essa pode sofrer atualizações enquanto o programa está rodando.

> Uma **Estrutura de Dados** define como os dados serão organizados em unidades, armazenados e manipulados.

Na lista encadeada, cada elementos contém um dado armazenado e um ponteiro  apontando para o próximo elemento da lista.

- Isso quebra o principio das listas tradicionais, que precisam que todos os elementos estejam continuamente ligados na memórias.
- Isso garante um melhor gerenciamento de memória, visto que novas memórias só são ocupadas se houver novos elementos a serem adicionados na lista.
- Infelizmente, perde-se a propriedade de acessar diferentes elementos do array de forma direta, porém adquiri-se ganhos na remoção e inserção de elementos.

---
## Capítulo 22: Membros Dinâmicos

 O potencial da memória dinâmica de alocação pode ser utilizado para construir atributos de classes com tamanhos variáveis.

Para isso a classe armazena o ponteiro padrão da região da memória na qual o objeto é instanciado, e além disso costuma ter variáveis auxiliares, como:
- `max` para definir a capacidade total do array.
- `cnt` para o número de elementos atuais.

> Os construtores e destrutores devem seguir a mesma ideia do capítulo anterior.
#### Inicialização por cópia

Esse tipo de inicialização pode não ser seguro nesse contexto, visto que se você copiar apenas o ponteiro, dois objetos apontarão para o mesmo endereço.

O ideal para esse caso é:
- Criar um construtor de cópia profunda, alocando um novo espaço na memória e copiando os valores um a um.
- Fazer uma sobrecarga do operador de atribuição, onde similar ao construtor de cópia profunda, nesse caso primeiro o elemento precisa liberar a memória do antigo objeto para fazer a nova alocação. (Impossibilita autoatribuição)

 É possível também sobrecarregar o operador `[]` para permitir acessar elementos de forma mais dinâmica visualmente, pelo índice de com verificação de limites.

Construção de métodos que permitam a construção ou adição de elementos dinamicamente nessa brincadeira.

---
## Capítulo 30: Mais sobre ponteiros

### Ponteiros para Ponteiros

Ponteiros de variáveis são objetos que possuem um endereço salvo na memória, dessa forma é possível construir ponteiros que apontam para outros ponteiros:

- Importante se um array de ponteiros precisa ser alocado dinamicamente.
- Uma função espera um array de ponteiros como argumento.
#### Array dinâmicos de ponteiros

Permite criar uma lista onde cada elemento é um ponteiro para outro objeto.
#### Argumentos de Funções

Importante quando a função vai receber ou manipular algum array de funções.
#### Vantagem em ordenação

Ordenar um array de ponteiros no ligar do geral, traz ganhos de performance por não precisar moves objetos pesados da memória, apenas seu  endereço.
### Funções com Número Variável de Argumentos

Ponteiros de  Permite a definição de funções que aceitam uma quantidade opcional de parâmetros.
### Ponteiros para funções

O nome de uma função em C++, serve como um ponteiro constante para o seu código da máquina.

A sintaxe se torna um pouco mais complexa:
```cpp
tipo (*nome_do_ponteiro)(parâmetros)
```

> Lembrando que é sempre importante utilizar o destrutor para liberar manualmente a memória alocada, evitando vazamentos.