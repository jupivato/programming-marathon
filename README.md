# Maratona de Programação — apostila e códigos

Repositório com soluções em C++, templates de algoritmos e uma apostila em LaTeX que **inclui o código direto dos arquivos** — você edita o `.cpp` uma vez e o PDF acompanha.

**GitHub:** [github.com/jupivato/programming-marathon](https://github.com/jupivato/programming-marathon)

---

## Estrutura do projeto

```
maratona/
├── apostila/              # Livro em LaTeX
│   ├── main.tex           # Entrada: capa, sumário, capítulos
│   ├── Makefile           # Gera main.pdf
│   ├── config/            # Preâmbulo, estilo C++, cores
│   └── capitulos/         # Um .tex por capítulo
├── codigos/               # Todo o C++ (fonte da verdade)
│   ├── algoritmos_avulsos/  # Templates por tema (grafos, DP, …)
│   ├── formulas_teoria/     # Trechos usados no cap. teórico
│   ├── mineira_2024/        # Provas / simulados (por pasta)
│   └── …
├── scripts/               # Ferramentas locais (não versionadas)
└── README.md
```

| Pasta | Conteúdo |
|-------|----------|
| `codigos/algoritmos_avulsos/` | ~75 algoritmos organizados: `grafos/`, `dp/`, `strings/`, `geometria/`, `matematica/`, `ordenacao/`, `estruturas/`, `tecnico/` |
| `codigos/formulas_teoria/` | Funções didáticas ligadas às fórmulas do capítulo teórico |
| `codigos/mineira_*`, `regional_*`, `simulado_*` | Soluções de provas e treinos |
| `apostila/capitulos/` | Texto da apostila; use `template-capitulo.tex` como modelo |

---

## Começando

### Clonar

```bash
git clone https://github.com/jupivato/programming-marathon.git
cd programming-marathon
```

### Dependências

**Apostila (PDF):**

- TeX Live (ou MiKTeX) com `pdflatex`, pacotes comuns: `listings`, `tcolorbox`, `hyperref`, `fancyhdr`, `amsmath`, …
- No Ubuntu/Debian, em geral: `sudo apt install texlive-latex-extra texlive-fonts-recommended`

**Códigos C++:**

- Compilador C++17 (`g++` ou `clang++`). Os arquivos usam estilo competitivo (`bits/stdc++.h` onde aplicável).

### Gerar o PDF da apostila

```bash
cd apostila
make pdf
```

O arquivo final fica em `apostila/main.pdf`. Artefatos intermediários vão para `apostila/build/` (ignorados pelo git).

**Limpar build:**

```bash
make clean
```

**XeLaTeX** (opcional, melhor para UTF-8 em comentários dos `.cpp`):

```bash
make LATEX=xelatex pdf
```

---

## Como a apostila puxa o código

Os `.cpp` ficam em `codigos/`. Na apostila, use (caminho relativo a `codigos/`):

```latex
\incluircpp{algoritmos_avulsos/grafos/dijkstra.cpp}
```

**Só um trecho do arquivo:**

```latex
\incluircpp[firstline=10,lastline=25]{formulas_teoria/combinatoria.cpp}
```

**Com legenda e referência** `\ref{lst:...}`:

```latex
\incluircppcaption[firstline=1,lastline=40]{algoritmos_avulsos/dp/knapsack_01.cpp}{Mochila 0/1}
```

Definições em `apostila/config/listings-cpp.tex` (cores rosa/cinza, numeração de linhas).

---

## Escrever um capítulo novo

1. Copie o modelo:

   ```bash
   cp apostila/capitulos/template-capitulo.tex apostila/capitulos/meu-tema.tex
   ```

2. Edite o `.tex` (título, seções, `\incluircpp{...}`).

3. Inclua o capítulo em `apostila/main.tex`:

   ```latex
   \input{capitulos/meu-tema}
   ```

4. Recompile: `cd apostila && make pdf`.

### Caixa “Exemplo do dia a dia”

Parágrafos e listas funcionam com **linha em branco** entre blocos:

```latex
\begin{exemplodiabox}
Primeiro parágrafo.

Segundo parágrafo.

\begin{itemize}[nosep]
  \item item um;
  \item item dois.
\end{itemize}
\end{exemplodiabox}
```

Estilo definido em `apostila/config/preamble.tex` (`exemplodiabox`).

---

## Trabalhar com os códigos C++

### Compilar um arquivo solto

```bash
g++ -std=c++17 -O2 -o /tmp/prog codigos/mineira_2024/copos_de_leite.cpp
/tmp/prog
```

### Onde colocar código novo

| Objetivo | Onde salvar |
|----------|-------------|
| Template reutilizável (Dijkstra, KMP, …) | `codigos/algoritmos_avulsos/<tema>/` |
| Fórmula / função do capítulo teórico | `codigos/formulas_teoria/` |
| Solução de prova ou simulado | `codigos/<nome_da_prova>/` |

**Dica:** comentários nos `.cpp` incluídos na apostila — prefira **ASCII** (sem acentos) se usar `pdflatex`; com `xelatex` há mais flexibilidade para UTF-8.

---

## Scripts locais (`scripts/`)

Não vão para o git (ver `.gitignore`). Uso interno, por exemplo:

- `extrair_algoritmos_pdf.py` — extração bruta de códigos a partir de PDFs
- `revisar_algoritmos_avulsos.py` — organiza e limpa `algoritmos_avulsos/`

Requer Python 3. Rode a partir da raiz do repositório se precisar reprocessar material antigo.

---

## O que o git ignora

- `apostila/build/`, `apostila/*.pdf`
- `scripts/`
- `git/` (clone auxiliar, se existir)
- `codigos/algoritmos_avulsos/_originais_flat/` (backup da extração)

Versione sempre as mudanças em `codigos/` e `apostila/*.tex`; o PDF pode ser gerado localmente com `make pdf`.

---

## Fluxo sugerido no dia a dia

1. Resolver ou refatorar um problema → salvar em `codigos/...`.
2. Atualizar (ou criar) o capítulo em `apostila/capitulos/`.
3. `\incluircpp{...}` apontando para o mesmo arquivo.
4. `make pdf` e revisar o PDF.

Assim texto, fórmulas e implementação ficam no mesmo repositório, sem copiar código manualmente para o LaTeX.

---

## Referências úteis

- [CP-Algorithms](https://cp-algorithms.com/)
- [USACO Guide](https://usaco.guide/)

Dúvidas ou sugestões: abra uma issue no GitHub do projeto.
