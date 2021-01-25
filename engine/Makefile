
# не использовать напрямую! #

OBJS= \
engine.o \
render/render.o \
kb/keyboard.o 
.PHONY: all clean
all: libEngine.a

libEngine.a: $(OBJS)
	ar crs $@ $^

clean:
	rm -f $(OBJ) libEngine.a