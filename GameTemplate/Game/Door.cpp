 #include "stdafx.h"
#include "Door.h"
#include "Player.h"
#include "Game.h"

Door::Door()
{
	
}

Door::~Door()
{
	
}
bool Door::Start()
{
	modelRender.Init("Assets/modelData/stage/Door.tkm");
	modelRender.SetPosition(m_position);
	modelRender.SetScale(m_scale);
	modelRender.SetRotation(m_rotation);
	player = FindGO<Player>("player");
	modelRender.SetScale(Vector3(0.8f, 0.8f, 0.8f));
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());

	return true;
}

void Door::Update()
{

	Vector3 dife = player->position - m_position;
	
	modelRender.SetPosition(m_position);
	modelRender.Update();

	if (player->keyCount == 1 && dife.Length() <= 180.0f)
	{
		if (g_pad[0]->IsPress(enButtonA))
		{
			g_soundEngine->ResistWaveFileBank(11, "Assets/sound/Key open.wav");
			gameSE = NewGO<SoundSource>(11);
			gameSE->Init(11);
			gameSE->Play(false);
			const auto& doors = FindGOs<Door>("door");
			for (auto door : doors)
			{
				DeleteGO(door);
			}
			player->keyCount = 0;
		}
	}
}

void Door::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}