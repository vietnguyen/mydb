#############################################################################
# COSC2541 - Programming C++
# Semester 3 2011 Assignment #1
# Full Name        : Nguyen Pham Hoang Quoc Viet
# Student Number   : 3324821
#############################################################################

CC=g++
CFLAGS=  -Wall
TARGET= mydb
OBJ = mydb.o

%.o: %.c 
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean: 
	rm -f *.o $(TARGET)

archive:
	zip $(USER)-a1.zip mydb.o
