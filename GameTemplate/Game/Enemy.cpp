#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "GameOver.h"
#include "Game.h"
#include "Mark.h"
#include "GameClear.h"

Enemy::Enemy()
{
	modelRender.Init("Assets/modelData/enemy2.tkm");

	modelRender.SetScale({ 1.2f,1.2f,1.2f});

	//プレイヤーのオブジェクトを引っ張ってくる
	player = FindGO<Player>("player");

	//ゲームのオブジェクトを引っ張ってくる
	game = FindGO<Game>("game");

	
}

Enemy::~Enemy()
{
	DeleteGO(mark2);
	DeleteGO(gameSE);
}

void Enemy::Update()
{
	Rotation();

	Move();

	if (player->a == 2 && player->keyCount == 1)
	{
		mark2 = NewGO<Mark>(0, "mark");
		mark2->m_position = { -6773.0f,-507.6f,-2630.8f };
		mark2->firstPosition = mark2->m_position;

		player->a = 3;
	}
	else if (player->a == 3 && player->keyCount == 1)
	{
		Vector3 dief = player->position - mark2->m_position;
		if (dief.Length() <= 150.0f && g_pad[0]->IsPress(enButtonA))
		{
			player->position = { 0.0f,0.0f,0.0f };
			player->modelRender.SetPosition(player->position);
			player->characterController.SetPosition(player->position);
			
			DeleteGO(mark2);
			DeleteGO(this);
			DeleteGO(game->gameBGM);
			game->gameBGM = NewGO<SoundSource>(0);
			game->gameBGM->Init(0);
			game->gameBGM->Play(true);
			gameSE = NewGO<SoundSource>(11);
			gameSE->Init(11);
			gameSE->Play(false);
			player->keyCount = 0;
		}
	}
	if (player->a == 4 && player->keyCount == 1)
	{
		mark2 = NewGO<Mark>(0, "mark");
		mark2->m_position = { -8108.0,100.0f,10899.0f };
		mark2->firstPosition = mark2->m_position;

		player->a = 5;
	}
	else if (player->a == 5 && player->keyCount == 0)
	{
		Vector3 dief = player->position - mark2->m_position;
		if (dief.Length() <= 150.0f && g_pad[0]->IsPress(enButtonA))
		{
			player->position = { 0.0f,0.0f,0.0f };
			player->modelRender.SetPosition(player->position);
			player->characterController.SetPosition(player->position);
			player->keyCount = 0;

			
			DeleteGO(this);
			NewGO<GameClear>(0, "gameClear");
			DeleteGO(game);
		}
	}
	Vector3 diff = m_position - player->position;
	if (diff.Length() <= 100.0f)
	{
		NewGO<GameOver>(0);
		//ゲームを削除する
		DeleteGO(game);
	}
	modelRender.Update();
}

void Enemy::Rotation()
{
	rotation.SetRotationYFromDirectionXZ(moveSpeed);

	modelRender.SetRotation(rotation);
}

void Enemy::Move()
{
	//position.Normalize();
	Vector3 v = player->position - m_position;
	v.Normalize();

	float distToPlayer = v.Length();
	if (distToPlayer < 500)
	{
		moveSpeed = v * 4.5f;
		m_position += moveSpeed;
		modelRender.SetPosition(m_position);
	}

	
}

void Enemy::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}