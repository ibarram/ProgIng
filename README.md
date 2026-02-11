[![version](https://img.shields.io/badge/version-1.0.0-blue)](https://github.com/ibarram/ProgIng/)
[![GitHub commit activity (branch)](https://img.shields.io/github/commit-activity/w/ibarram/ProgIng)](https://github.com/ibarram/ProgIng/)
[![GitHub discussions](https://img.shields.io/github/discussions/ibarram/ProgIng)](https://github.com/ibarram/ProgIng/discussions)
[![GitHub issues](https://img.shields.io/github/issues/ibarram/ProgIng)](https://github.com/ibarram/ProgIng/issues)
![Gitter](https://img.shields.io/gitter/room/ibarram/ProgIng)
[![Programming Languages: C](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white)](#)
![GitHub License](https://img.shields.io/github/license/ibarram/ProgIng)

<br />
<div align="center">
  <a href="https://github.com/ibarram/ProgIng">
    <img src="/doc/img/GitHubPI.png" alt="Logo" width="520" height="217">
  </a>

  <h3 align="center">Programación en Ingeniería (IILI06104)</h3>

  <p align="center">
    Licenciatura en Ingeniería en Comunicaciones y Electrónica (IS75LI0303) <br />
    Licenciatura en Ingeniería en Mecatrónica (IS75LI0403) <br />
    Licenciatura en Ingeniería Sistemas Computacionales (IS75LI0502) <br />
    Licenciatura en Ingeniería de Datos e Inteligencia Artificial (IS75LI0801) <br />
    <a href="https://github.com/ibarram/ProgIng"><strong>Explorar la documentación »</strong></a>
    <br />
    <br />
    <a href="https://github.com/ibarram/ProgIng">Ver Demo</a>
    ·
    <a href="https://github.com/ibarram/ProgIng/issues">Reportar Bug</a>
    ·
    <a href="https://github.com/ibarram/ProgIng/issues">Requiere Modificaciones</a>
  </p>
</div>

<details><summary>Tabla de contenidos</summary><p>

- [Introducción](#introducción)
- [Datos generales](#datos-generales)
- [Competencia de la UDA](#competencia-de-la-uda)
- [Contenido](#contenido)
- [Entregas y evaluación](#entregas-y-evaluación)
  - [Tareas](#tareas)
  - [Prácticas](#prácticas)
  - [Proyecto final](#proyecto-final)
  - [Elementos mínimos de los reportes](#elementos-mínimos-de-los-reportes)
- [Repositorio y plataformas](#repositorio-y-plataformas)
- [Documentación del código (Doxygen)](#documentación-del-código-doxygen)
- [Estructura sugerida del repositorio](#estructura-sugerida-del-repositorio)
- [Código de ética y conducta profesional](#código-de-ética-y-conducta-profesional)
- [Bibliografía](#bibliografía)
- [Contacto](#contacto)
- [Licencia](#licencia)

</p></details>

## Introducción

Esta Unidad de Aprendizaje (UDA) desarrolla bases sólidas de programación **en C** para resolver problemas de ingeniería con énfasis en:
- Estructuras de datos y algoritmos,
- Memoria dinámica y punteros,
- Manejo eficiente de archivos (texto y binarios),
- Buenas prácticas de programación estructurada,
- Trabajo profesional y ético.

> Nota: Este repositorio concentra materiales, código, guías y entregables de la UDA.

## Datos generales

- **UDA:** Programación en Ingeniería  
- **Clave:** IILI06104  
- **Periodo:** Enero 2026  
- **Días:** Lunes y Jueves  
- **Horario:** 12:00–14:00  
- **Aula:** B101  
- **Créditos:** 6 (150 horas totales: 72 con profesor/a + 78 autónomas)  
- **Prerrequisito normativo:** Ninguno  
- **Prerrequisito recomendable:** Fundamentos de los Sistemas de Información (IILI06061)

## Competencia de la UDA

**Diseña e implementa programas computacionales en C para abordar problemas complejos en ingeniería de datos e inteligencia artificial**, empleando estructuras de datos avanzadas, manipulación de memoria dinámica y manejo eficiente de archivos, con apego a buenas prácticas, ética profesional y metodologías de programación estructurada.

## Contenido

El contenido se organiza en los siguientes ejes:

1. [**Estructura de un programa en C**](https://sway.cloud.microsoft/2VEazTGqwCbPcq1J?ref=Link)
2. [**Variables**](https://sway.cloud.microsoft/LHm4HXq9x0DBVwnx?ref=Link)
   - Reglas para identificadores
   - Tipos de datos
   - Alcance
3. [**Operadores básicos**](https://sway.cloud.microsoft/cKmXp7sYqY0flW6F?ref=Link)
   - Aritméticos, comparación, lógicos, binarios
   - [Ejemplos](doc/slide/03_Ejemplos_OperadoresBasicos.pdf)
4. [**Sentencias de control**](doc/slide/04_SentenciasdeControl.pdf)
   - Decisiones (if/switch), ciclos (for/while/do-while), anidamientos
5. [**Arreglos**](doc/slide/05_Arreglos.pdf)
   - 1D (inicialización, longitud, búsqueda, ordenamiento: fuerza bruta, inserción, conteo)
   - Cadenas (longitud, carácter nulo, copiado, concatenado, búsqueda, conversión)
   - 2D y multidimensionales
6. [**Manipulación de bits**](doc/slide/06_ManipulacionBits.pdf)
7. [**Funciones**](doc/slide/07_Funciones.pdf)
   - Prototipos, paso por valor/referencia, `main(argc, argv)`, recursividad
8. **Estructuras y uniones**
9. **Punteros**
   - Aritmética, punteros a arreglos/cadenas/estructuras/funciones
   - Memoria dinámica
   - Punteros a punteros
   - Listas enlazadas (simples y dobles), árboles binarios
10. **Manejo de archivos**
    - Conceptos, flujo, posicionamiento
    - Texto y binarios (lectura/escritura/búsqueda/actualización/temporales)
11. **Directivas de preprocesamiento**
    - Macros, depuración
12. **Tópicos avanzados**
    - Unicode, números complejos, hilos (threads)

## Entregas y evaluación

### Ponderaciones

|Elemento|Porcentaje|
|---|---:|
|Tareas|8%|
|Exámenes rápidos|8%|
|Primera evaluación (1–4)|8%|
|Primera práctica|10%|
|Segunda evaluación (5–9)|8%|
|Segunda práctica|10%|
|Tercera evaluación (10–13)|8%|
|Tercera práctica|10%|
|Código del proyecto final|10%|
|Presentación del proyecto final|10%|
|Reporte del proyecto final|10%|
|**Total**|**100%**|

### Tareas

- **Plataformas:** Microsoft Teams y CSAcademy  
- **Entrega por correo:** `mibarram@gmail.com`  
- **Asunto:** `PI 2026 1 T## NUA Apellidos`  
- **Formato:** reporte **PDF** con diagramas de flujo y simulaciones (cuando aplique)  
- **Restricción:** **no** entregar ejecutables; **solo** código fuente y reporte  
- **Fecha de entrega:** 1 semana (a partir de la asignación)

### Prácticas

- **Plataforma:** Microsoft Teams  
- **Entrega por correo:** `mibarram@gmail.com`  
- **Asunto:** `PI 2026 1 P# NUA Apellidos`  
- **Modalidad:** equipo (máximo 3 integrantes)  
- **Formato:** reporte **PDF** con diagramas de flujo, simulaciones, **tablas de resultados**  
- **Restricción:** **no** ejecutables; **solo** código fuente y reporte  
- **Fecha de entrega:** acordada en clase

### Proyecto final

- **Plataforma:** Microsoft Teams  
- **Entrega por correo:** `mibarram@gmail.com`  
- **Asunto:** `PI 2026 1 Py ## NUA Apellidos`  
- **Modalidad:** equipo (máximo 3 integrantes)  
- **Entregables:**  
  - reporte **PDF** (diagramas de flujo, simulaciones, tablas y análisis),  
  - **código fuente**,  
  - **presentación**,  
  - sesión de **preguntas y respuestas**.

### Elementos mínimos de los reportes

1. **Introducción**  
2. **Objetivos**  
3. **Procedimiento (Algoritmo + Estructura de datos)**  
4. **Diagrama de flujo**  
5. **Resultados y análisis**  
6. **Tablas comparativas** (si aplica)  
7. **Conclusiones**  
8. **Bibliografía**

## Repositorio y plataformas

- **Repositorio oficial (GitHub):** https://github.com/ibarram/ProgIng/  
- **Microsoft Teams (código de equipo):** `co3pdww`  
- **Repositorio/Materiales (Dropbox):** disponible en el grupo (liga compartida)  
- **Comunidad (Facebook):** grupo de apoyo (liga compartida en Teams)

Plataformas recomendadas para práctica y competencia:
- Repl.it, HackerRank, CSAcademy, OmegaUp, Project Euler, Codeforces, Codingame

Software sugerido:
- Dev-C++, MinGW, Code::Blocks, Visual Studio Community, Visual Studio Code, Eclipse, GNU Emacs, NetBeans

## Documentación del código (Doxygen)

Este repositorio incluye ejemplos en C documentados ([HTML](https://ibarram.github.io/docs_ProgIng/index.html) y [PDF](doc/pdf/refman.pdf)) con comentarios estilo **Doxygen**.
La documentación se genera en:

- `doc/doxygen/html/index.html`
- `doc/doxygen/latex/refman.pdf`

### Requisitos

- **Doxygen**
- **Graphviz** (opcional, pero recomendado para `CALL_GRAPH` / `CALLER_GRAPH`)

Instalación típica:

- **openSUSE**: `sudo zypper install doxygen graphviz texlive-scheme-medium latexmk`
- **Ubuntu/Debian**: `sudo apt-get update && sudo apt-get install doxygen graphviz texlive-scheme-medium latexmk`
- **macOS (Homebrew)**: `brew install doxygen graphviz MacTeX`

### Generar documentación

```bash
make docs
```

```bash
make docs-pdf
```

## Estructura sugerida del repositorio

```
.
├─ doc/
│  ├─ pdf/                 # Temario, consideraciones, guías
│  ├─ slide/               # Presentaciones (PDF)
│  ├─ img/                 # Imágenes (escudo, figuras)
│  └─ markdown/            # Notas y guías (Markdown)
├─ src/
│  ├─ 20251/               # Ejemplos desarrollados en la UDA para el periodo E-J 2025
│  ├─ 20251/               # Ejemplos desarrollados en la UDA para el periodo A-D 2025
│  ├─ 20251/               # Ejemplos desarrollados en la UDA para el periodo E-J 2026
│  ├─ tools/               # Scripts de apoyo (opcional)
│  └─ templates/           # Plantillas de reporte y estilos
├─ data/                   # Archivos de entrada/salida
└─ LICENSE
```

## Código de ética y conducta profesional

- El código debe ser **original** y debidamente **referenciado**.
- Se penaliza el **plagio** (copiar-pegar sin atribución) y la **suplantación**.
- Se fomenta la colaboración en equipo **cuando esté permitida**, respetando las reglas de autoría.
- El uso de herramientas de apoyo (incluida IA) debe reflejarse con transparencia en el **reporte** (qué se usó y cómo).

## Bibliografía

- Gazi, O. (2024). *Modern C Programming* (1st Ed.). Springer Cham.
- Horton, I. (2013). *Beginning C* (5th Ed.). Apress.
- Chavan, S. (2017). *C Recipes* (1st Ed.). Apress.
- Toppo, N. & Dewan, H. (2013). *Pointers in C* (1st Ed.). Apress.
- Goyal, A. (2013). *Moving from C to C++* (1st Ed.). Apress.
- Kalicharan, N. (2017). *Advanced Topics in C* (1st Ed.). Apress.
- Erickson, J. (2019). *Algorithms* (1st Ed.). University of Illinois.

## Contacto

[Dr. M.-A. Ibarra-Manzano](mailto:ibarram@ugto.mx?subject=[GitHub]%20ReconocimientoPatrones) - [DICIS-UG](http://www.posgrados.ugto.mx/Profesores/Perfil.aspx?id=20150) - [ORCID: 0000-0003-4317-0248](https://orcid.org/0000-0003-4317-0248) - [SCOPUS: 15837259000](https://www.scopus.com/authid/detail.uri?authorId=15837259000)

Unidad de Aprendizaje Link: [Programación en Ingeniería](https://github.com/ibarram/ProgIng/)

## Licencia

Este repositorio se distribuye bajo **GPL-3.0**. Consulta el archivo `LICENSE`.
