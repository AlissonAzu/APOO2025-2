# 📂 Catálogo Pokémon (Pokédex) - Trabalho Grau B

**Equipe**

* Alisson Henrique Maciel Grings

## Descrição do Projeto

Este programa foi desenvolvido como parte da disciplina de **Programação Orientada a Objetos (POO)** com o objetivo de aplicar conceitos avanços de C++ e POO, como Herança (Simples e Multinível), Polimorfismo, Classes Abstratas e Persistência de Dados.

O projeto simula um sistema de catálogo Pokédex em console, que armazena objetos Pokémon de diferentes tipos elementais. O sistema gerencia a criação, exibição e salvamento desses objetos, demonstrando o uso correto de alocação dinâmica e design de classes.

Os dados da aplicação (Pokémons) são salvos em arquivos de texto no formato **.csv** para garantir a persistência das informações entre as sessões de uso.

## Estrutura do Projeto

O projeto está estruturado de forma modular, utilizando os princípios da Programação Orientada a Objetos e seguindo o padrão de arquivos de cabeçalho e implementação.

| Arquivo                      | Descrição |
| :---                         | :--- |
| **main.cpp**                 | Ponto de entrada do programa. |
| **Pokedex.h / .cpp**         | Classe orquestradora. Gerencia o vetor de objetos `Pokemon*` (polimorfismo e alocação dinâmica) e controla a persistência de dados. |
| **Pokemon.h / .cpp**         | **Classe Abstrata Base**. Define a interface básica (ex: `atacar()`, `exibirStatus()`) usando métodos virtuais puros. |
| **PokemonFogo.h / .cpp**     | Representa a Herança Simples de `Pokemon`. Contém um exemplo de **Sobrecarga** de Construtores. |
| **PokemonAgua.h / .cpp**     | Representa a Herança Simples de `Pokemon`. |
| **PokemonEletrico.h / .cpp** | Representa a Herança Simples de `Pokemon`. |
| **PokemonPedra.h / .cpp**    | Representa a Herança Simples de `Pokemon`. |
| **Squirtle.h / .cpp**        | Implementa a **Herança Multinível** (Pokemon -> PokemonAgua -> Squirtle). |
| **\*.csv**                   | Arquivo `pokedex_data.csv` utilizado para carregar e salvar o estado do catálogo de forma persistente. |

---

## ℹ️ Informações Técnicas

| Item | Detalhe |
| :--- | :--- |
| **Linguagem** | C++ (C++11 ou superior) |
| **Interface** | Aplicação de Console (sem interface gráfica) |
| **Dependências** | Nenhuma dependência externa, apenas a Biblioteca Padrão do C++ (iostream, fstream, vector, string, sstream). |
| **IDE/Compilador** | Visual Studio Code / g++ (parte do MinGW no Windows). |
| **Requisitos POO** | Classe Abstrata, Herança Simples/Multinível, Polimorfismo, Sobrecarga e Alocação Dinâmica (`new`/`delete`). |

---

## 🚀 Como Compilar e Executar

### Pré-requisitos

É necessário ter um compilador C++ instalado e configurado em seu sistema, como o **g++** (parte do MinGW no Windows ou do build-essentials no Linux).

### Compilação

Navegue até a pasta raiz do projeto pelo terminal e execute o seguinte comando, que compila todos os 10 arquivos `.cpp`:

```bash
g++ -g main.cpp Pokemon.cpp PokemonFogo.cpp PokemonAgua.cpp Squirtle.cpp PokemonEletrico.cpp PokemonPedra.cpp Pokedex.cpp -o pokedex_sistema
