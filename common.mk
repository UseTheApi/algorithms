ALGO=$(algorithms)

run:
	@cd $(ALGO)/$(CUR_PATH) && if [ ! -d "build" ]; then mkdir build; fi
	@cd $(ALGO)/$(CUR_PATH)/build && cmake ..
	@cd $(ALGO)/$(CUR_PATH)/build && make
	@cd $(ALGO)/$(CUR_PATH)/build && ./$(PACKAGE)

