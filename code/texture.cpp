#include "texture.h"

Texture::Texture(){
	SDLtex = nullptr;
}
Texture::~Texture(){ free(); }

void Texture::free() {
	if (SDLtex != NULL) {
		SDL_DestroyTexture(SDLtex);
		SDLtex = NULL;
		width = 0;
		height = 0;
	}
}

bool Texture::load(const std::string &path) {
	free();
	SDL_Texture *newTexture = nullptr;
	SDL_Surface *loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr){
		printf("failed to load surface in Texture::load function path: %s\n", path.c_str());
	} else {
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
		newTexture = SDL_CreateTextureFromSurface(SDL_graphics::renderer, loadedSurface);
		if (newTexture == nullptr) {
			printf("failed to load newTexture in Texture::load function path %s\n", path.c_str());
		} else {
			width = loadedSurface->w;
			height = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
	}
	SDLtex = newTexture;

	return SDLtex != nullptr;
}

bool Texture::load(TTF_Font *font, std::string text, SDL_Color text_color) {
	free();
	SDL_Surface *textSurface = TTF_RenderText_Solid(font, text.c_str(), text_color);
	if (textSurface != NULL) {
		SDLtex = SDL_CreateTextureFromSurface(SDL_graphics::renderer, textSurface);
		if (SDLtex == NULL) {
			printf("SDL Failed to Create Texture from text! ERROR: %s. \n", SDL_GetError());
		}
		else {
			width = textSurface->w;
			height = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	} else {
		printf("SDL Failed to Render Texture from text! ERROR: %s. \n", TTF_GetError());
	}

	return SDLtex != NULL;
}

void Texture::draw(int x, int y, SDL_Rect *src_clip, SDL_Rect *dst_rect, double angle, SDL_Point *center, SDL_RendererFlip render_flip) {
	SDL_Rect srcClip = {0, 0, width, height};
	if (src_clip != nullptr) {
		srcClip.x = src_clip->x;
		srcClip.y = src_clip->y;
		srcClip.w = src_clip->w;
		srcClip.h = src_clip->h;
	}
	SDL_Rect renderQuad = {x, y, width, height};
	if (dst_rect != nullptr) {
		renderQuad.w = dst_rect->w;
		renderQuad.h = dst_rect->h;
	}
	SDL_RenderCopyEx(SDL_graphics::renderer, SDLtex, &srcClip, &renderQuad, angle, center, render_flip);
}

void Texture::draw(SDL_Rect *destination) {
	SDL_RenderCopy(SDL_graphics::renderer, SDLtex, nullptr, destination);
}

void Texture::drawWithWidthClamp(const int &clamp_width, int x = 0, int y = 0) {
	if (width > clamp_width) {
		SDL_Rect *tmprect = {0,0,0,0};
		tmprect.x = x;
		tmprect.y = y;
		tmprect.h = height;
		tmprect.w = clamp_width;
		this->draw(tmprect);
	} else {
		this->draw(x, y);
	}
}
