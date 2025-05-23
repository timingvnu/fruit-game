#pragma once

#include "config/buff_data.h"
#include "game/game.h"
#include "entities/entity.h"
#include "utils/math.h"

class Enemy: public Entity
{
public:
	int score = 1;
	int hp = 100;

	const char* soundHit = nullptr;
	BuffConfig* buff = nullptr;
	SDL_Color deathParticleColor = { 255, 255, 255, 255 };

	Enemy(vec2_t position, vec2_t direction) : Entity(EntityType::ENEMY, position, direction) {};
	Enemy(vec2_t position, float speed, float angle) : Entity(EntityType::ENEMY, position, speed, angle) {};

	void onTick(int deltaTicks) override;
	void onRender() override;
	void onDespawn(EntityDeathType type) override;
	void onHit() override;
};