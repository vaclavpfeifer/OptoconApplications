#ifndef ABSTRACT_COMMAND_H
#define ABSTRACT_COMMAND_H


class AbstractCommand
{
public:
	AbstractCommand()
	{
		int a = 5;
	}
	virtual ~AbstractCommand()
	{
		int a = 5;
	}

	virtual int execute() const = 0;

protected:
	long id; // TODO: id for command type identification or for a number odintifying sequence	 
	// TODO: add command Name??
};


#endif
