#pragma once

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
		Vector3 moveSpeed;
		Quaternion rotation;
		Player* player;
		int playerState = 0;
		int keyCount = 0;
};

