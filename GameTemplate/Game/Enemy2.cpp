#include "stdafx.h"
#include "Enemy2.h"
#include "Player.h"
#include "GameOver.h"
#include "Game.h"

Enemy2::Enemy2()
{
	modelRender.Init("Assets/modelData/MushroomMan/MushroomMan.tkm");

	modelRender.SetScale({ 0.8f,0.8f,0.8f });

	//プレイヤーのオブジェクトを引っ張ってくる
	player = FindGO<Player>("player");

	//ゲームのオブジェクトを引っ張ってくる
	game = FindGO<Game>("game");


}

Enemy2::~Enemy2()
{

}

void Enemy2::Update()
{
	Rotation();

	Move();
	Vector3 diff = m_position - player->position;
	if (diff.Length() <= 30.0f)
	{
		NewGO<GameOver>(0);
		//ゲームを削除する
		DeleteGO(game);
	}
	modelRender.Update();
}

void Enemy2::Rotation()
{
	rotation.SetRotationYFromDirectionXZ(moveSpeed);

	modelRender.SetRotation(rotation);
}

void Enemy2::Move()
{
	//position.Normalize();
	Vector3 v = player->position - m_position;
	v.Normalize();

	float distToPlayer = v.Length();
	if (distToPlayer < 500)
	{
		moveSpeed = v * 3.5f;
		m_position += moveSpeed;
		modelRender.SetPosition(m_position);
	}


}

void Enemy2::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}