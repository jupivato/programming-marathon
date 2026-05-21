# Índice de capítulos — Apostila de Maratona

Mapa do livro: capítulos existentes, códigos vinculados e capítulos planejados.
Atualize este arquivo ao criar um capítulo novo ou ao incluir um `.cpp` na apostila.

**Como usar:** copie `apostila/capitulos/template-capitulo.tex`, renomeie conforme a tabela,
adicione `\input{capitulos/...}` em `apostila/main.tex` e marque o status aqui.

---

## Legenda de status

| Status | Significado |
|--------|-------------|
| ✅ Publicado | Incluído em `main.tex` e compilando |
| 📝 Rascunho | `.tex` existe mas ainda não está no `main.tex` |
| 📋 Planejado | Ainda não escrito |

---

## Parte I — Fundamentos (já na apostila)

| # | Arquivo `.tex` | Título | Status | Códigos (`codigos/`) |
|---|----------------|--------|--------|----------------------|
| 1 | `capitulos/fundamentos-teoricos.tex` | Fundamentos teóricos | ✅ | `formulas_teoria/combinatoria.cpp` |
|   | | | | `formulas_teoria/numeros.cpp` |
|   | | | | `formulas_teoria/somas.cpp` |
|   | | | | `formulas_teoria/geometria.cpp` |
|   | | | | `formulas_teoria/grafos_probabilidade.cpp` |
| 2 | `capitulos/cpp-utilitarios.tex` | C++ utilitários (STL) | ✅ | `cpp_utilitarios/template_tipos.cpp` |
|   | | | | `cpp_utilitarios/entrada_saida.cpp` |
|   | | | | `cpp_utilitarios/vetor_detalhado.cpp` |
|   | | | | `cpp_utilitarios/vetor_deque.cpp` |
|   | | | | `cpp_utilitarios/iteradores.cpp` |
|   | | | | `cpp_utilitarios/ordenacao_detalhada.cpp` |
|   | | | | `cpp_utilitarios/ordenacao_tuple.cpp` |
|   | | | | `cpp_utilitarios/pair_tupla_detalhado.cpp` |
|   | | | | `cpp_utilitarios/pair_tupla_em_estruturas.cpp` |
|   | | | | `cpp_utilitarios/set_map_detalhado.cpp` |
|   | | | | `cpp_utilitarios/filas_detalhado.cpp` |
|   | | | | `cpp_utilitarios/algoritmos_stl.cpp` |
|   | | | | `cpp_utilitarios/comparadores_lambdas.cpp` |
|   | | | | `cpp_utilitarios/strings_bitset.cpp` |

### Parte II — primeiro capítulo de algoritmo

| # | Arquivo `.tex` | Título | Status | Códigos (`codigos/`) |
|---|----------------|--------|--------|----------------------|
| 3 | `capitulos/ordenacao.tex` | Ordenação | ✅ | `algoritmos_avulsos/ordenacao/bubble_sort.cpp` |
|   | | | | `algoritmos_avulsos/ordenacao/selection_sort.cpp` |
|   | | | | `algoritmos_avulsos/ordenacao/insertion_sort.cpp` |
|   | | | | `algoritmos_avulsos/ordenacao/shell_sort.cpp` |
|   | | | | `algoritmos_avulsos/ordenacao/merge_sort.cpp` |
|   | | | | `algoritmos_avulsos/ordenacao/quick_sort.cpp` |
|   | | | | `algoritmos_avulsos/ordenacao/heapsort.cpp` |
|   | | | | `algoritmos_avulsos/ordenacao/counting_sort.cpp` |
| 4 | `capitulos/tecnicas.tex` | Técnicas clássicas | ✅ | `algoritmos_avulsos/tecnico/io_utilidades.cpp` |
|   | | | | `algoritmos_avulsos/tecnico/prefix_sum_1d.cpp` |
|   | | | | `algoritmos_avulsos/tecnico/dois_ponteiros_ordenado.cpp` |
|   | | | | `algoritmos_avulsos/tecnico/janela_soma_max_k.cpp` |
|   | | | | `algoritmos_avulsos/tecnico/janela_maximo_k.cpp` |
|   | | | | `algoritmos_avulsos/tecnico/subarray_soma_minima.cpp` |
|   | | | | `algoritmos_avulsos/tecnico/substring_unica_max.cpp` |
|   | | | | `algoritmos_avulsos/tecnico/submatriz_soma_max_k.cpp` |
|   | | | | `algoritmos_avulsos/tecnico/busca_binaria_resposta.cpp` |

### Reserva C++ (opcional — versões curtas)

Não entram no PDF hoje; o cap. 2 usa as versões `_detalhado`. Podem virar apêndice “cola rápida”.

| Arquivo | Observação |
|---------|------------|
| `cpp_utilitarios/conjuntos_mapas.cpp` | set / map resumido |
| `cpp_utilitarios/filas_pilhas_heap.cpp` | stack, queue, `priority_queue` |
| `cpp_utilitarios/pair_tupla.cpp` | pair / tuple básico |

---

## Parte II — Algoritmos (planejados)

Ordem sugerida de escrita (do mais acessível ao mais avançado).

### 5. Estruturas para consultas em intervalo

| Campo | Valor |
|-------|-------|
| Arquivo | `capitulos/estruturas-consulta.tex` |
| Título | Estruturas: prefixo, BIT e segment tree |
| Status | 📋 |
| Pasta | `codigos/algoritmos_avulsos/estruturas/` |

| Arquivo `.cpp` | Tema |
|---------------|------|
| `prefix_sum_2d.cpp` | Soma de prefixo 2D |
| `fenwick.cpp` | Fenwick tree (BIT) |
| `segment_tree.cpp` | Segment tree |
| `segment_tree_lazy.cpp` | Segment tree com lazy |
| `sliding_window_max.cpp` | Máximo em janela (deque) — ver também `tecnico/janela_maximo_k.cpp` no cap. técnicas |

---

### 6. Grafos I — Busca e ordenação topológica

| Campo | Valor |
|-------|-------|
| Arquivo | `capitulos/grafos-busca.tex` |
| Título | Grafos: BFS, DFS e ordenação topológica |
| Status | 📋 |
| Pasta | `codigos/algoritmos_avulsos/grafos/` |
| Nota | O cap. teórico já aponta templates em `grafos/` |

| Arquivo `.cpp` | Tema |
|---------------|------|
| `bfs.cpp` | Busca em largura |
| `dfs_recursivo_matriz.cpp` | DFS recursivo (matriz de adjacência) |
| `dfs_iterativo_matriz.cpp` | DFS iterativo (matriz) |
| `dfs_toposort.cpp` | Ordenação topológica |

---

### 7. Grafos II — Caminhos mínimos e MST

| Campo | Valor |
|-------|-------|
| Arquivo | `capitulos/grafos-caminhos.tex` |
| Título | Grafos: caminhos mínimos e árvore geradora mínima |
| Status | 📋 |
| Pasta | `codigos/algoritmos_avulsos/grafos/` |

| Arquivo `.cpp` | Tema |
|---------------|------|
| `dijkstra.cpp` | Dijkstra |
| `bellman_ford.cpp` | Bellman-Ford |
| `floyd_warshall.cpp` | Floyd-Warshall |
| `union_find.cpp` | Disjoint Set Union (DSU) |
| `kruskal.cpp` | Kruskal (MST) |
| `prim.cpp` | Prim (MST) |
| `lca.cpp` | Lowest Common Ancestor |

---

### 8. Grafos III — Componentes, pontes, fluxo e 2-SAT

| Campo | Valor |
|-------|-------|
| Arquivo | `capitulos/grafos-avancado.tex` |
| Título | Grafos avançados |
| Status | 📋 |
| Pasta | `codigos/algoritmos_avulsos/grafos/` |

| Arquivo `.cpp` | Tema |
|---------------|------|
| `tarjan.cpp` | Tarjan (SCC / componentes) |
| `kosaraju.cpp` | Kosaraju (SCC) |
| `pontes.cpp` | Pontes e articulações |
| `edmonds_karp.cpp` | Fluxo máximo (Edmonds-Karp) |
| `dinic.cpp` | Fluxo máximo (Dinic) |
| `mincut.cpp` | Corte mínimo |
| `two_sat.cpp` | 2-SAT |

---

### 9. Programação dinâmica

| Campo | Valor |
|-------|-------|
| Arquivo | `capitulos/dp.tex` |
| Título | Programação dinâmica |
| Status | 📋 |
| Pasta | `codigos/algoritmos_avulsos/dp/` |

| Arquivo `.cpp` | Tema |
|---------------|------|
| `knapsack_01.cpp` | Mochila 0/1 |
| `knapsack_ilimitada.cpp` | Mochila ilimitada |
| `coin_change.cpp` | Troco / moedas |
| `grid_paths.cpp` | Caminhos em grade |
| `lis.cpp` | LIS O(n log n) |
| `lis_on_tree.cpp` | LIS em árvore |
| `edit_distance.cpp` | Distância de edição |
| `max_weight_independent_set.cpp` | Conjunto independente (árvore) |
| `digit_dp.cpp` | DP em dígitos |

*Opcional:* dividir em `dp-classica.tex` e `dp-avancada.tex` se o capítulo ficar longo.

---

### 10. Strings

| Campo | Valor |
|-------|-------|
| Arquivo | `capitulos/strings.tex` |
| Título | Algoritmos em strings |
| Status | 📋 |
| Pasta | `codigos/algoritmos_avulsos/strings/` |

| Arquivo `.cpp` | Tema |
|---------------|------|
| `hash.cpp` | Hash de string |
| `kmp_lps.cpp` | KMP — função de prefixo (LPS) |
| `kmp.cpp` | KMP — busca |
| `rabin_karp.cpp` | Rabin-Karp |
| `manacher.cpp` | Manacher (palíndromos) |
| `trie.cpp` | Trie |
| `suffix_automaton.cpp` | Autômato de sufixos |

---

### 11. Geometria computacional

| Campo | Valor |
|-------|-------|
| Arquivo | `capitulos/geometria-computacional.tex` |
| Título | Geometria computacional 2D |
| Status | 📋 |
| Pasta | `codigos/algoritmos_avulsos/geometria/` |

| Arquivo `.cpp` | Tema |
|---------------|------|
| `template_2d.cpp` | Template base (ponto, vetor, ccw) |
| `angulo_vetores.cpp` | Ângulo entre vetores |
| `area_poligono.cpp` | Área (Shoelace) |
| `convex_hull.cpp` | Fecho convexo |
| `closest_pair.cpp` | Par de pontos mais próximo |

---

### 12. Matemática implementada

| Campo | Valor |
|-------|-------|
| Arquivo | `capitulos/matematica.tex` |
| Título | Matemática para maratona |
| Status | 📋 |
| Pasta | `codigos/algoritmos_avulsos/matematica/` |

| Subtema | Arquivos |
|---------|----------|
| Aritmética básica | `gcd.cpp`, `lcm.cpp`, `divisores.cpp`, `fibonacci.cpp`, `fast_pow.cpp` |
| Modular / bases | `inverso_modular.cpp`, `base10_para_b.cpp`, `base_b_para_10.cpp` |
| Primos | `crivo_eratostenes.cpp`, `crivo_segmentado.cpp`, `pollard_rho.cpp` |
| Combinatória | `catalan.cpp`, `catalan_mod.cpp` |
| Álgebra linear | `gauss_eliminacao.cpp`, `gauss_sistemas.cpp`, `cramer.cpp` |
| Avançado | `fft.cpp`, `produto_vetorial.cpp` |

*Opcional:* `matematica-basica.tex` + `matematica-avancada.tex`.

---

## Parte III — Problemas de prova (planejados)

Um capítulo por edição ou por grupo de simulado. Status 📋 para todos.

### Mineira

| Arquivo `.tex` | Título | Códigos |
|----------------|--------|---------|
| `capitulos/prova-mineira-2024.tex` | Mineira 2024 | `mineira_2024/copos_de_leite.cpp`, `mineira_2024/passaporte.cpp` |
| `capitulos/prova-mineira-2025.tex` | Mineira 2025 | `mineira_2025/nome_minimo.cpp` |
| `capitulos/prova-mineira-vii.tex` | Mineira VII | `mineira_vii/aplicando_prova.cpp`, `mineira_vii/golnaldinho.cpp` |

### Regional

| Arquivo `.tex` | Título | Códigos |
|----------------|--------|---------|
| `capitulos/prova-regional-23-24.tex` | Regional 2023–24 | `regional_23_24/a.cpp`, `golnaldinho.cpp`, `i.cpp`, `l.cpp`, `m.cpp` |
| `capitulos/prova-regional-24-25.tex` | Regional 2024–25 | `regional_24_25/a.cpp`, `f.cpp`, `h.cpp` |

### Simulados

| Arquivo `.tex` | Título | Códigos |
|----------------|--------|---------|
| `capitulos/simulado-grupo-1.tex` | Simulado — Grupo 1 | `simulado_grupo_1/abc.cpp`, `alice.cpp`, `Centopeia.cpp`, `Comunidades.cpp`, `Estantes.cpp`, `Substrings.cpp` |
| `capitulos/simulado-grupo-2.tex` | Simulado — Grupo 2 | `simulado_grupo_2/e.cpp` |
| `capitulos/simulado-grupo-3.tex` | Simulado — Grupo 3 | `simulado_grupo_3/bingo.cpp`, `e.cpp`, `gabarito.cpp`, `j.cpp`, `princess.cpp` |

### Avulso

| Arquivo `.tex` | Título | Códigos |
|----------------|--------|---------|
| `capitulos/problema-intersecao.tex` | Interseção (avulso) | `intersecao.cpp` |

---

## Ordem sugerida em `main.tex`

```latex
% --- Parte I (feito) ---
\input{capitulos/fundamentos-teoricos}
\input{capitulos/cpp-utilitarios}
\input{capitulos/ordenacao}
\input{capitulos/tecnicas}

% --- Parte II — algoritmos ---
\input{capitulos/estruturas-consulta}
\input{capitulos/grafos-busca}
\input{capitulos/grafos-caminhos}
\input{capitulos/grafos-avancado}
\input{capitulos/dp}
\input{capitulos/strings}
\input{capitulos/geometria-computacional}
\input{capitulos/matematica}

% --- Parte III — provas (quando quiser) ---
% \input{capitulos/prova-mineira-2024}
% ...
```

---

## Contagem rápida

| Grupo | Arquivos `.cpp` | Na apostila |
|-------|-----------------|-------------|
| `formulas_teoria/` | 5 | 5 |
| `cpp_utilitarios/` (usados no cap. 2) | 14 | 14 |
| `cpp_utilitarios/` (reserva) | 3 | 0 |
| `algoritmos_avulsos/` | 75 | 0 |
| Provas / simulados / avulso | 25 | 0 |
| `algoritmos_avulsos/ordenacao/` | 8 | 8 |
| `algoritmos_avulsos/tecnico/` | 9 | 9 |
| **Total em `codigos/`** | **127** | **36** |

---

## Checklist ao publicar um capítulo novo

1. [ ] Copiar `template-capitulo.tex` → `capitulos/<nome>.tex`
2. [ ] Preencher texto, `\incluircpp{...}` e (se quiser) `\incluircppcaption{...}`
3. [ ] Descomentar `\input{capitulos/<nome>}` em `main.tex`
4. [ ] `cd apostila && make pdf`
5. [ ] Atualizar a coluna **Status** deste índice (📋 → ✅)
6. [ ] Mover os `.cpp` usados da tabela “planejados” para a tabela “publicado” (ou marcar na seção)

---

*Última revisão do inventário: maio/2026 — 4 capítulos publicados (teórico, C++, ordenação, técnicas), 8 capítulos de algoritmo planejados, 8 capítulos de prova planejados.*
