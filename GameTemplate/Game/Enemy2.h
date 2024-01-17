#pragma once

class Player;
class Game;

class Enemy2 : public IGameObject
{
public:
	Enemy2();
	~Enemy2();

	void Update();
	void Move();
	void Render(RenderContext& rc);
	void SetPosition(const Vector3& position);
	void Rotation();
	Enemy2* enemy2;
	Vector3 moveSpeed;
	Player* player;
	Game* game;
	//CharacterController characterController;
	ModelRender modelRender;
	//Quaternion rotation;
	Vector3 m_position;
	Vector3 firstPosition;
	Quaternion rotation;
};
