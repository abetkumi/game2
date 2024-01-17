#include "stdafx.h"
#include "Mark.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"

Mark::Mark()
{
	modelRender.Init("Assets/modelData/チェックマーク.tkm");
}

Mark::~Mark()
{

}

void Mark::Update()
{
	Move();

	Rotation();

	modelRender.Update();

}

void Mark::Move()
{
	if (moveState == 0)
	{
		m_position.y += 1.0f;
	}
	else if (moveState == 1)
	{
		m_position.y -= 1.0f;
	}

	if (m_position.y >= firstPosition.y+20.0f)
	{
		moveState = 1;
	}
	else if (m_position.y <= firstPosition.y-20.0f)
	{
		moveState = 0;
	}
	modelRender.SetPosition(m_position);
}

void Mark::Rotation()
{
	rotation.AddRotationDegY(2.0f);

	modelRender.SetRotation(rotation);
}



void Mark::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}