include ../Makefile.include
include Makefile.include

DEPS = $(INFRA_HFILES) Makefile ../Makefile.include

OBJS = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(INFRA_CFILES)))
OBJ_OWNS = $(patsubst %.o, %$(OBJ_TYPE).o, $(OBJS))

OBJS_PLUSPLUS = $(addprefix $(OBJDIR)/, $(patsubst %.cpp, %.o, $(INFRA_CPPFILES)))
OBJ_OWNS_PLUSPLUS = $(patsubst %.o, %$(OBJ_TYPE).o, $(OBJS_PLUSPLUS))

INC = -I./ \

CFLAGS += $(INC)

.PHONY: all
all: $(OBJDIR) $(OBJ_OWNS) $(OBJ_OWNS_PLUSPLUS)

$(OBJDIR):
	@if [ ! -d "$(OBJDIR)" ]; then echo "mkdir -p $(OBJDIR)"; mkdir -p "$(OBJDIR)"; fi

$(OBJ_OWNS):$(OBJDIR)/%$(OBJ_TYPE).o:./%.c $(DEPS)
	$(CC) -c $(OPTIONS) $(CFLAGS) $< -o $(@)

$(OBJ_OWNS_PLUSPLUS):$(OBJDIR)/%$(OBJ_TYPE).o:./%.cpp $(DEPS)
	$(CC) -c $(OPTIONS) $(CFLAGS) $< -o $(@)

.PHONY: clean
clean:
	rm -rf $(OBJDIR)

