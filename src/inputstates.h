#pragma once
class inputstates{
	bool keystates[255];
	int mousepos[2];
public:
	inputstates();
	void setkeystates(unsigned char key,bool state);
	bool* getkeystates(void);
	void setmousepos(int x, int y);
	int* getmousepos(void);
};