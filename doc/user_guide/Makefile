PDFLATEX=
BIBTEX=

PDFLATEXCMD = $(PDFLATEX) \
 '\nonstopmode \newcommand{\GyotoSrcDir}{../..} \input{./GyotoManual.tex}'

vpath %.tex .
vpath %.bib .

TEXINPUTS=.:.:../../images/:
export TEXINPUTS

all: GyotoManual.pdf

GyotoManual.aux: GyotoManual.tex
	$(PDFLATEXCMD)

GyotoManual.bbl: GyotoManual.aux GyotoManual.bib
	$(BIBTEX) $<

GyotoManual.pdf: GyotoManual.tex GyotoManual.bbl
	$(PDFLATEXCMD)
	$(PDFLATEXCMD)

clean:
	-rm GyotoManual.aux GyotoManual.bbl GyotoManual.blg GyotoManual.log
	-rm GyotoManual.out GyotoManual.pdf GyotoManual.toc

.PHONY: clean
