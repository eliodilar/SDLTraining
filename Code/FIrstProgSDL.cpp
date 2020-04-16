#include <SDL2/SDL.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>


using namespace std;

int main(int argc, char **argv)
{	
    // Notre fenêtre
	
    SDL_Window* fenetre(0);         //sdl2 window pointer
    SDL_Event evenements;           //sdl2 event end var bool
    bool terminer(false);           //sdl2 event end var bool
    SDL_GLContext contexteOpenGL; //create an opengl context utilisation of sdl2
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    //sdl double buffer size ( x,y)
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); //double buffer activation (1)
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    contexteOpenGL = SDL_GL_CreateContext(fenetre); //give an opengl context to sdl window

    // Initialisation de la SDL
	
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();
		
        return -1;
    }
    else
    {

        cout<< "SDL initialise"<<endl;

    }
	
	
    // Création de la fenêtre
	
    fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if(fenetre == 0)
    {
    std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
    SDL_Quit();

    return -1;
    }   
    else
    {

        cout<< "SDL Window create"<<endl;

    }

    // Création du contexte OpenGL

contexteOpenGL = SDL_GL_CreateContext(fenetre);

if(contexteOpenGL == 0)
{
    std::cout << SDL_GetError() << std::endl;
    SDL_DestroyWindow(fenetre);
    SDL_Quit();

    return -1;
}
else
{
    cout<< "OpenGl context create on SDL2 window"<<endl;

}

   // Boucle principale de fonctionement sdl2

    while(!terminer)
    {
	    SDL_WaitEvent(&evenements);

	    if(evenements.window.event == SDL_WINDOWEVENT_CLOSE )
        {
	        terminer = true;
            cout<<"SDL2 End event call"<<endl;
        }
    }
	
	
    // On quitte la SDL
    sleep(2); //wait 2 sec

    SDL_GL_DeleteContext(contexteOpenGL); //destroy the openGL context of the sdl2 window
     cout<<"OpenGl context destroy"<<endl;

    SDL_DestroyWindow(fenetre);             //destroy the sdl2 window
    cout<<"SDL2 window destroy"<<endl;

    SDL_Quit();
    cout<<"SDL2 lib exit"<<endl;

	
    return 0;
}