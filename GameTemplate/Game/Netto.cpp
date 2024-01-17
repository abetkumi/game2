#include "stdafx.h"
#include "Netto.h"
#include "Player.h"
#include "Game.h"

Netto::Netto()
{

}

Netto::~Netto()
{
	DeleteGO(gameSE);
}
bool Netto::Start()
{
	modelRender.Init("Assets/modelData/stage/netto.tkm");
	modelRender.SetPosition(m_position);
	modelRender.SetScale(m_scale);
	modelRender.SetRotation(m_rotation);
	player = FindGO<Player>("player");
	//modelRender.SetScale(Vector3(0.3f, 0.3f, 0.3f));
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());

	return true;
}

void Netto::Update()
{

	Vector3 dife = player->position - m_position;

	modelRender.SetPosition(m_position);
	modelRender.Update();

	if (player->keyCount == 1 && dife.Length() <= 180.0f)
	{
		if (g_pad[0]->IsPress(enButtonA))
		{
		
				DeleteGO(this);
				gameSE = NewGO<SoundSource>(11);
				gameSE->Init(11);
				gameSE->Play(false);
			player->keyCount = 0;
		}
	}
}

void Netto::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}