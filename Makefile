# GNU Make solution makefile autogenerated by Premake
# Type "make help" for usage help

ifndef config
  config=debug
endif
export config

PROJECTS := test_board

.PHONY: all clean help $(PROJECTS)

all: $(PROJECTS)

test_board: 
	@echo "==== Building test_board ($(config)) ===="
	@${MAKE} --no-print-directory -C . -f test_board.make

clean:
	@${MAKE} --no-print-directory -C . -f test_board.make clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "   debug"
	@echo "   release"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   test_board"
	@echo ""
	@echo "For more information, see http://industriousone.com/premake/quick-start"
