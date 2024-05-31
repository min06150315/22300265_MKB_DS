CC = g++
LIBPATH = ./
LIB_SRC = $(LIBPATH)
LIB_OBJ = $(subst /,\,$(LIBPATH))
INCLUDEPATH = -I$(LIBPATH)
EXE1 = ds041
EXE2 = ds042
EXEALL = $(EXE1)

all: $(EXEALL)

$(LIB_OBJ): $(LIB_SRC)
	$(CC) -c $< -o $@ $(INCLUDEPATH)

$(EXE1): $(EXE1).cpp 
	$(CC) -o $@ $^ 

clean:
	del $(EXE1).exe
	del $(LIB_OBJ)