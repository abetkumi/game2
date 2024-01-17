#pragma once

#include "Level3DRender/LevelRender.h"
#include "sound/SoundSource.h"

class Player;
class GameCamera;
class Enemy;
class Mod1;
class BackGround;
class Mark;
class Stage1;
class Key;


class Game : public IGameObject
{
public:
	Game();
	//ä÷êîêÈåæ
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	GameCamera* gameCamera;
	BackGround* backGround;
	Stage1* stage1;
	Mark* mark;
	Player* m_player;
	Mod1* mod1;
	Enemy* enemy;
	FontRender fontRender;
	Vector3 position;
	SoundSource* gameBGM;
	ModelRender modelRender;
	Vector3 m_pos;
	LevelRender m_levelRender;
	SpriteRender spriteRender;
	//int ene = 0;

};

