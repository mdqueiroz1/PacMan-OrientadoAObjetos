
COMPILADOR=g++

CFLAGS=-Wall

#Mapeamento de onde o Allegro está instalado
LDFLAGS=-L/usr/local/lib -lallegro `pkg-config --libs allegro-5 allegro_audio-5 allegro_dialog-5 allegro_image-5 allegro_memfile-5 allegro_primitives-5 allegro_acodec-5 allegro_color-5 allegro_font-5 allegro_main-5 allegro_physfs-5 allegro_ttf-5` 

#INCLUDE= Incluir todos os arquivos .h 
INCLUDE=-I/usr/local/include/allegro5 

#Codes= Incluir todos os arquivos .cpp
CODES=Main.cpp

#executavel do programa
EXE=pacman

all: projeto

clean:
	rm -rf *.o $(EXE)

projeto: $(CODES)
	$(COMPILADOR) $(CODES) -o $(EXE) $(INCLUDE) $(CFLAGS) $(LDFLAGS)


