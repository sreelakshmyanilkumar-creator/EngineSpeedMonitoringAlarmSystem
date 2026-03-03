# Compiler and flags
CC       := gcc
INCLUDES := -I./inc
CFLAGS   := -Wall -Wextra -Wpedantic -std=c11 -O0 -g -fstack-usage -pthread \
			 $(INCLUDES) -MMD -MP 
LDFLAGS  :=

# Project structure
SRC_DIR  := src
INC_DIR  := inc
BUILD_DIR:= build
TARGET   := $(BUILD_DIR)/SpeedAlarm

# Source and object files
SRC      := $(wildcard $(SRC_DIR)/*.c)
OBJ      := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEPS     := $(OBJ:.o=.d)

# Default target
.PHONY: all
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJ)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

# Compile source files into object files (and generate .d dependency files)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Include auto-generated dependency files
-include $(DEPS)

# Convenience targets
.PHONY: run clean debug rebuild

run: $(TARGET)
	./$(TARGET)

debug: CFLAGS += -g -O0
debug: rebuild

rebuild: clean all

clean:
	$(RM) -r $(BUILD_DIR)
