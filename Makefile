sources := $(wildcard src/*.c)
objects := $(notdir $(basename $(sources)))
objects := $(foreach x,$(objects),obj/$(x).o)
tests := $(notdir $(basename $(wildcard tests/test_*.c)))

.PHONY: test

test_%: tests/test_%.c $(objects)
	gcc $^ -o $@

obj/%.o: src/%.c
	gcc $^ -o $@ -c

test: $(tests)
	$(foreach x,$(tests),./$(x);)

$(objects):

clean:
	-rm obj/*  
	-rm test_*
