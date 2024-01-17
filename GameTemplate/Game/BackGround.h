#pragma once
class Player;
class Stage1;
//class Mark;
class Mod1;
class Enemy;
class Game;

class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();

	PhysicsStaticObject physicsStaticObject;
	//void SetPosition(const Vector3& position);
	//void SetScale(const Vector3& scale);
	void Render(RenderContext& rc);
	Vector3 position;
	void Update();
	Mod1* mod1;
	//Mark* mark;
	Player* player;
	//Mark* mark2;
	Enemy* enemy;
	Game* game;
	//Vector3 m_scale;
	BackGround* backGround;
	ModelRender modelRender;
};

