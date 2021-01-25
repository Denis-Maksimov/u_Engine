

CFLAGS += -I${PWD}/u_stdlib 
CFLAGS += -I${PWD}/engine 
CFLAGS += -I${PWD}/u_stdlib/u_stdlib 
CPPFLAGS += ${CFLAGS}
export CFLAGS


main: main.o u_stdlib/libu_std.a engine/libEngine.a 
	g++ $^ -lglut -lGLU -lGL -Lu_stdlib -Lengine -lu_std -lEngine


u_stdlib/libu_std.a:
	${MAKE} -C u_stdlib

engine/libEngine.a:
	${MAKE} -C engine


clean:
	${MAKE} -C engine clean
	${MAKE} -C u_stdlib clean
	