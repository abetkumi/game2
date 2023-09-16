#pragma once
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();

	PhysicsStaticObject physicsStaticObject;

	void Render(RenderContext& rc);

	ModelRender modelRender;
};

