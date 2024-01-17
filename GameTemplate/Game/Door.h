#pragma once

#include "sound/SoundSource.h"

class Player;

class Door :public IGameObject
{
public:
	Door();
	~Door();
	bool Start();
	void Update();
	void Render(RenderContext& rc);

	Vector3 m_scale;
	Quaternion m_rotation;
	Vector3 m_position;
	SoundSource* gameSE;
	ModelRender modelRender;
	Player* player = nullptr;
	PhysicsStaticObject		physicsStaticObject;
};

