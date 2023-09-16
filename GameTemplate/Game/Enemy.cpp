#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "GameOver.h"
#include "Game.h"

Enemy::Enemy()
{
	modelRender.Init("Assets/modelData/enemy2.tkm");

	modelRender.SetScale({ 0.8f,0.8f,0.8f});

	//�v���C���[�̃I�u�W�F�N�g�����������Ă���
	player = FindGO<Player>("player");

	//�Q�[���̃I�u�W�F�N�g�����������Ă���
	game = FindGO<Game>("game");
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
	Rotation();

	Move();
	Vector3 diff = position - player->position;
	if (diff.Length() <= 30.0f)
	{
		NewGO<GameOver>(0);
		//�Q�[�����폜����
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
	Vector3 v = player->position - position;
	v.Normalize();
	moveSpeed = v * 3.5f;
	position += moveSpeed;
	modelRender.SetPosition(position);
}

void Enemy::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}