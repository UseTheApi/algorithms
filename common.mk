ALGO=$(algorithms)

clean:
	@rm -rf $(ALGO)/$(CUR_PATH)/build

run: clean
	@cd $(ALGO)/$(CUR_PATH) && if [ ! -d "build" ]; then mkdir build; fi
	@cd $(ALGO)/$(CUR_PATH)/build && cmake ..
	@cd $(ALGO)/$(CUR_PATH)/build && make
	@cd $(ALGO)/$(CUR_PATH)/build && ./$(PACKAGE)

build: clean
	@cd $(ALGO)/$(CUR_PATH) && if [ ! -d "build" ]; then mkdir build; fi
	@cd $(ALGO)/$(CUR_PATH)/build && cmake ..
	@cd $(ALGO)/$(CUR_PATH)/build && make

test: clean
	@cd $(ALGO)/$(CUR_PATH) && if [ ! -d "build" ]; then mkdir build; fi
	@cd $(ALGO)/$(CUR_PATH)/build && cmake ..
	@cd $(ALGO)/$(CUR_PATH)/build && make
	@cd $(ALGO)/$(CUR_PATH)/build && ./$(PACKAGE)_test
