CC = g++ #compiler
ded_flags = -D _DEBUG -ggdb3 -std=c++17 -D_FORTIFY_SOURCES=3 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
CFLAGS = -c $(ded_flags) #tag of *.c file + compilaor flags
LDFLAGS = $(ded_flags)   #linker flags
SOURCES = main_onegin.cpp my_swap.cpp array_sort.cpp output_functions.cpp array_to_file_translation.cpp files_input.cpp
OBJECTS = $(SOURCES:%.cpp=onegin_o/%.o) #rename files *.cpp --> file *.o
EXECUTABLE = onegin				  
#sourses is a list
.PHONY: all				#target name
.PHONY: clean			#target name

#all: means make will call all needed to complete build 
all: $(EXECUTABLE)         	#taget: requisits(dependency) \enter\tab shell commands

#LINKER
$(EXECUTABLE): $(OBJECTS) 				#taget: requisits(dependency) \enter\tab shell commands
	@$(CC) $(LDFLAGS) $^ -o $@ 
#main target file(kvadratka) get files *.o to link and get main.exe(kvadratka)
#@ - mute output                    $@ - compilation target name

#PREPROCESSING + COMPILATION
onegin_o/%.o: onegin_cpps/%.cpp
	@$(CC) $(CFLAGS) $< -o $@
# make *.o file from current *.c file with ded_flags
# $< - first requisit $@ - compilation target name(EXECUTABLE)

clean:
	rm -rf onegin_o/*.o $(EXECUTABLE) 
# here rm -rf remove directories *.o in EXECUTABLE(kvadratka) and content in them and ignore non-existing files
#equals to rm -r -f