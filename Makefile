headers := $(wildcard include/*.h)
src := $(wildcard src/*.c)
obj := $(addprefix obj/,$(notdir $(src:.c=.o)))
tests := $(wildcard tests/*.c)
exe_tests := $(foreach test,$(tests),$(addprefix debug/,$(notdir $(basename $(test)))))

main :=
ifeq ($(OS),Windows_NT)
	main += main.exe
	exe_tests := $(foreach test,$(tests),$(addprefix debug/,$(notdir $(basename $(test))).exe))
else
	main += main
endif

.PHONY: all run clean test

all: $(main)

$(main): $(obj) main.c $(headers)
	gcc main.c $(obj) -o $(main)

test: $(exe_tests) tests/orange_juice.h
	@for x in $(exe_tests); do \
		./$$x; \
	done

debug/%: tests/$(basename %).c $(obj)
	gcc $< $(obj) -o $@

obj/%.o: src/%.c
	gcc $< -o $@ -c

run: $(main)
	@./$(main)

clean:
	@rm -f $(foreach x,$(obj),"$(x)") "$(main)"
	@echo "cleaned."
