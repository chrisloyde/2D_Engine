#pragma once
/*

Interface for Texture implementation.

*/

#include <string>
#include <SDL_render.h>
#include <SDL_ttf.h>

class ITexture {
public:
	virtual ~ITexture() {};

	/* loadFromFile
	Loads an image from file using SDL library.
	Param: SDL_Renderer, String path to image.
	Returns: bool representing if load was successful or not
	*/
	virtual bool loadFromFile(SDL_Renderer *renderer, std::string path) = 0;
	
	/* render
	Renders a texture at position. Generally the texture class would have texture stored.
	Param: SDL_Renderer, x position on screen, y position on screen.
	*/
	virtual void render(SDL_Renderer *renderer, int posX, int posY) = 0;

	/* loadFromRenderedText
	Create an image from text and load it into the stored texture.
	Param: SDL_Renderer, text to render, font to draw text, color for text.
	Returns: bool representing if load was successful or not.
	*/
	virtual bool loadFromRenderedText(SDL_Renderer *renderer, std::string text, TTF_Font *font, SDL_Color color) = 0;

protected:
	SDL_Texture *loadedTexture;
};
