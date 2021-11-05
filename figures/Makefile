fsm.png: fsm.pdf
	convert -density 300 -resize 50% $^ $@

fsm.pdf: fsm.tex
	latexmk -pdf $^
