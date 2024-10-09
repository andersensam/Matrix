.PHONY: all debug clean

MKDIR_P = mkdir -p
RM_RF = rm -rf
CFLAGS = --std=c99
DEBUG = -Wall -Wextra -Wpedantic -g

all:
	$(MKDIR_P) target
	$(CC) $(CFLAGS) tests.c -o target/tests

debug:
	$(MKDIR_P) target
	$(CC) $(CFLAGS) $(DEBUG) tests.c -o target/tests_debug

clean:
	$(RM_RF) target/