FILE = clothSim.cc genCoord.cc getLength.cc _C.cc _J.cc _JDOT.cc _CDOT.cc\
	setM.cc mult.cc multT.cc gaussSeidel.cc printMatrix.cc Tmult.cc\
	OpenGL.cc fit.cc conjGradient.cc

INC = -IC:/GLFW_64/include -IC:/GLEW/include -I include

LINK= -LC:/GLFW_64/lib-mingw-w64 -LC:/GLEW/lib/Release/x64

CFLAGS= -lglew32s -lglfw3 -lopengl32 -lglu32 -lgdi32

test: $(FILE)
	g++ $(FILE) $(INC) $(LINK) -o test $(CFLAGS)	
	
clean:
	rm -f *~
	rm -f include/*~ 	
	rm *.exe	