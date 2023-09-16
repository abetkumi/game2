#pragma once

class Player;
class Game;

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
	//CharacterController characterController;
	ModelRender modelRender;
	//Quaternion rotation;
	Vector3 position;
	Vector3 firstPosition;
	Quaternion rotation;
};

