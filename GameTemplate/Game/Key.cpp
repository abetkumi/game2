#include "stdafx.h"
#include "Key.h"
#include "Player.h"
#include "Game.h"

Key::Key()
{

	modelRender.Init("Assets/modelData/key.tkm");

	m_player = FindGO<Player>("player");
	//game = FindGO<Game>("game");
}

Key::~Key()
{
	DeleteGO(gameSE);
}

void Key::Update()
{
	if (m_player == nullptr) {
		return;
	}
	modelRender.SetPosition(m_position);
	Vector3 dif = m_player->position - m_position;
	if (dif.Length() <= 120.0f && g_pad[0]->IsTrigger(enButtonA))
	{
		m_player->a++;
		m_player->keyCount += 1;
		m_player->ene++;
		g_soundEngine->ResistWaveFileBank(10, "Assets/sound/Key pick.wav");
		gameSE = NewGO<SoundSource>(10);
		gameSE->Init(10);
		gameSE->Play(false);
		DeleteGO(this);
	}
	modelRender.Update();
}

void Key::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}