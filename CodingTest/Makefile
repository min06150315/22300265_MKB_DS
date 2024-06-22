CC = g++
LIBPATH = ./lib/
LIB_SRC = $(LIBPATH)Sorting.cpp
LIB_OBJ = $(subst /,\,$(LIBPATH)Sorting.o)
INCLUDEPATH = -I$(LIBPATH)
EXE1 = ds101
EXE2 = ds102
EXE3 = ds103
EXE4 = ds104
EXE5 = ds105
EXE6 = ds106
EXE7 = ds107
EXE8 = ds108
EXE9 = ds109
EXE10 = ds110
EXEALL = $(EXE1) $(EXE3) $(EXE4) $(EXE5) $(EXE6) $(EXE7) $(EXE8)

all: $(EXEALL)

$(LIB_OBJ): $(LIB_SRC)
	$(CC) -c $< -o $@ $(INCLUDEPATH)

$(EXE1): $(EXE1).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE3): $(EXE3).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE4): $(EXE4).cpp 
	$(CC) -o $@ $^ 

$(EXE5): $(EXE5).cpp 
	$(CC) -o $@ $^ 

$(EXE6): $(EXE6).cpp 
	$(CC) -o $@ $^ 

$(EXE7): $(EXE7).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

$(EXE8): $(EXE8).cpp 
	$(CC) -o $@ $^ 

clean:
	del $(EXE1).exe
	del $(EXE3).exe
	del $(EXE4).exe
	del $(EXE5).exe
	del $(EXE6).exe
	del $(EXE7).exe
	del $(EXE8).exe
	del $(LIB_OBJ)
