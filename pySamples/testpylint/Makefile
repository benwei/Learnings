ORIGINPY = simplecaeser_origin.py

MODIFIED = simplecaeser_modified.py

all: modified

origin:
	pylint $(ORIGINPY) ; \
	if [ $$? -eq 20 ]; then \
		echo "found origin files issue with pylint" ; \
	fi

modified:
	pylint $(MODIFIED) 


inst:
	# debian and ubuntu
	which apt-get ; \
	if [ $$? -eq 0 ] ; then \
		sudo apt-get install pylint ; \
	else \
		which pip ; \
		if [ $$? -eq 0 ] ; then \
			pip install pylint
		else \
			echo "use another way" ; \
		fi \
	fi

