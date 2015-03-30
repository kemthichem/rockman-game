#pragma once


#ifndef __SOUND_MANAGER_H__
#define __SOUND_MANAGER_H__

#include "SoundDev.h"
#include <vector>
using namespace std;

#pragma region define
#define SOUND_E_BOSS_FIRE 			"Resource/sound/e_boss_fire.wav"
#define SOUND_E_BOSS_HURT 			"Resource/sound/e_boss_hurt.wav"
#define SOUND_E_BOSS_BEFORE_DIE 	 "Resource/sound/e_boss_before_die.wav"
#define SOUND_E_BOSS_DIE 			"Resource/sound/e_boss_die.wav"
#define SOUND_B_OPTION_STATE 		"Resource/sound/b_option_state.wav"
#define SOUND_B_LOADING_STATE 		"Resource/sound/b_loading_state.wav"
#define SOUND_B_ABOUT_STATE 		"Resource/sound/b_about_state.wav"
#define SOUND_B_LOSE_STATE 			"Resource/sound/b_lose_state.wav"
#define SOUND_B_WIN_STATE 			"Resource/sound/b_win_state.wav"
#define SOUND_E_SLIDE 				"Resource/sound/e_slide.wav"
#define SOUND_E_PIPE 				"Resource/sound/e_pipe.wav"
#define SOUND_E_BRICK_UP 			"Resource/sound/e_brick_up.wav"
#define SOUND_E_TOUCH_TIRTLE 		"Resource/sound/e_touch_tirtle.wav"
#define SOUND_E_EAT 				"Resource/sound/e_eat.wav"
#define SOUND_E_UP 					"Resource/sound/e_up.wav"
#define SOUND_E_MUSH_DIE 			"Resource/sound/e_mush_die.wav"
#define SOUND_E_SHOT 				"Resource/sound/e_shot.wav"
#define SOUND_E_BROKEN 				"Resource/sound/e_broken.wav"
#define SOUND_E_WIN 				"Resource/sound/e_win.wav"
#define SOUND_E_DEATH_SHOT 			"Resource/sound/e_death_shot.wav"
#define SOUND_E_JUMP 				 "Resource/sound/e_jump.wav"
#define SOUND_E_DEATH 				 "Resource/sound/e_death.wav"
#define SOUND_E_PAUSE 				 "Resource/sound/e_pause.wav"
#define SOUND_E_BULLETEX				 "Resource/sound/e_bulletex.wav"

#define SOUND_E_GROW 	 "Resource/sound/e_grow.wav"
#define SOUND_E_COIN 	 "Resource/sound/e_coin.wav"
#define SOUND_E_1UP 	 "Resource/sound/e_1up.wav"
#define SOUND_E_CLICK 	 "Resource/sound/e_click.wav"
#define SOUND_B_GAME2 	 "Resource/sound/b_game2.wav"
#define SOUND_B_GAME1 	 "Resource/sound/b_game1.wav"
#define SOUND_B_MENU 	 "Resource/sound/b_menu.wav"
#pragma endregion define

class SoundManager
{
private:
	DSound* SDev;
	vector<CSound*> _listEffSound;
	vector<CSound*> _listBgSound;

	SoundManager();

	static SoundManager* _instance;

public:

	static SoundManager* GetInst();
	
	~SoundManager();
	
	void PlayBgSound(char* SOUND_FILE_PATH, bool isLoop = true, bool wantPlayAgain = false);

	void PlayEffSound(char* SOUND_FILE_PATH, bool isLoop = false,bool wantPlayAgain = true);

	bool IsSoundEffPlaying(char *SOUND_FILE_PATH);

	void StopBgSound(char* SOUND_FILE_PATH);

	void StopEffSound(char* SOUND_FILE_PATH);

	void StopAllBgSound();

	void StopAllEffSound();
};

#endif //__SOUND_MANAGER_H__