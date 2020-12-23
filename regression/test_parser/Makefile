include ../../Makefile.include

INC = -I./ \
      -I../../$(INFRA_DIR) \

CXXFLAGS += $(INC)

CFILES = \

CPLUSPLUSFULES = main.cpp \
                 test_parser.cpp \

HFILES = test_parser.h \

DEPS = $(HFILES) Makefile ../../Makefile.include

OBJS = $(addprefix $(OBJDIR)/, $(patsubst %.c, %.o, $(CFILES)))
OBJ_OWNS = $(patsubst %.o, %$(OBJ_TYPE).o, $(OBJS))

OBJS_PLUSPLUS = $(addprefix $(OBJDIR)/, $(patsubst %.cpp, %.o, $(CPLUSPLUSFULES)))
OBJ_OWNS_PLUSPLUS = $(patsubst %.o, %$(OBJ_TYPE).o, $(OBJS_PLUSPLUS))

LDFLAGS += -L../../build
LIB_DEPS += -l$(MODULE)

EXEC = "entry"

all: $(EXEC)

$(EXEC): $(OBJDIR) $(OBJ_OWNS) $(OBJ_OWNS_PLUSPLUS)
	$(CC) $(OPTIONS) $(CXXFLAGS) $(OBJ_OWNS) $(OBJ_OWNS_PLUSPLUS) $(LDFLAGS) $(LIB_DEPS) -o $(EXEC)

$(OBJDIR):
	@if [ ! -d "$(OBJDIR)" ]; then echo "mkdir -p $(OBJDIR)"; mkdir -p "$(OBJDIR)"; fi

$(OBJ_OWNS):$(OBJDIR)/%$(OBJ_TYPE).o:./%.c $(DEPS)
	$(CC) -c $(OPTIONS) $(CXXFLAGS) $< -o $(@)

$(OBJ_OWNS_PLUSPLUS):$(OBJDIR)/%$(OBJ_TYPE).o:./%.cpp $(DEPS)
	$(CC) -c $(OPTIONS) $(CXXFLAGS) $< -o $(@)

.PHONY: clean
clean:
	@rm -rf $(OBJDIR)
	@rm -rf $(EXEC)


