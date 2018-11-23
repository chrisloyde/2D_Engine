
#include "Texture.h"
// Construct Texture Object
Texture::Texture() {
    hTexture = nullptr;
    width = 0;
    height = 0;
}
// Free memory from texture object.
Texture::~Texture() {
    free();
}
bool Texture::loadFromFile(SDL_Renderer *renderer, std::string path) {
    // free any texture already loaded
    free();

    std::cout << "Loading " << path;

    SDL_Texture *newTexture = nullptr; // final texture
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image for texture: " << path.c_str() << "! SDL_Image Error: " << IMG_GetError() << std::endl;
    } else {
        // Color Key Image (Cyan is chroma keyed; red 0, green 255, blue 255
        SDL_SetColorKey(loadedSurface,SDL_TRUE,SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == nullptr) {
            std::cerr << "Unable to create texture from " << path.c_str() << "! SDL Error" << SDL_GetError() << std::endl;
        } else {
            //Get Image Dimmensions
            width = loadedSurface->w;
            height = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface); // loadedSurface no longer required
    }
    hTexture = newTexture;

    std::cout << " : Finished" << std::endl;
    return hTexture != nullptr;
}
bool Texture::loadFromRenderedText(SDL_Renderer *renderer, std::string textureText, TTF_Font *font, SDL_Color textColor) {
    free();
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
    if (textSurface != nullptr) {
        hTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        if (hTexture == nullptr) {
            std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
        }
        else {
            width = textSurface -> w;
            height = textSurface->h;
        }
        SDL_FreeSurface(textSurface);
    }
    else {
        std::cerr << "Unable to render text surface! SDL_ttf Error " << TTF_GetError() << std::endl;
    }
    return (hTexture != nullptr);
}
void Texture::free() {
    // Free texture if it exists
    if (hTexture != nullptr) {
        SDL_DestroyTexture(hTexture);
        hTexture = nullptr;
        width = 0;
        height = 0;
    }
}

// clip represents how the sprite will be clipped from the image,
// leave null if the whole image is to be rendered.
// if a sprite sheet is being rendered then use clip as the coordinates of
// the rectangle containing the sprite.
void Texture::render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip) {
    // Set rendering space and render to screen
    SDL_Rect renderQuad = {x,y,width,height};
    if (clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    // render to screen
    SDL_RenderCopy(renderer, hTexture, clip, &renderQuad);
}

int Texture::getWidth() { return width;}
int Texture::getHeight() { return height;}