#include "stdafx.h"
#include "BackGround.h"
#include "Player.h"
#include "Mod1.h"
#include "Mark.h"
#include "Key.h"
#include "Enemy.h"
#include "Game.h"

BackGround::BackGround()
{
	modelRender.Init("Assets/modelData/stage/stage2-1-8.tkm");
	//modelRender.Update();
	
	modelRender.SetScale(Vector3(0.3f,0.3f,0.3f));
	modelRender.Update();
	player = FindGO<Player>("player");

	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}


BackGround::~BackGround()
{

}

void BackGround::Update()
{

	modelRender.SetPosition(position);
}

void BackGround::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}