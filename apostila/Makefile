MAIN = main
BUILD = build
# Use "make LATEX=xelatex pdf" se tiver XeLaTeX (melhor para UTF-8 nos .cpp)
LATEX ?= pdflatex

.PHONY: all pdf clean watch

all: pdf

pdf:
	@mkdir -p $(BUILD)
	-$(LATEX) -interaction=nonstopmode -output-directory=$(BUILD) $(MAIN).tex
	-$(LATEX) -interaction=nonstopmode -output-directory=$(BUILD) $(MAIN).tex
	@test -f $(BUILD)/$(MAIN).pdf
	@cp $(BUILD)/$(MAIN).pdf ./$(MAIN).pdf
	@echo "PDF gerado: apostila/$(MAIN).pdf"

clean:
	rm -rf $(BUILD) $(MAIN).pdf $(MAIN).aux $(MAIN).log $(MAIN).toc $(MAIN).out
