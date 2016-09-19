#ifndef ABSTRACT_COMMAND_H
#define ABSTRACT_COMMAND_H


class AbstractCommand
{
public:
	AbstractCommand();
	virtual ~AbstractCommand();

	virtual int execute() = 0;

protected:
	long id; // TODO: id for command type identification or for a number odintifying sequence	 
	// TODO: add command Name??
};


#endif
