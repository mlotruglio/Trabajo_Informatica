#pragma once
class inputstates{

	int mousepos[2];
	bool mousestates[4];
	bool keystates[255];
public:

	inputstates();
	void setkeystates(unsigned char key,bool state);
	bool* getkeystates(void);
	void setmousepos(int x, int y);
	int* getmousepos(void);
	void setmousestates(int mouse, bool state);
	bool* getmousestates(void);
};