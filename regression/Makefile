include ../Makefile.include

MODULES = $(MAIN) \
          test_scanner \
          test_lexer \
          test_parser \

all:
	@for dir in $(MODULES); do make -C $$dir; done

.PHONY: clean
clean:
	@for dir in $(MODULES); do make -C $$dir clean; done

