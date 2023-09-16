#pragma once

class Player;
class Key : public IGameObject
{
public:
	Key();
	~Key();
	void Update();
	void Render(RenderContext& rc);
	void Move();
	void Rotation();
	Player* player;
	Quaternion rotation;
	ModelRender modelRender;
	Vector3 position;
	Vector3 firstPosition;
	int moveState = 0;
};

