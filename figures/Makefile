all: fsm.png fsm2.png

%.png: %.pdf
	convert -density 300 -resize 50% $^ $@

%.pdf: %.tex
	latexmk -pdf $^
