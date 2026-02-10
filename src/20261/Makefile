SHELL := /bin/sh

CC      ?= gcc
CFLAGS  ?= -std=c11 -O2 -Wall -Wextra -pedantic
LDFLAGS ?=

SRC_DIR   ?= src
BUILD_DIR ?= build

SOURCES := $(wildcard $(SRC_DIR)/Ejemplo*.c)
EXE     := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%,$(SOURCES))

DOXYGEN   ?= doxygen
REPO_ROOT := $(shell git rev-parse --show-toplevel 2>/dev/null || pwd)
DOXYFILE  := $(REPO_ROOT)/Doxyfile
DOXY_OUT  := $(REPO_ROOT)/doc/doxygen
DOXY_HTML := $(DOXY_OUT)/html/index.html

.PHONY: all clean help docs docs-open docs-serve docs-clean doxyfile
all: $(EXE)

help:
	@echo "make            Compila $(SRC_DIR)/Ejemplo*.c -> $(BUILD_DIR)/"
	@echo "make clean      Borra $(BUILD_DIR)/"
	@echo "make docs       Genera Doxygen en doc/doxygen/html/"
	@echo "make docs-open  Abre doc/doxygen/html/index.html"
	@echo "make docs-serve Sirve en http://localhost:8000/"
	@echo "make docs-clean Borra doc/doxygen/"

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Regla genérica de compilación
$(BUILD_DIR)/%: $(SRC_DIR)/%.c | $(BUILD_DIR)
	@echo "[CC] $< -> $@"
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS) $(if $(filter Ejemplo005,$*),-lm,)

clean:
	rm -rf $(BUILD_DIR)

# ------------------ Doxygen ------------------

doxyfile:
	@command -v $(DOXYGEN) >/dev/null 2>&1 || { \
		echo "Error: doxygen no está instalado."; \
		exit 1; \
	}
	@if [ -f "$(DOXYFILE)" ]; then \
		echo "Doxyfile ya existe: $(DOXYFILE)"; \
	else \
		echo "Creando Doxyfile en $(DOXYFILE)"; \
		cd "$(REPO_ROOT)" && $(DOXYGEN) -g Doxyfile >/dev/null; \
	fi
	@perl -pi -e 's|^\s*PROJECT_NAME\s*=.*|PROJECT_NAME = "ProgIng - Programación en Ingeniería"|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*OUTPUT_DIRECTORY\s*=.*|OUTPUT_DIRECTORY = doc/doxygen|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*INPUT\s*=.*|INPUT = src README.md doc|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*FILE_PATTERNS\s*=.*|FILE_PATTERNS = *.c *.h *.md|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*RECURSIVE\s*=.*|RECURSIVE = YES|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*EXTRACT_ALL\s*=.*|EXTRACT_ALL = YES|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*OPTIMIZE_OUTPUT_FOR_C\s*=.*|OPTIMIZE_OUTPUT_FOR_C = YES|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*MARKDOWN_SUPPORT\s*=.*|MARKDOWN_SUPPORT = YES|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*USE_MDFILE_AS_MAINPAGE\s*=.*|USE_MDFILE_AS_MAINPAGE = README.md|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*SOURCE_BROWSER\s*=.*|SOURCE_BROWSER = YES|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*INLINE_SOURCES\s*=.*|INLINE_SOURCES = YES|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*HAVE_DOT\s*=.*|HAVE_DOT = YES|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*CALL_GRAPH\s*=.*|CALL_GRAPH = YES|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*CALLER_GRAPH\s*=.*|CALLER_GRAPH = YES|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*GENERATE_HTML\s*=.*|GENERATE_HTML = YES|' "$(DOXYFILE)"
	@perl -pi -e 's|^\s*GENERATE_LATEX\s*=.*|GENERATE_LATEX = NO|' "$(DOXYFILE)"
	@echo "OK: $(DOXYFILE) configurado."

docs: doxyfile
	@cd "$(REPO_ROOT)" && $(DOXYGEN) Doxyfile
	@touch "$(DOXY_OUT)/html/.nojekyll" 2>/dev/null || true
	@echo "OK: $(DOXY_HTML)"

docs-open: docs
	@if command -v xdg-open >/dev/null 2>&1; then \
		xdg-open "$(DOXY_HTML)"; \
	elif command -v open >/dev/null 2>&1; then \
		open "$(DOXY_HTML)"; \
	else \
		echo "Abre manualmente: $(DOXY_HTML)"; \
	fi

docs-serve: docs
	@echo "Sirviendo en http://localhost:8000/ (Ctrl+C para detener)"
	@python3 -m http.server 8000 -d "$(DOXY_OUT)/html"

docs-clean:
	rm -rf "$(DOXY_OUT)"
