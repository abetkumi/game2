#include "stdafx.h"
#include "mod1.h"

Mod1::Mod1()
{
	modelRender.Init("Assets/modelData/mod.tkm");
	modelRender.SetScale({ 1.3f,1.3f,1.3f });
	rot.SetRotationDegY(90.0f);

}

Mod1::~Mod1()
{

}

void Mod1::Update()
{
	modelRender.Update();
}

void Mod1::Render(RenderContext& rc)
{
	modelRender.SetPosition(m_position);
	modelRender.SetRotation(rot);
	modelRender.Draw(rc);
}