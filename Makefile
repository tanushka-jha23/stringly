stringly.o: src/stringly.c
	gcc src/stringly.c -o stringly.o -c

test_char_utils: test_char_utils.o char_utils.o
	gcc test_char_utils.o char_utils.o -o test_char_utils
	./test_char_utils

test_char_utils.o: tests/test_char_utils.c
	gcc tests/test_char_utils.c -o test_char_utils.o -c

test_miniutils: test_miniutils.o miniutils.o
	gcc test_miniutils.o miniutils.o -o test_miniutils
	./test_miniutils

test_miniutils.o: tests/test_miniutils.c
	gcc tests/test_miniutils.c -o test_miniutils.o -c

test_string_concat: test_string_concat.o stringly.o char_utils.o
	gcc test_string_concat.o stringly.o char_utils.o -o test_string_concat
	./test_string_concat

test_string_concat.o: tests/test_string_concat.c
	gcc tests/test_string_concat.c -o test_string_concat.o -c

test_string_format: test_string_format.o stringly.o string_format.o miniutils.o char_utils.o
	gcc test_string_format.o stringly.o string_format.o miniutils.o char_utils.o -o test_string_format
	./test_string_format

test_string_format.o: tests/test_string_format.c
	gcc tests/test_string_format.c -o test_string_format.o -c

string_format.o: src/string_format.c 
	gcc src/string_format.c -o string_format.o -c

test_string_internals: test_string_internals.o stringly.o char_utils.o
	gcc test_string_internals.o stringly.o char_utils.o -o test_string_internals
	./test_string_internals

test_string_internals.o: tests/test_string_internals.c
	gcc tests/test_string_internals.c -o test_string_internals.o -c

test_string_join: test_string_join.o stringly.o char_utils.o
	gcc test_string_join.o stringly.o char_utils.o -o test_string_join
	./test_string_join

test_string_join.o: tests/test_string_join.c
	gcc tests/test_string_join.c -o test_string_join.o -c

test_string_manipulation: test_string_manipulation.o stringly.o char_utils.o
	gcc test_string_manipulation.o stringly.o char_utils.o -o test_string_manipulation
	./test_string_manipulation

test_string_manipulation.o: tests/test_string_manipulation.c
	gcc tests/test_string_manipulation.c -o test_string_manipulation.o -c

test_string_slice: test_string_slice.o stringly.o char_utils.o
	gcc test_string_slice.o stringly.o char_utils.o -o test_string_slice
	./test_string_slice

test_string_slice.o: tests/test_string_slice.c
	gcc tests/test_string_slice.c -o test_string_slice.o -c

test_string_split: test_string_split.o stringly.o char_utils.o
	gcc test_string_split.o stringly.o char_utils.o -o test_string_split
	./test_string_split

test_string_split.o: tests/test_string_split.c
	gcc tests/test_string_split.c -o test_string_split.o -c

test_string_swapcase: test_string_swapcase.o stringly.o char_utils.o
	gcc test_string_swapcase.o stringly.o char_utils.o -o test_string_swapcase
	./test_string_swapcase

test_string_swapcase.o: tests/test_string_swapcase.c
	gcc tests/test_string_swapcase.c -o test_string_swapcase.o -c

test_string_trim: test_string_trim.o stringly.o char_utils.o string_trim.o
	gcc test_string_trim.o stringly.o char_utils.o string_trim.o -o test_string_trim
	./test_string_trim

test_string_trim.o: tests/test_string_trim.c
	gcc tests/test_string_trim.c -o test_string_trim.o -c

string_trim.o: src/string_trim.c
	gcc src/string_trim.c -o string_trim.o -c

miniutils.o: src/miniutils.c
	gcc src/miniutils.c -o miniutils.o -c

char_utils.o: src/char_utils.c
	gcc src/char_utils.c -o char_utils.o -c


