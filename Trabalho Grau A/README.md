# Nome do Projeto

## Equipe
- Alisson Henrique Maciel Grings  

---

## Descrição do Projeto

Este programa foi desenvolvido como parte da disciplina de Programação Orientada a Objetos com o objetivo de aplicar conceitos de C++, POO e persistência de dados na criação de uma aplicação interativa de console.

O projeto simula um aplicativo de álbum de figurinhas, permitindo o cadastro de múltiplos usuários, obtenção de figurinhas através de pacotes, gerenciamento de coleções e um sistema completo de trocas entre usuários. Os dados da aplicação (usuários, álbuns, trocas) são salvos em arquivos de texto no formato .csv para garantir a persistência das informações entre as sessões de uso.

---

## Estrutura do Projeto

O projeto foi estruturado de forma modular, utilizando os princípios da Programação Orientada a Objetos. Abaixo estão os principais arquivos de código:

| Arquivo               | Descrição                                                                                                        |
|-----------------------|------------------------------------------------------------------------------------------------------------------|
| `main.cpp`            | Ponto de entrada do programa. Responsável por exibir os menus e gerenciar o loop principal da aplicação.         |
| `Sistema.h / .cpp`    | Classe orquestradora. Gerencia todos os dados (usuários, figurinhas, trocas), controla o login e a persistência. |
| `Usuario.h / .cpp`    | Representa um usuário do sistema, contendo seu nome, senha e o seu objeto Album.                                 |
| `Album.h / .cpp`      | Representa a coleção de um usuário, gerenciando o vetor de Figurinhas que ele possui.                            |
| `Figurinha.h / .cpp`  | Representa uma única figurinha, com seus atributos como número, nome, e status (na coleção, colada, etc).        |
| `Troca.h / .cpp`      | Representa uma proposta de troca, contendo o proponente, o receptor e as figurinhas envolvidas.                  |
| `Pagina.h / .cpp`     | Estrutura auxiliar para definir o layout e a organização das páginas do álbum.                                   |
| `*.csv`               | Arquivos de texto utilizados para carregar e salvar os dados da aplicação de forma persistente.                  |

---

## Informações Técnicas

- **Linguagem:** C++ (C++11 ou superior) 
- **Interfaçe** Aplicação de Console (sem interface gráfica)  
- **Dependências:** Nenhuma dependência externa, apenas a Biblioteca Padrão do C++.  
- **IDE/Compilador:** Visual Studio Code / g++ (MinGW no Windows, ou equivalentes).  
- **Plataforma-alvo:** Windows / Linux / MacOS  

---

## Checklist de Requisitos

- [x] Cadastro e Login de Usuários.  
- [x] Persistência de dados em arquivos .csv (usuários, álbuns e trocas).  
- [X] Obtenção de novas figurinhas (funcionalidade "Abrir Pacote").
- [X] Visualização do Álbum (distinção entre figurinhas coladas, não coladas e faltantes).
- [X] Gerenciamento da Coleção (Colar figurinha, Disponibilizar para troca).
- [X] Sistema de Trocas entre Usuários (Propor, Revisar, Aceitar e Recusar trocas).
- [X] Estrutura Orientada a Objetos com múltiplas classes.
- [X] Código organizado em arquivos de cabeçalho (.h) e implementação (.cpp).
- [X] Tratamento de entradas inválidas do usuário para evitar crashes.

---

## Como Compilar e Executar

### Pré-requisitos
É necessário ter um compilador C++ instalado e configurado no seu sistema, como o g++ (parte do MinGW no Windows ou do build-essentials no Linux).
### Compilação
Navegue até a pasta raiz do projeto pelo terminal e execute o seguinte comando:
`g++ main.cpp Sistema.cpp Usuario.cpp Album.cpp Figurinha.cpp Troca.cpp -o programa`
### Execução
Após a compilação, um arquivo executável chamado programa (ou programa.exe) será criado. Para rodar a aplicação, execute:
`./programa`
