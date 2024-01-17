#include "stdafx.h"
#include "Game.h"
#include "Title.h"
#include "BackGround.h"
#include "Player.h"
#include "Gamecamera.h"
#include "Enemy.h"
#include "GameOver.h"
#include "GameClear.h"
#include "sound/SoundEngine.h"
#include "Mod1.h"
#include "Mark.h"
#include "Key.h"
#include "Door.h"
#include "Stage1.h"
#include "Netto.h"

bool Game::Start()
{
	return true;
}

Game::Game()
{
	Mark* mark1 = NewGO<Mark>(0, "mark");
	mark1->m_position = { -206.2f,150.6f,493.6f };
	mark1->firstPosition = mark1->m_position;
	
	m_player = NewGO<Player>(0, "player");

	spriteRender.Init("Assets/sprite/Key.dds", 350.0f, 300.0f);

	gameCamera = NewGO<GameCamera>(0, "gamecamera");

	g_soundEngine->ResistWaveFileBank(0, "Assets/sound/Game.wav");
	gameBGM = NewGO<SoundSource>(0);
	gameBGM->Init(0);
	gameBGM->Play(true);

	m_player = FindGO<Player>("player");

	Mod1* mod1 = NewGO<Mod1>(0, "mod1");
	mod1->m_position = { -156.0f,29.0f,0.0f };

	Key* key1 = NewGO<Key>(0, "key");
	key1->m_position = { -7683.0f,-605.0f,1148.0f };
	//key1->m_position = { -6073.0f,-4.6f,9560.8f };
	Key* key2 = NewGO<Key>(0, "key");
	key2->m_position = { -7787.0f,580.0f,-2726.0f };
	Key* key3 = NewGO<Key>(0, "key");
	key3->m_position = { -3430.0f,0.2f,8853.0f };

	//modelRender.SetPosition(position);

	m_levelRender.Init("Assets/level3D/level2.tkl", [&](LevelObjectData& objData)
		{
			if (objData.EqualObjectName(L"door") == true)
			{
				Door* door = NewGO<Door>(0, "door");
				door->m_position = objData.position;
				door->m_scale = objData.scale;
				door->m_rotation = objData.rotation;
				return true;
			}

			else if (objData.EqualObjectName(L"stage") == true) {
				//背景オブジェクトを作成する。
				backGround = NewGO<BackGround>(0, "background");
				//座標を設定する。
				backGround->position = objData.position;
				//大きさを設定する。
				//backGround->m_scale = objData.scale;

				return true;
			}

			else if (objData.EqualObjectName(L"stage1") == true) {
				//背景オブジェクトを作成する。
				stage1 = NewGO<Stage1>(0, "stage1");
				//座標を設定する。
				stage1->SetPosition(objData.position);
				//大きさを設定する。
				//stage1->SetScale(objData.scale);

				return true;
			}
			else if (objData.EqualObjectName(L"netto") == true) {
				//背景オブジェクトを作成する。
				Netto* netto = NewGO<Netto>(0, "netto");
				//座標を設定する。
				netto->m_position = objData.position;
				//大きさを設定する。
				netto->m_scale = objData.scale;
				netto->m_rotation = objData.rotation;

				return true;
			}
			return true;
		});

	g_renderingEngine->SetDirectionLight(0, Vector3(0.2f, -0.7f, 0.2f), Vector3(0.2f, 0.2f, 0.2f));
	g_renderingEngine->SetAmbient(Vector3(0.0007f, 0.0007f, 0.0007f));
}

Game::~Game()
{

	DeleteGO(gameCamera);
	DeleteGO(backGround);
	DeleteGO(mod1);
	DeleteGO(gameBGM);
	DeleteGO(enemy);
	DeleteGO(stage1);
	DeleteGO(m_player);
	DeleteGO(mark);
	
	QueryGOs<Key>("key", [&](Key* key) {
		DeleteGO(key);
		return true;
	});

	const auto& doors = FindGOs<Door>("door");
	for (auto door : doors)
	{
		DeleteGO(door);
	}
	const auto& nettos = FindGOs<Netto>("netto");
	for (auto netto : nettos)
	{
		DeleteGO(netto);
	}
}

void Game::Update()
{

	if (m_player->keyCount == 1)
	{
	
		position.x = -900.0f;
		position.y = -350.0f;
		spriteRender.SetPosition(position);
		
		spriteRender.Update();
		
			if (m_player->ene == 1)
			{
				enemy = NewGO<Enemy>(0, "enemy");
				enemy->m_position = { -6773.0f,-557.6f,-2630.8f };
				m_player->ene++;
				DeleteGO(gameBGM);
				g_soundEngine->ResistWaveFileBank(1, "Assets/sound/Game2.wav");
				gameBGM = NewGO<SoundSource>(1);
				gameBGM->Init(1);
				gameBGM->Play(true);
			}
	
			if (m_player->ene == 4)
			{
				enemy = NewGO<Enemy>(0, "enemy");
				enemy->m_position = { -8108.0,100.0f,10899.0f };
				m_player->ene++;
				DeleteGO(gameBGM);
				
				gameBGM = NewGO<SoundSource>(1);
				gameBGM->Init(1);
				gameBGM->Play(true);
			}
		
		//enemy->firstPosition = enemy->m_position;
	}

	modelRender.Update();
}

void Game::Render(RenderContext& rc)
{
	if (m_player->keyCount == 1)
	{
		spriteRender.Draw(rc);
	}
	m_levelRender.Draw(rc);
	fontRender.Draw(rc);
}