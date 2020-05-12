
# test duplicated item in list to a variable

test_duplicated_item = a.o b.o b.o a.o


all: test-duplicated-item-target

test-duplicated-item-target: $(test_duplicated_item)
	@## http://www.gnu.org/software/make/manual/make.html#Quick-Reference
	@## use $^ will filter the duplicates from $(test_duplicated_item)
	@echo "$$^: $^"
	@echo "$$+: $+"

clean:
	rm -f *.o
