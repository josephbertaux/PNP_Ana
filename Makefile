SHELL=/bin/bash

TRGT = pnp_ana

SRC_DIR = ./src
OBJ_DIR = ./bld

CC = g++

OBJS = $(OBJ_DIR)/pnp_ana.o $(OBJ_DIR)/PNP_Wrapper.o $(OBJ_DIR)/PNP_Ana.o 

FLAGS = `root-config --cflags`
#INCS = -I`root-config --incdir` #already included with root-config --cflags
LIBS = `root-config --evelibs` -lTMVA -lTMVAGui -lRooFitCore -lRooFitMore -lRooFit

$(TRGT) : $(OBJS)
	$(CC) $(FLAGS) $(INCS) -o $(TRGT) $(OBJS) $(LIBS)

$(OBJ_DIR)/pnp_ana.o :
	$(CC) $(FLAGS) $(INCS) -c $(SRC_DIR)/pnp_ana.cc $(LIBS)
	mv pnp_ana.o $(OBJ_DIR)/pnp_ana.o

$(OBJ_DIR)/PNP_Wrapper.o :
	$(CC) $(FLAGS) $(INCS) -c $(SRC_DIR)/PNP_Wrapper.cc $(LIBS)
	mv PNP_Wrapper.o $(OBJ_DIR)/PNP_Wrapper.o

$(OBJ_DIR)/PNP_Ana.o :
	$(CC) $(FLAGS) $(INCS) -c $(SRC_DIR)/PNP_Ana.cc $(LIBS)
	mv PNP_Ana.o $(OBJ_DIR)/PNP_Ana.o

.PHONY : clean
clean :
	-rm -rf $(TRGT) $(OBJS)
