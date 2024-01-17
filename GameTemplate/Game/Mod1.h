#pragma once
class Mod1 : public IGameObject
{
public:
	Mod1(); ~Mod1();
	void Update();
	void Render(RenderContext& rc);
	Vector3 m_position;
	ModelRender modelRender;
	PhysicsStaticObject physicsStaticObject;
	Quaternion rot;
};

