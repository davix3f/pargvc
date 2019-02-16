CC = gcc
SOURCES = $(wildcard ./*.c ./*/*.c)
HEADERS = $(wildcard ./*.h ./*/*.h)
OBJ_FILES = $(patsubst ./%.c, %.o, $(SOURCES))
FILENAMES = $(patsubst ./%.c, %, $(SOURCES))

compilesrc: $(SOURCES)
	@echo "Compiling those sources.. $(SOURCES)"
	@echo "Headers: $(HEADERS)"
	@$(CC) -Wall $(SOURCES)
	@echo "\n----------------\nCompilation terminated\n----------------\n"

compile-nowall: $(SOURCES)
	@echo "Compiling those sources.. $(SOURCES)"
	@echo "Headers: $(HEADERS)"
	@$(CC) $(SOURCES)
	@echo "\n----------------\nCompilation terminated\n----------------\n"

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(PKGCONF)

alltobj: $(FILENAMES)
	$(FILENAMES): ./%: ./%.c
	@echo "Compiling $^ to $@.o"
	$(CC) -c -o $@.o $^

compileobj: $(OBJ_FILES)
	$(CC) $(OBJ_FILES)

compilestat: alltobj
	@echo -n "\nCompiling as static lib"
	ar rcsv libpargvc.a $(OBJ_FILES)

mvlib:
	@echo -n "\nCopying headers to /usr/include/\n"
	sudo mkdir --parents /usr/include/pargvc_backends/
	sudo cp -t /usr/include/pargvc_backends/ $(HEADERS)
	sudo mv /usr/include/pargvc_backends/pargvc.h /usr/include/pargvc.h
	@echo "Copying libpargvc.a to /usr/lib\n"
	sudo cp --force libpargvc.a /usr/lib/libpargvc.a

installib: compilestat mvlib clean

clean:
	@rm *.o && echo "All .o files removed"