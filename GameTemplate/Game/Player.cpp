#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include "Gamecamera.h"

Player::Player()
{
	
	animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	animationClips[enAnimationClip_Run].Load("Assets/animData/run.tka");
	animationClips[enAnimationClip_Run].SetLoopFlag(true);

	modelRender.Init("Assets/modelData/unityChan.tkm", animationClips,
		enAnimationClip_Num, enModelUpAxisY);
	characterController.Init(25.0f, 75.0f, position);

}

Player::~Player()
{

}

void Player::Update()
{
	Move();

	Rotation();

	ManageState();

	PlayAnimation();

	modelRender.Update();

}


void Player::Move()
{
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;

	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	Vector3 forward = g_camera3D->GetForward();
	Vector3 right = g_camera3D->GetRight();

	forward.y = 0.0f;
	right.y = 0.0f;

	right *= stickL.x * 240.0f;
	forward *= stickL.y * 240.0f;

	moveSpeed += right + forward;

	if (g_pad[0]->IsPress(enButtonRB1))
	{
		moveSpeed += (right + forward) * 1.5f;
		
	}

	if (characterController.IsOnGround())
	{
		moveSpeed.y = 0.0f;
		if (g_pad[0]->IsTrigger(enButtonLB1))
		{
			playerState = 3;
			moveSpeed.y = 240.0f;
		}

	}
	else
	{
		moveSpeed.y -= 4.5f;
	}
	//moveSpeed.x += stickL.x * 120.0f;
	//moveSpeed.z += stickL.y * 120.0f;

	position = characterController.Execute(moveSpeed, 1.0f / 60.0f);
	
	modelRender.SetPosition(position);
}

void Player::Rotation()
{
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		rotation.SetRotationYFromDirectionXZ(moveSpeed);

		modelRender.SetRotation(rotation);
	}
}

void Player::ManageState()
{
	//地面に着いていなかったら
	if (characterController.IsOnGround() == false)
	{
		//ステートを1に
		playerState = 1;
		//処理を終了
		return;
	}


	//xz平面に動いていたら
	if (fabsf(moveSpeed.x) >= 0.001f || fabsf(moveSpeed.z) >= 0.001f)
	{
		//ステートを2にする
		playerState = 2;
	}

	//地面についている　かつ　xz平面に動いていない
	else
	{
		//ステートを0に
		playerState = 0;
	}
}

void Player::PlayAnimation()
{
	switch(playerState)
	{
	case 0:
		modelRender.PlayAnimation(enAnimationClip_Idle);
		break;
	case 1:
		modelRender.PlayAnimation(enAnimationClip_Jump);
		break;
	case 2:
		modelRender.PlayAnimation(enAnimationClip_Walk);
		break;
	case 3:
		modelRender.PlayAnimation(enAnimationClip_Run);
	}
}

void Player::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}