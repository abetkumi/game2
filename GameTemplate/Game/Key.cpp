#include "stdafx.h"
#include "key.h"
#include "Player.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

Key::Key()
{
	modelRender.Init("Assets/modelData/key.tkm");
	g_soundEngine->ResistWaveFileBank(1, "Assets/sound/sample.wav");
	modelRender.SetScale(Vector3(2.0f, 2.0f, 2.0f));
	player = FindGO<Player>("player");
}

Key::~Key()
{

}

void Key::Update()
{

	Move();

	Rotation();


	modelRender.Update();
	Vector3 diff = player->position - position;
	if (diff.Length() <= 120.0f)
	{
		SoundSource* se = NewGO<SoundSource>(0);
		se->Init(1);
		se->Play(false);
		se->SetVolume(3.5f);

		player->keyCount += 1;
		DeleteGO(this);
	}

}

void Key::Move()
{
	if (position.y >= firstPosition.y + 50.0f)
	{
		moveState = 1;
	}
	else if (position.y <= firstPosition.y - 50.0f)
	{
		moveState = 0;
	}
	if (moveState == 0)
	{
		position.y += 0.5f;
	}
	else if (moveState == 1)
	{
		position.y -= 0.5f;
	}
	modelRender.SetPosition(position);
}

void Key::Rotation()
{
	rotation.AddRotationDegY(2.0f);

	modelRender.SetRotation(rotation);
}

void Key::Render(RenderContext& rc)
{
	
	modelRender.Draw(rc);
}
