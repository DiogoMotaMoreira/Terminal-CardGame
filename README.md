# 🂡 Analisador de Cartas de Baralho (C com Unicode)

Este é um pequeno projeto em linguagem C que lê cartas de baralho em formato **Unicode** (🂡, 🂢, 🂣...) e identifica padrões como **conjuntos**, **sequências** e **duplas sequências**.

---

## ✨ Funcionalidades

✅ Identifica **conjuntos** de cartas com o mesmo valor  
✅ Detecta **sequências** de valores consecutivos  
✅ Determina a **carta mais alta** com desempate por naipe  
✅ Manipula e compara cartas em Unicode (U+1F0A1 a U+1F0DE)

---

## 📥 Exemplo de Entrada

```txt
🂡🂱🃁🃑
```

> Cartas: AS de ESPADAS, AS de COPAS, AS de OUROS, AS de PAUS

---

## 📤 Exemplo de Saída

```txt
conjunto com 4 cartas onde a carta mais alta é 🃑
```

---

## ⚙️ Como Compilar

1. Certifica-te de que tens um compilador C (ex: `gcc`)
2. Compila com:

```bash
gcc -o cartas cartas.c -lm
```

3. Corre o programa:

```bash
./cartas
```

> **Atenção**: Deves ter suporte a Unicode no terminal. Usa `setlocale(LC_CTYPE, "C.UTF-8")`.

---

## 🧠 Organização do Código

| Função       | Descrição |
|--------------|-----------|
| `main()`     | Gere input/output e organiza as cartas |
| `f1()`       | Verifica se todas as cartas têm o mesmo valor (conjunto) |
| `f2()`       | Verifica se existe uma sequência crescente de valores |
| `valor()`    | Extrai o valor da carta (AS, DOIS, ..., REI) |
| `naipe()`    | Determina o naipe da carta (ESPADAS, COPAS, OUROS, PAUS) |
| `cartaMAlta()` | Determina a carta mais alta, considerando empate por naipe |
| `resultado()` | Avalia e imprime o tipo de jogada encontrada |
| `remove_newline()` | Limpa quebras de linha do input |

---

## 📚 Tabela de Códigos Unicode das Cartas

| Naipe     | Intervalo Unicode  |
|-----------|--------------------|
| ESPADAS   | U+1F0A1 → U+1F0AE |
| COPAS     | U+1F0B1 → U+1F0BE |
| OUROS     | U+1F0C1 → U+1F0CE |
| PAUS      | U+1F0D1 → U+1F0DE |

---

## 🎯 Melhorias Futuras

- Otimizar a função `f2()` para melhor legibilidade
- Modularizar o código (separar lógica em múltiplos ficheiros)
- Adicionar suporte a combinações mais complexas (ex: flush, full house)
- Testes automáticos com ficheiros de input

---

## 📸 Exemplo Visual (captura do terminal)

```txt
Input:
🂣🂤🂥🂦

Output:
sequência com 4 cartas onde a carta mais alta é 🂦
```

---

## 👨‍💻 Autor

Desenvolvido por Diogo Moreira, Daniel Gonçalves, Nuno Mendes, Rafael Silva.

💡 Projeto académico de LI2 com foco na manipulação de strings Unicode e lógica de jogo.

---

## 🤝 Contribuições

Sinta-te à vontade para abrir um _issue_ ou enviar um _pull request_.  
Qualquer sugestão ou melhoria é bem-vinda! 🙌

---

> 🎴 "A carta mais forte é aquela que joga no tempo certo."  
