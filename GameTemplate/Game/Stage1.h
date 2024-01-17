#pragma once

class Game;
class Player;
class Mark;
class Enemy;

class Stage1:public IGameObject
{
public:
	Stage1();
	~Stage1();

	void SetPosition(const Vector3& position)
	{
		m_position = position;
	}
	/// <summary>
	/// ëÂÇ´Ç≥Çê›íË
	/// </summary>
	/// <param name="scale">ëÂÇ´Ç≥</param>
	void SetScale(const Vector3& scale)
	{
		m_scale = scale;
	}
	bool Start();
	void Update();
	void Render(RenderContext& rc);
	Game*					game;
	Player*					m_player;
	Mark*					mark3;
	Enemy*					enemy;

private:
	Vector3					m_position;					//
	Vector3					m_scale;					//

	ModelRender				m_modelRender;				//
	PhysicsStaticObject		m_physicsStaticObject;		//
};

