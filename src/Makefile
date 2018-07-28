CC = gcc
SOURCES = $(wildcard ./*.c)
HEADERS = $(wildcard ./*.h)
OBJ_FILES = $(patsubst ./%.c,%.o,$(SOURCES))
FILENAMES = $(patsubst ./%.c, %, $(SOURCES))

compilesrc: $(SOURCES)
	@echo "Compiling those sources.. $(SOURCES)"
	@echo "Headers: $(HEADERS)"
	@$(CC) -Wall $(SOURCES)
	@echo "\n----------------\nCompilation terminated\n----------------\n"

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(PKGCONF)

alltobj: $(FILENAMES)
$(FILENAMES): ./%: ./%.c
	@echo "Compiling $^ to $@.o"
	$(CC) -c -o $@.o $^ 

compileobj: $(OBJ_FILES)
	$(CC) $(OBJ_FILES)

clean:
	@rm *.o && echo "All .o files removed"
