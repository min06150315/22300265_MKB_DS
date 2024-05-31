CC = g++
LIBPATH = ./
LIB_SRC = $(LIBPATH)
LIB_OBJ = $(subst /,\,$(LIBPATH))
INCLUDEPATH = -I$(LIBPATH)
EXE1 = ds101
EXE2 = ds102
EXE3 = ds103
EXE4 = ds104
EXE5 = ds105
EXEALL = $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5)

all: $(EXEALL)

$(LIB_OBJ): $(LIB_SRC)
	$(CC) -c $< -o $@ $(INCLUDEPATH)

$(EXE1): $(EXE1).cpp 
	$(CC) -o $@ $^ 

$(EXE2): $(EXE2).cpp 
	$(CC) -o $@ $^ 

$(EXE3): $(EXE3).cpp 
	$(CC) -o $@ $^ 

$(EXE4): $(EXE4).cpp 
	$(CC) -o $@ $^ 

$(EXE5): $(EXE5).cpp 
	$(CC) -o $@ $^ 

clean:
	del $(EXE1).exe
	del $(EXE2).exe
	del $(EXE3).exe
	del $(EXE4).exe
	del $(EXE5).exe
	del $(LIB_OBJ)