#ifndef RESOURCE_CONFIG_H
#define RESOURCE_CONFIG_H

enum KEY
{
	KEY_RM_TIME_INJUNRED = 0,
	KEY_RM_TIME_SHOT,
	KEY_RM_VY_JUMP,
	KEY_RM_ACCEL_VX,
	KEY_RM_ACCEL_VY,
	KEY_RM_ACCEL_STOP,
	KEY_RM_MAX_VX,
	KEY_RM_VX_PREPARE,
	KEY_RM_CLIMB_VY,
	KEY_RM_POS_INIT_X,
	KEY_RM_POS_INIT_Y,
	KEY_CAMERA_CURRENT_POINT,
	KEY_BD_DIS_ATTACK,
	KEY_BD_VY_ACTTACK,
	KEY_BD_VX,
	KEY_EN_TIMEEXPLOSIVE,
	KEY_CM_VELLOC_X,
	KEY_CAMERA_MOVE_X,
	KEY_CAMERA_MOVE_Y,
	KEY_COUNT
};


class CConfig
{
private:
	CConfig(void);
	
	void LoadConfig(char*);
	static CConfig* instance;
public:
	//static CConfig* GetInstance();
	float *m_ArrayConfig;
	static float ValueOf(int inIDKey);
	static void ReleaseConfig();
	~CConfig(void);
};

#endif //RESOURCE_CONFIG_H