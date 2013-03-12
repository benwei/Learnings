all:
	@# writes R output to stdout and stderr
	@# !/usr/bin/env Rscript
	Rscript test.R

test.Rout:
	@# run in batch mode 
	R CMD BATCH test.R test.Rout

show:
	cat test.Rout

clean:
	rm -f test.Rout
