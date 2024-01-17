#pragma once

#include "sound/SoundSource.h"

class Player;
class BackGround;
class Game;

class Key : public IGameObject
{
public:
	Key();
	~Key();

	void Update();
	void Render(RenderContext& rc);

	Player* m_player;
	Game* game;
	SoundSource* gameSE;
	BackGround* backGround;
	ModelRender modelRender;
	Vector3 m_position;
	
};

