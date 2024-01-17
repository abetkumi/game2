#pragma once

class Player;
class GameCamera;

class Mark : public IGameObject
{
public:
	Mark();
	~Mark();
	
	void Render(RenderContext& rc);
	void Move();
	void Rotation();
	void Update();
	Player* player;
	GameCamera* gameCamera;
	ModelRender modelRender;
	Vector3 m_position;
	int moveState = 0;
	Vector3 firstPosition;
	Quaternion rotation;
	int markState = 0;
};

