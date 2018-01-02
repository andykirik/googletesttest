EXECUTABLE_NAME=main.exe
EXECUTABLE_TEST=main_test.exe
DEBUG=
CFLAGS=/c $(DEBUG) /W4 /EHsc -I. -IC:\Projects\googletest-master\googletest\include
LFLAGS=$(DEBUG) -LIBPATH:C:\Projects\googletest-master\googletest\msvc\2010\gtest\Win32-Release

all: $(EXECUTABLE_NAME) $(EXECUTABLE_TEST)

$(EXECUTABLE_NAME): main.obj class1.obj
	link /out:$(EXECUTABLE_NAME) $** 

main.obj: main.cpp class1.h
	$(CC) $(CFLAGS) main.cpp

class1.obj: class1.cpp class1.h common.h
	$(CC) $(CFLAGS) class1.cpp

$(EXECUTABLE_TEST): main_test.obj class1.obj
	link $(LFLAGS) /out:$(EXECUTABLE_TEST) $** gtest.lib

main_test.obj: main_test.cpp class1.h
	$(CC) $(CFLAGS) main_test.cpp

clean: 
	del *.obj main.exe main_test.exe