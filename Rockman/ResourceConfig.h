#ifndef RESOURCE_CONFIG_H
#define RESOURCE_CONFIG_H

enum KEY
{
	KEY_RM_TIME_INJUNRED = 0,
	KEY_RM_TIME_SHOT,
	KEY_RM_VY_JUMP,
	KEY_RM_ACCEL_STOP,
	KEY_RM_MAX_VX,
	KEY_RM_VX_PREPARE,
	KEY_RM_CLIMB_VY,
	KEY_COUNT
};


class ResourceConfig
{
private:
	ResourceConfig(void);
	float *m_ArrayConfig;
	void LoadConfig(char*);
	static ResourceConfig* instance;
public:
	static ResourceConfig* GetInstance();
	float GetValue(int inIDKey);
	~ResourceConfig(void);
};

#endif //RESOURCE_CONFIG_H