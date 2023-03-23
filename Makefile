CXX=g++
IDIR=./include
BDIR=./build
SDIR=./src
LDIR=./lib
SFINC=C:\Users\ANowa\Documents\SFML-2.5.1\include
SFLIB=C:\Users\ANowa\Documents\SFML-2.5.1\lib
COMPILEFLAGS=-I$(IDIR) -I$(SFINC) -DSFML_STATIC
LINKFLAGS=-L$(SFLIB) -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows
_DEPS=singleton.h gameManager.h windowManager.h IDamageable.h IPhysics.h IDrawable.h projectile.h entity.h weapon.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))
_OBJ=main.o singleton.o gameManager.o windowManager.o projectile.o entity.o weapon.o
OBJ=$(patsubst %,$(BDIR)/%,$(_OBJ))
$(BDIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(COMPILEFLAGS)
$(SDIR)/main: $(OBJ)
	$(CXX) -o $@ $^ $(LINKFLAGS)