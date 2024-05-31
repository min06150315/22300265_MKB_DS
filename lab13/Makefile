CC = g++
LIBPATH = ./lib/
LIB_SRC = $(LIBPATH)Sorting.cpp
LIB_OBJ = $(subst /,\,$(LIBPATH)Sorting.o)
INCLUDEPATH = -I$(LIBPATH)
EXE1 = ds071
EXE2 = ds072
EXE3 = ds073
EXE4 = ds074
EXE5 = ds075
EXE6 = ds076
EXEALL = $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5) $(EXE6)

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

$(EXE6): $(EXE6).cpp $(LIB_OBJ)
	$(CC) -o $@ $^ $(INCLUDEPATH)

clean:
	del $(EXE1).exe
	del $(EXE2).exe
	del $(EXE3).exe
	del $(EXE4).exe
	del $(EXE5).exe
	del $(EXE6).exe
	del $(LIB_OBJ)