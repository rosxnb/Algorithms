COMPILER=clang++
CPP_FLAGS=-std=c++20 -g
BUILD_DIR=build

all: insertion_sort bubble_sort merge_sort

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/utilities.o: misc/utilities.cpp misc/utilities.hpp | $(BUILD_DIR)
	$(COMPILER) $(CPP_FLAGS) -c $< -o $@

insertion_sort: insertion_sort.cpp $(BUILD_DIR)/utilities.o | $(BUILD_DIR)
	$(COMPILER) $(CPP_FLAGS)  $^ -o $(BUILD_DIR)/insertion_sort

bubble_sort: bubble_sort.cpp $(BUILD_DIR)/utilities.o | $(BUILD_DIR)
	$(COMPILER) $(CPP_FLAGS) $^ -o $(BUILD_DIR)/bubble_sort

merge_sort: merge_sort.cpp $(BUILD_DIR)/utilities.o | $(BUILD_DIR)
	$(COMPILER) $(CPP_FLAGS) $^ -o $(BUILD_DIR)/merge_sort

clean:
	rm -rf $(BUILD_DIR)
