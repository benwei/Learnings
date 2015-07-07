
define setup_env
	@which staticjinja ; \
	if [ $$? -eq 1 ] ; then \
		pip install staticjinja ; \
	fi
endef

all:
	$(call setup_env)

	python build.py
