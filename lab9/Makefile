CC = g++
LIBPATH = ./
LIB_SRC = $(LIBPATH)
LIB_OBJ = $(subst /,\,$(LIBPATH))
INCLUDEPATH = -I$(LIBPATH)
EXE1 = ds031
EXE2 = ds032
EXE3 = ds033
EXEALL = $(EXE1) $(EXE2) $(EXE3)

all: $(EXEALL)

$(LIB_OBJ): $(LIB_SRC)
	$(CC) -c $< -o $@ $(INCLUDEPATH)

$(EXE1): $(EXE1).cpp 
	$(CC) -o $@ $^ 

$(EXE2): $(EXE2).cpp
	$(CC) -o $@ $^
   
$(EXE3): $(EXE3).cpp
	$(CC) -o $@ $^

clean:
	del $(EXE1).exe
	del $(EXE2).exe
	del $(EXE3).exe
	del $(LIB_OBJ)