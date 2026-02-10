# ============================================================
# ProgIng - Makefile
# - Compila ejemplos Ejemplo001..Ejemplo016
# - Genera documentación con Doxygen (make docs)
# ============================================================

SHELL := /bin/sh

# -------- Compilación --------
CC      ?= gcc
CFLAGS  ?= -std=c11 -O2 -Wall -Wextra -pedantic
LDFLAGS ?=

EXE := Ejemplo001 Ejemplo002 Ejemplo003 Ejemplo004 Ejemplo005 Ejemplo006 \
       Ejemplo007 Ejemplo008 Ejemplo009 Ejemplo010 Ejemplo011 Ejemplo012 \
       Ejemplo013 Ejemplo014 Ejemplo015 Ejemplo016

# Ejemplo005 usa sqrt()/math -> -lm
LDLIBS_Ejemplo005 := -lm

# -------- Doxygen --------
DOXYGEN  ?= doxygen

# Detecta la raíz del repo (sirve aunque ejecutes make desde src/...):
REPO_ROOT := $(shell git rev-parse --show-toplevel 2>/dev/null || pwd)

DOXYFILE  := $(REPO_ROOT)/Doxyfile
DOXY_OUT  := $(REPO_ROOT)/doc/doxygen
DOXY_HTML := $(DOXY_OUT)/html/index.html

.PHONY: all clean help docs docs-clean docs-open docs-serve doxyfile

all: $(EXE)

help:
	@echo "Targets disponibles:"
	@echo "  make all        Compila todos los ejemplos ($(words $(EXE)))"
	@echo "  make clean      Elimina ejecutables"
	@echo "  make docs       Genera documentación Doxygen en $(DOXY_OUT)/html/"
	@echo "  make docs-open  Abre el index.html (si hay xdg-open/open)"
	@echo "  make docs-serve Sirve la documentación en http://localhost:8000/"
	@echo "  make docs-clean Elimina la carpeta $(DOXY_OUT)"
	@echo "  make doxyfile   Crea $(DOXYFILE) si no existe"

# Regla genérica: compila EjemploXXX a partir de EjemploXXX.c (en el mismo directorio)
%: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS_$@)

clean:
	rm -f $(EXE)

# ---------------------------
# Doxygen targets
# ---------------------------

# Crea un Doxyfile mínimo en la raíz del repo (si no existe).
doxyfile:
	@if [ -f "$(DOXYFILE)" ]; then \
		echo "Doxyfile ya existe: $(DOXYFILE) (no se sobrescribe)."; \
	else \
		echo "Generando Doxyfile en: $(DOXYFILE)"; \
		cd "$(REPO_ROOT)" && cat > "Doxyfile" <<'EOF' ;\
# ---------- Doxygen configuration (generado por Makefile) ----------
PROJECT_NAME           = "ProgIng - Programación en Ingeniería"
PROJECT_BRIEF          = "Ejemplos en C para la UDA Programación en Ingeniería (IILI06104)"

# Salida (queda en el árbol doc/ del repo)
OUTPUT_DIRECTORY       = doc/doxygen

# Entradas del proyecto (desde la raíz del repo)
INPUT                  = src README.md doc
FILE_PATTERNS          = *.c *.h *.md
RECURSIVE              = YES

# Evita documentar la salida generada
EXCLUDE                = doc/doxygen

# Extracción y estilo
EXTRACT_ALL            = YES
EXTRACT_STATIC         = YES
OPTIMIZE_OUTPUT_FOR_C  = YES
MARKDOWN_SUPPORT       = YES
USE_MDFILE_AS_MAINPAGE = README.md
GENERATE_TREEVIEW      = YES

# Navegación / código fuente
SOURCE_BROWSER         = YES
INLINE_SOURCES         = YES
STRIP_FROM_PATH        = .

# Gráficas (requiere Graphviz 'dot')
HAVE_DOT               = YES
CALL_GRAPH             = YES
CALLER_GRAPH           = YES

# Salidas
GENERATE_HTML          = YES
GENERATE_LATEX         = NO

QUIET                  = YES
WARN_IF_UNDOCUMENTED   = YES
EOF \
		; \
		echo "Listo: $(DOXYFILE)"; \
	fi

# Si no existe Doxyfile, make sabe “cómo crearlo” (vía el target doxyfile)
$(DOXYFILE): doxyfile
	@true

docs: $(DOXY_HTML)

# Genera la documentación (ejecuta doxygen desde la raíz del repo)
$(DOXY_HTML): $(DOXYFILE)
	@command -v $(DOXYGEN) >/dev/null 2>&1 || { \
		echo "Error: 'doxygen' no está instalado."; \
		echo "Instala Doxygen (y opcionalmente Graphviz) y reintenta."; \
		exit 1; \
	}
	@cd "$(REPO_ROOT)" && $(DOXYGEN) "Doxyfile"
	@mkdir -p "$(DOXY_OUT)/html"
	@touch "$(DOXY_OUT)/html/.nojekyll"
	@echo "Documentación generada en: $(DOXY_HTML)"

docs-clean:
	rm -rf "$(DOXY_OUT)"

# Abre el index en el navegador (Linux: xdg-open, macOS: open)
docs-open: docs
	@if command -v xdg-open >/dev/null 2>&1; then \
		xdg-open "$(DOXY_HTML)"; \
	elif command -v open >/dev/null 2>&1; then \
		open "$(DOXY_HTML)"; \
	else \
		echo "No se encontró xdg-open/open. Abre manualmente: $(DOXY_HTML)"; \
	fi

# Sirve la documentación localmente (útil porque GitHub no “renderiza” HTML dentro del repo)
docs-serve: docs
	@echo "Sirviendo documentación en http://localhost:8000/ (Ctrl+C para detener)"
	@python3 -m http.server 8000 -d "$(DOXY_OUT)/html"
