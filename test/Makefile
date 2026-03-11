# Compiler and Flags
CC       := gcc
CXX      := g++
OUTDIR   := build
TESTDIR  := lltc

#for coverage test
GCOV     := gcov
LCOV     := lcov
GENHTML  := genhtml

# Updated paths based on your tree image (test is sibling to source)
TOP      := $(abspath $(CURDIR)/..)
# The tree shows: source -> src
SRC_DIR  := $(TOP)/source/src
INC_DIR  := $(TOP)/source/inc
MOCK_DIR := $(TESTDIR)

# Includes
INCLUDES := -I$(INC_DIR) -I$(MOCK_DIR)
CXXFLAGS := -Wall -Wextra -std=c++17 $(INCLUDES) -fprofile-arcs -ftest-coverage
CFLAGS   := -Wall -Wextra -std=c11 $(INCLUDES) -DUNIT_TEST \
			-fprofile-arcs -ftest-coverage
LDLIBS   := -lgtest -lgtest_main -lpthread -lgcov

# Implementation objects
C_SRC    := $(SRC_DIR)/Sensor.c \
			$(SRC_DIR)/MessageQueue.c
C_OBJ    := $(OUTDIR)/Sensor.o \
			$(OUTDIR)/MessageQueue.o
MOCK_OBJ   := $(OUTDIR)/LltcMock.o

# Test objects
TEST_SRC := lltc/LltcEngineSpeedMonitoringSystem.cpp
TEST_OBJ := $(OUTDIR)/LltcEngineSpeedMonitoringSystem.o

TARGET   := $(OUTDIR)/lltc_test

.PHONY: all clean test

all: $(OUTDIR) $(TARGET)

$(OUTDIR):
	mkdir -p $(OUTDIR)

# Rule to compile the actual Sensor logic from the source/src directory
$(OUTDIR)/Sensor.o: $(SRC_DIR)/Sensor.c
	@echo "Compiling Implementation: $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTDIR)/MessageQueue.o: $(SRC_DIR)/MessageQueue.c
	@echo "Compiling Implementation: $<"
	$(CC) $(CFLAGS) -c $< -o $@

$(OUTDIR)/LltcMock.o: $(MOCK_DIR)/LltcMock.c
	@echo "Compiling Implementation: $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile the Test logic
$(OUTDIR)/LltcEngineSpeedMonitoringSystem.o: $(TEST_SRC)
	@echo "Compiling Test: $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link everything together
$(TARGET): $(C_OBJ) $(TEST_OBJ) $(MOCK_OBJ)
	@echo "Linking Final Test Executable..."
	$(CXX) $^ -o $@ $(LDLIBS) $(CXXFLAGS)

# New Target for Coverage
coverage: test
	@echo "--- Generating Coverage Report ---"
	# Run gcov on the source files located in the build directory
	# -n: no output files, -b: branch probabilities, -c: count
	$(GCOV) -n $(C_OBJ)
	
# Optional: HTML Report (Requires lcov and genhtml installed)
report: coverage
	@mkdir -p $(OUTDIR)/coverage_report
	$(LCOV) --capture --directory $(OUTDIR) --output-file $(OUTDIR)/coverage.info --no-external
	$(GENHTML) $(OUTDIR)/coverage.info --output-directory $(OUTDIR)/coverage_report
	@echo "HTML report generated at: $(OUTDIR)/coverage_report/index.html"

test: all
	./$(TARGET)

clean:
	rm -rf $(OUTDIR)