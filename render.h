#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

#include "alignment.h"
#include "mouse_record/mouse_path.h"
#include "task/task.h"
#include "task/types/timer_task.h"
#include "textures.h"

#include <functional>
#include <filesystem>
#include <string>
#include <unordered_map>

namespace fs = std::filesystem;

class Renderer {
private:
	static Renderer* instancePtr;
public:

	SDL_Window* gWindow = nullptr;
	SDL_Renderer* gRenderer = nullptr;

	std::unordered_map<const char*, TTF_Font*> fonts;
	std::unordered_map<const char*, GameTexture*> textures;

	void Initialize();

	static Renderer* GetInstance() {
		return instancePtr;
	}

	void PreRender();
	void UpdateRender();

	//this function needs to go
	void PlayFadeTransition(std::function<void(TimerTask* self)> onTransitioned, std::function<void(TimerTask* self)> onComplete);

	bool LoadFontByName(const char* name);
	bool LoadTextureByName(const char* name);

	void FreeGameTexture(GameTexture* texture);

	TTF_Font* GetFontByName(const char* name);
	GameTexture* GetTextureByName(const char* name);

	GameTexture* CreateText(const char* text, const char* fontId, const int size, const SDL_Color color, const int outlineSize = 0, const SDL_Color outlineColor = { 0, 0, 0, 0xff });

	void RenderTextureBackground(const char* textureId, int opacity = 255);
	void SetBackgroundColor(const int r, const int g, const int b, const int a);

	void RenderTexture(const char* textureId, int x, int y, const Alignment align = Alignment::LEFT, const AlignmentVertical alignmentVertical = AlignmentVertical::TOP);
	void RenderTexture(GameTexture* texture, int x, int y, const Alignment align = Alignment::LEFT, const AlignmentVertical alignmentVertical = AlignmentVertical::TOP);
};