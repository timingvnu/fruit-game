#pragma once

#include "audio/audio_mgr.h"
#include "render.h"
#include "scene/elements/basic_element.h"

#include <functional>

class ButtonElement : public Element
{
private:
	GameTexture* texture = nullptr;
public:
	const char* text;
	const char* fontId;
	int size;
	SDL_Color color;
	int outlineSize;
	SDL_Color outlineColor;
	int boxPadding;

	std::function<void(ButtonElement* button)> onClick = nullptr;

	ButtonElement(const char* id, vec2_t position, const char* text, const char* fontId, const int size, const SDL_Color color, std::function<void (ButtonElement* button)> onClick, const int outlineSize = 0, const SDL_Color outlineColor = { 0, 0, 0, 255 }, const int boxPadding = 0);

	void Prepare() override;
	void Render() override;
	void OnHoveredRender() override;
	void Release() override;
	void OnMouseClick(SDL_MouseButtonEvent& e) override;
	bool IsHovered() override;
};