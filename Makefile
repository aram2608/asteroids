CC := clang

BUILD_DIR := ./build
APP := asteroids

APP_DIR := ./asteroids
SRC_DIR := $(APP_DIR)/src/
INC_DIR := $(APP_DIR)/include/
LIB_DIR := $(APP_DIR)/libs/

SRC_FILES := $(wildcard $(SRC_DIR)*.c)
CFLAGS := -Wall -Wextra -pedantic

INCLUDE_FLAG := -I$(INC_DIR)
LD_FLAG := -L$(LIB_DIR) -lraylib
FRAMEWORKS := -framework CoreFoundation -framework CoreVideo -framework IOKit -framework Cocoa -framework OpenGL

$(BUILD_DIR)/$(APP):
	@mkdir -p $(@D)
	$(CC) $(INCLUDE_FLAG) $(LD_FLAG) $(FRAMEWORKS) $(CFLAGS) -o $@ $(SRC_FILES)