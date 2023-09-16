#pragma once

#include "Level3DRender/LevelRender.h"
#include "sound/SoundSource.h"

class Player;
class GameCamera;
class BackGround;
class Enemy;
class Key;

class Game : public IGameObject
{
public:
	Game() {}
	//ä÷êîêÈåæ
	~Game();
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	GameCamera* gameCamera;
	BackGround* backGround;
	Player* player;
	Enemy* enemy;
	FontRender fontRender;
	Vector3 position;
	int keyCount;
	SoundSource* gameBGM;
private:
	ModelRender m_modelRender;
	Vector3 m_pos;
	Key* key1;
	Key* key2;
	Key* key3;
	Key* key4;
	Key* key5;
};

