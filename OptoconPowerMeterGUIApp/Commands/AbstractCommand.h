#ifndef ABSTRACT_COMMAND_H
#define ABSTRACT_COMMAND_H


class AbstractCommand
{
public:
	AbstractCommand();
	virtual ~AbstractCommand();

	virtual int execute() = 0;
};


#endif
