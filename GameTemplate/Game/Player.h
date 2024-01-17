#pragma once

class Mark;
class GameCamera;
class Key;

class Player : public IGameObject
{
public:
	Player();
		~Player();

		void Update();
		void Render(RenderContext& rc);
		void Move();
		void Rotation();
		void ManageState();
		void PlayAnimation();
		void Warp();
		ModelRender modelRender;
		Vector3 position;
		enum EnAnimationClip
		{
			enAnimationClip_Idle,
			enAnimationClip_Walk,
			enAnimationClip_Jump,
			enAnimationClip_Run,
			enAnimationClip_Num,
			
		};
		AnimationClip animationClips[enAnimationClip_Num];
		CharacterController characterController;
		SpriteRender spriteRender;
		Vector3 moveSpeed;
		Quaternion rotation;
		Vector3 m_scale;
		Mark* mark;
		GameCamera* gameCamera;
		int playerState = 0;
		int keyCount = 0;
		//int warpState = 0;
		int i = 1;
		int a = 0;
		int ene = 0;
};

