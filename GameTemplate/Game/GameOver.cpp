#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"
#include "Game.h"
#include "sound/SoundEngine.h"

GameOver::GameOver()
{
	g_soundEngine->ResistWaveFileBank(3, "Assets/sound/GameOver.wav");
	spriteRender.Init("Assets/sprite/GameOver3.dds", 1920.0f, 1080.0f);
	gameoverBGM = NewGO<SoundSource>(3);
	gameoverBGM->Init(3);
	gameoverBGM->Play(true);
}

GameOver::~GameOver()
{
	DeleteGO(gameoverBGM);
}

void GameOver::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}
}

void GameOver::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}