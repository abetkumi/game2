#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"

GameClear::GameClear()
{
	spriteRender.Init("Assets/sprite/GameClear.dds", 1920.0f,1080.0f);

	g_soundEngine->ResistWaveFileBank(4, "Assets/sound/GameClear.wav");
	gameclearBGM = NewGO<SoundSource>(4);
	gameclearBGM->Init(4);
	gameclearBGM->Play(true);
}

GameClear::~GameClear()
{
	DeleteGO(gameclearBGM);
}

void GameClear::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}
}

void GameClear::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}