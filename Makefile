ifdef OS
   CREATE_DIR = if not exist "build\" mkdir "build\"
   REMOVE_FILE = del
   T1 = t1_heap.exe
   T2 = t2_ordenacao.exe
   T3 = t3_busca.exe
else
   ifeq ($(shell uname), Linux)
      CREATE_DIR = mkdir -p build
	  REMOVE_FILE = rm
	  T1 = t1_heap.out
      T2 = t2_ordenacao.out
      T3 = t3_busca.out
   endif
endif

LIBS = -lhelper -lbusca -lheap -lsort

build-t1: folder compilacao $(LIBS) main run-t1
build-t2: folder compilacao $(LIBS) main run-t2
build-t3: folder compilacao $(LIBS) main run-t3

folder:
	@$(CREATE_DIR)

compilacao: 
	@echo #Compilando Libs:
	@cd build && gcc -c ../libs/*.c

-lhelper: 
	@echo  1 - helper
	@cd build && ar rcs libhelper.a $(shell dir /b/s "helper*.o")

-lbusca:
	@echo  2 - busca
	@cd build && ar rcs libbusca.a $(shell dir /b/s "busca*.o")

-lheap:
	@echo  3 - heap
	@cd build && ar rcs libheap.a $(shell dir /b/s "heap*.o")

-lsort:
	@echo  4 - sort
	@cd build && ar rcs libsort.a $(shell dir /b/s "sort*.o")

main:
	@echo #Building...
	@gcc -static src/t1_heap.c -L ./build -I ./libs $(LIBS) -o build/$(T1) &&\
	gcc -static src/t2_ordenacao.c -L ./build -I ./libs $(LIBS) -o build/$(T2) &&\
	gcc -static src/t3_busca.c -L ./build -I ./libs $(LIBS) -o build/$(T3) &&\
	cd build && $(REMOVE_FILE) *.o

run-t1:
	@echo #Executando Trabalho 1: &&\
	cd build &&\
	$(T1)

run-t2:
	@echo #Executando Trabalho 2: &&\
	cd build &&\
	$(T2)

run-t3:
	@echo #Executando Trabalho 3: &&\
	cd build &&\
	$(T3)

