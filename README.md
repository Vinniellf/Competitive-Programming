# Competitive-Programming

Repositorio personal de programación competitiva. Aquí guardo las soluciones a problemas que resuelvo en distintos jueces online, los contests en los que participo, plantillas de código y apuntes de C++.

## Estructura

| Carpeta | Contenido |
|---|---|
| `codeforces/` | Problemas de rondas de Codeforces (Round 978, 983, 986, 987, 990, etc.) y de contests espejo (ICPC-NERC, Regional 2024, UNSA). |
| `CSES/` | Problemas del CSES Problem Set, ordenados por tema: `DP`, `Grafos`, `Mathematics` y `Strings`. |
| `AtCoder-dp/` | Soluciones al AtCoder Educational DP Contest (problemas `a` a `l`). |
| `TEMAS/` | Problemas y plantillas agrupados por tema: `DataStructure` (BIT, Segment Tree), `NumberTheory`, `Strings` (Hashing, Trie), `Trees` y `Miscelánea`. |
| `Contests/` | Contests sueltos: IEEEXTREME 17.0 y 18.0, y un contest de LCA. |
| `Training ICPC 2024/` | Entrenamientos para el ICPC 2024 (Brazil Subregional, RPC, contests internos). |
| `TCs/` | Training camps: `TC-UPC-2025` y `tc-utec`. |
| `PUCP/` | Contests de la PUCP. |
| `Plantillas/` | Plantillas base: `template_cf.cpp` y `template_number_theory.cpp`. |
| `Extra/` | Problemas varios que estoy resolviendo o probando. |
| `books/` | Libros de referencia en PDF (CPH, PAPS, Dynamic Programming). |
| `Anotaciones.md` | Apuntes de atajos y bugs comunes de C++ para competitiva. |
| `Libro de problemas.xlsx` | Registro de problemas resueltos. |

## Lenguaje y herramientas

Todo está escrito en **C++** (`bits/stdc++.h`, estilo competitivo). Las plantillas usan macros comunes (`fastio`, `rep`, `all`, `pb`) y leen de `input.txt` / escriben en `output.txt` cuando no se está en un juez online, gracias a la guarda `#ifndef ONLINE_JUDGE`.

Para compilar y correr un problema:

```bash
g++ -std=c++17 -O2 -o p problema.cpp
./p < input.txt
```

El repo incluye configuración de VS Code y archivos de la extensión Competitive Programming Helper (`.cph/`).

## Jueces y plataformas

- [Codeforces](https://codeforces.com/)
- [CSES Problem Set](https://cses.fi/problemset/)
- [AtCoder](https://atcoder.jp/)
- IEEEXTREME, ICPC y contests universitarios (UPC, UTEC, PUCP, UNSA)
