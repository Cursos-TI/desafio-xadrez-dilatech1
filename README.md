# ♟️ MateCheck - Desafio de Xadrez em C

Bem-vindo ao **MateCheck**, um projeto desenvolvido para praticar **estruturas de repetição**, **funções recursivas** e **organização de código** em linguagem C, simulando a movimentação de peças de xadrez em um tabuleiro.

---

## 🎯 Objetivo do Projeto

O projeto faz parte do desafio proposto pela equipe **MateCheck**, que tem como meta explorar os limites de utilização do código dentro de um jogo de xadrez.  
O foco é a criação de **movimentos automatizados das peças** (Bispo, Torre, Rainha e Cavalo) utilizando diferentes técnicas de programação.

---

## 🧩 Níveis do Desafio

### 🏅 Nível Novato
- Movimentar as peças básicas utilizando **loops simples** (`for`, `while`, `do-while`).
- **Peças e movimentos:**
  - **Bispo:** 5 casas na diagonal superior direita  
  - **Torre:** 5 casas para a direita  
  - **Rainha:** 8 casas para a esquerda  
- O programa exibe o **tabuleiro** a cada movimento.

### 🏅 Nível Aventureiro
- Introduz o **Cavalo**, que se movimenta em **L**.  
- O movimento deve utilizar **loops aninhados** com pelo menos um `for` e outro tipo de laço (`while` ou `do-while`).

### 🥇 Nível Mestre
- Substitui os loops simples por **funções recursivas**.
- O **Cavalo** é aprimorado com **condições múltiplas**, `break` e `continue`.
- Mantém o uso de **loops aninhados** na movimentação do Bispo.

---

## 🧠 Conceitos Praticados

- Estruturas de repetição (`for`, `while`, `do-while`)
- Loops aninhados
- Funções recursivas
- Estruturação modular do código
- Uso de constantes (`#define`)
- Exibição de tabuleiro em terminal
- Lógica condicional com `if`, `break` e `continue`

---

## ⚙️ Execução

### 1️⃣ Criar o arquivo
Abra o PowerShell e execute:
```powershell
cd C:\Users\dilaf\Documents
New-Item -Path "xadrez_mateCheck.c" -ItemType File
