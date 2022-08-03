#pragma once
#include "Pipe.h"

class PipeGroup : public Node
{
private:
	Pipe* topPipe;
	Pipe* botPipe;
	float pipeHeight;
	void randPipePos();
public:
	PipeGroup(const std::string filename);
	Pipe* getTopPipe();
	Pipe* getBotPipe();
};

