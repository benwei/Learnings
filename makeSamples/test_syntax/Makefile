
# test duplicated item in list to a variable
test_duplicated_item = a.o b.o b.o a.o

TARGETS += test-duplicated-item-target
TARGETS += test-banner
TARGETS += test-filter-out
TARGETS += test-mscript


all: $(TARGETS)

test-duplicated-item-target: $(test_duplicated_item)
	$(call run-duplicated-item-example)

test-banner: 
	@$(call banner-default) ; \
	eval "$(call test_document_banner,$@,1)"

test-mscript: export mscript = $(value test_shell1)
test-mscript: 
	@$(call banner-default) ; \
	eval "$$mscript" ;

myitems:= e a b c d
filter-pattern:= a b 
filter-result :=$(sort $(filter-out $(filter-pattern),$(myitems)))
test-filter-out:
	@$(call banner-default); \
	echo "sorted filter-out([$(filter-pattern)],[$(myitems)]) = [$(filter-result)]"

clean:
	rm -f *.o

define run-duplicated-item-example
	@## http://www.gnu.org/software/make/manual/make.html#Quick-Reference
	@## use $^ will filter the duplicates from $(test_duplicated_item)
	@echo "> $@" ;\
	echo "$$^: $^" ; \
	echo "$$+: $+"
endef

define  test_shell1
export a=1
export b=2
cat <<EOF
run test data $a + $b
EOF
endef

define  test_shell1
export a=1
export b=2
cat <<EOF
run test data $a + $b
EOF
endef

define test_document_banner
	echo === $(1) $(2) ===
endef

define banner-default
	echo ">>> [$@]"
endef
