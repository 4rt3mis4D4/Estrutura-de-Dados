# 🏙️ Sistema de Gerenciamento de Eventos Críticos — Árvore AVL

**👩‍💻 Aluna:** Gabriela Pedroso

Sistema desenvolvido em linguagem C para gerenciamento de eventos críticos em uma cidade inteligente, utilizando uma Árvore Binária de Busca Balanceada (AVL) como estrutura de dados principal.

---

## 📋 Descrição geral

O sistema permite registrar, monitorar e gerenciar ocorrências urbanas em tempo real, como acidentes de trânsito, falhas em semáforos, interrupções de energia, alagamentos e incêndios. Cada evento é armazenado como um nó da árvore AVL, identificado por um ID único e classificado por tipo, nível de severidade, região da cidade e status.

A árvore AVL garante que as operações de busca, inserção e remoção ocorram em tempo O(log n), mantendo o balanceamento automaticamente a cada modificação por meio de rotações simples (LL, RR) e duplas (LR, RL).

### ⚙️ Funcionalidades

- 📝 **Cadastro de eventos** com data e hora automáticas do sistema
- 🔄 **Atualização de status** de Ativo para Resolvido
- 📊 **Atualização de severidade** de eventos ativos
- 🗑️ **Remoção** restrita a eventos com status Resolvido
- 🔍 **Consultas avançadas:**
  - Listagem de eventos ativos por intervalo de severidade
  - Relatório de eventos ativos por região da cidade
  - Listagem por intervalo de ID
- 📈 **Métricas da árvore:**
  - Altura atual
  - Total de nós
  - Total de eventos ativos
  - Fator de balanceamento médio
  - Total de rotações realizadas

### 🗂️ Estrutura de arquivos

```
.
├── estrutura.h          # Definição dos tipos, enums e struct do nó
├── arvore_avl.h         # Declarações das funções da árvore AVL
├── arvore_avl.c         # Implementação da AVL (inserção, remoção, busca, rotações)
├── funcionalidades.h    # Declarações das consultas e operações de atualização
├── funcionalidades.c    # Implementação das consultas e métricas
├── interface.h          # Declaração do menu e conversores enum → string
├── interface.c          # Implementação do menu interativo
└── main.c               # Ponto de entrada do programa
```

### 🚨 Tipos de evento suportados

| Código | Tipo de evento |
|--------|---------------|
| 0 | 🚗 Acidente de Trânsito |
| 1 | 🚦 Falha em Semáforo |
| 2 | ⚡ Interrupção de Energia |
| 3 | 🌊 Alagamento |
| 4 | 🔥 Incêndio |

### 🗺️ Regiões da cidade

| Código | Região |
|--------|--------|
| 0 | 🧭 Norte |
| 1 | 🧭 Sul |
| 2 | 🧭 Leste |
| 3 | 🧭 Oeste |
| 4 | 🏛️ Centro |

---

## 🛠️ Compilação e execução

### ✅ Pré-requisitos

- Compilador GCC (versão 9.2.0 ou superior recomendada)
- Sistema operacional Windows, Linux ou macOS

### 💻 Via terminal (GCC)

Coloque todos os arquivos do projeto no mesmo diretório e execute:

```bash
gcc -o sistema main.c arvore_avl.c funcionalidades.c interface.c
```

Para executar:

```bash
./sistema
```

No Windows:

```bash
sistema.exe
```

### 🖥️ Via Dev-C++ (Embarcadero)

1. Abra o Dev-C++ e vá em **File → New → Project**
2. Selecione **Console Application** e linguagem **C**
3. Dê um nome ao projeto e salve na mesma pasta dos arquivos
4. Remova o `main.c` gerado automaticamente clicando com o botão direito → **Remove File**
5. Vá em **Project → Add to Project** e adicione os quatro arquivos `.c`:
   - `main.c`
   - `arvore_avl.c`
   - `funcionalidades.c`
   - `interface.c`
6. Pressione **F11** para compilar e executar

> ⚠️ Os arquivos `.h` não precisam ser adicionados ao projeto — apenas os `.c`. Todos os arquivos devem estar na mesma pasta.

### 🔵 Via VS Code

Com a extensão **C/C++** instalada, crie um arquivo `tasks.json` em `.vscode/` com o seguinte conteúdo:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "build",
      "type": "shell",
      "command": "gcc",
      "args": [
        "-o", "sistema",
        "main.c", "arvore_avl.c", "funcionalidades.c", "interface.c"
      ],
      "group": { "kind": "build", "isDefault": true }
    }
  ]
}
```

Depois pressione **Ctrl+Shift+B** para compilar.

---

## ▶️ Exemplo de uso

```
=== SISTEMA DE GERENCIAMENTO DE EVENTOS CRITICOS ===
1. [CADASTRO] Registrar Novo Evento
2. [STATUS] Marcar Evento como RESOLVIDO
3. [SEVERIDADE] Atualizar Nivel de Severidade
4. [REMOVER] Excluir Evento (Apenas Resolvidos)
5. [RELATORIOS] Consultas e Listagens
6. [METRICAS] Ver Desempenho da Arvore AVL
0. Sair
```
