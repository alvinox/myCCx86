include ../Makefile.include

MODULES = $(MAIN) \
          test_scanner \

all:
	@for dir in $(MODULES); do make -C $$dir; done

.PHONY: clean
clean:
	@for dir in $(MODULES); do make -C $$dir clean; done

