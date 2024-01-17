#pragma once

#include "sound/SoundSource.h"

class Player;
class Game;
class Mark;

class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
	
	void Update();
	void Move();
	void Render(RenderContext& rc);
	void SetPosition(const Vector3& position);
	void Rotation();
	Enemy* enemy;
	Vector3 moveSpeed;
	Player* player;
	Game* game;
	Mark* mark2;
	SoundSource* gameSE;
	//CharacterController characterController;
	ModelRender modelRender;
	//Quaternion rotation;
	Vector3 m_position;
	Vector3 firstPosition;
	Quaternion rotation;
};

