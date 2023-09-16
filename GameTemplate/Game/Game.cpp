#include "stdafx.h"
#include "Game.h"
#include "Title.h"
#include "BackGround.h"
#include "Player.h"
#include "Gamecamera.h"
#include "Enemy.h"
#include "GameOver.h"
#include "Key.h"
#include "GameClear.h"
#include "sound/SoundEngine.h"

bool Game::Start()
{


	player = NewGO<Player>(0, "player");
	gameCamera = NewGO<GameCamera> (0, "gamecamera");
	backGround = NewGO<BackGround>(0, "background");
	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/Game.wav");
	gameBGM = NewGO<SoundSource>(0);
	gameBGM-> Init(0);
	gameBGM->Play(true);

	fontRender.SetPosition({ -680.0f,-380.0f,0.0f });
	fontRender.SetColor(g_vec4White);
	fontRender.SetScale(2);
	key1 = NewGO<Key>(0, "key");
	key1->position = { -2247.0f,15.0f,-1030.0f };
	key1->firstPosition = key1->position;
	key2 = NewGO<Key>(0, "key");
	key2->position = { 2932.0f,68.0f,-918.0f };
	key2->firstPosition = key2->position;
	key3 = NewGO<Key>(0, "key");
	key3->position = { -2225.0f,135.0f,398.0f };
	key3->firstPosition = key3->position;
	key4 = NewGO<Key>(0, "key");
	key4->position = { 1760.0f,276.0f,-611.0f };
	key4->firstPosition = key4->position;
	key5 = NewGO<Key>(0, "key");
	key5->position = { 2508.0f,1280.0f,1829.0f };
	key5->firstPosition = key5->position;

	enemy = NewGO<Enemy>(0,"enemy");
	enemy->position = { 2700.0f,450.0f,400.0f };
	enemy->firstPosition = enemy->position;


	g_renderingEngine->SetDirectionLight(0, Vector3(0.2f, -0.7f, 0.2f), Vector3(0.2f, 0.2f, 0.2f));
	g_renderingEngine->SetAmbient(Vector3(0.0007f, 0.0007f, 0.0007f));

	return true;
}

Game::~Game()
{
	//BGM�t��������s����
	DeleteGO(player);
	DeleteGO(gameCamera);
	DeleteGO(backGround);
	DeleteGO(gameBGM);
	DeleteGO(enemy);
	DeleteGO(key1);
	DeleteGO(key2);
	DeleteGO(key3);
	DeleteGO(key4);
	DeleteGO(key5);
}

void Game::Update()
{
	int number;
	char moji;
	if (player->keyCount == 5)
	{
		NewGO<GameClear>(0);
		DeleteGO(this);
	}
	//文字列
	wchar_t numStr[256];
	//キーの数
	int num = 1;
	num = player->keyCount;

	//数値から文字列の変換
	swprintf_s(numStr, L"%d/5", num);

	fontRender.SetText(numStr);
	
	m_modelRender.Update();
}

void Game::Render(RenderContext& rc)
{
	fontRender.Draw(rc);
}