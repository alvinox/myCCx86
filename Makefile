include Makefile.include

.PHONY: all
all: gen_objects gen_shared_lib gen_execute

CAPP_LIBS = lib$(MODULE).so

gen_objects:
	@if [ ! -d $(BUILD_DIR) ]; then echo mkdir -p $(BUILD_DIR); mkdir -p $(BUILD_DIR); fi
	@make -C $(INFRA_DIR)

gen_shared_lib:
	$(CC) $(OPTIONS) $(CXXFLAGS) -shared $(wildcard $(INFRA_DIR)/$(OBJDIR)/*$(OBJ_TYPE).o) -o $(BUILD_DIR)/$(CAPP_LIBS) $(LDFLAGS)
	@make -C $(REGRESSION_DIR)

gen_execute:
	@ln -fs ./$(REGRESSION_DIR)/$(MAIN)/$(MAIN) ./$(MODULE)

#############################################################################3
.PHONY: clean
clean:
	@make -C $(INFRA_DIR) clean
	@make -C $(REGRESSION_DIR) clean
	@rm -rf $(BUILD_DIR)
	@rm -rf $(MODULE)
