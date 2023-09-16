#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Player.h"
#include "sound/SoundEngine.h"

Title::Title()
{
	spriteRender.Init("Assets/sprite/GameTitle2.dds",1920.0f,1080.0f);
	
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/Title.wav");
	titleBGM = NewGO<SoundSource>(2);
	titleBGM->Init(2);
	titleBGM->Play(true);
}

Title::~Title()
{
	DeleteGO(titleBGM);
}

void Title::Update()
{
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0,"game");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	spriteRender.Draw(rc);
}