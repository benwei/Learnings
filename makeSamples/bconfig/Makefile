
include bconfig

test-$(app1) += app1
test-$(app2) += app2
test-$(app3) += app3
test-$(app4) += app4

testall = $(test-y:%=%/all)
testnot = $(test-n:%=%/not)

all: build
	@echo "build app: $(test-y)"
	@echo "not build app: $(test-n)"

home/yourname/mydir:
	@echo "${@D}"

%/all:
	@echo "all -> $(@D)"

%/not:
	@echo "not -> $(@D)"

build: $(testall) $(testnot)
