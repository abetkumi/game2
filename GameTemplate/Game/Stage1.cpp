#include "stdafx.h"
#include "Stage1.h"
#include "BackGround.h"
#include "Game.h"
#include "Player.h"
#include "Mark.h"
#include "GameClear.h"
#include "Enemy.h"


Stage1::Stage1()
{
	
}

Stage1::~Stage1()
{
	DeleteGO(mark3);
}

bool Stage1::Start()
{
	m_modelRender.Init("Assets/modelData/stage/stage2-2-3.tkm");

	m_modelRender.SetScale(Vector3(10.0f,10.0f,10.0f));
	m_modelRender.SetPosition(m_position);
	m_modelRender.Update();
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
	m_player = FindGO<Player>("player");

	return true;
}

void Stage1::Update()
{

	m_modelRender.SetPosition(m_position);

	m_modelRender.Update();
}

void Stage1::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}