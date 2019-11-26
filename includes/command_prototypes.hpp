#ifndef COMMAND_PROTOTYPES
# define COMMAND_PROTOTYPES
#include "IOperand.hpp"
#include "OpFactory.hpp"
#include "our_exceptions.hpp"
#include <string>
#include <iostream>
#include <deque>
//push pop dump
void		stack_interface_command__push(std::deque<const IOperand *> & q, eOperandType type, OpFactory & fac, std::string value);
void		stack_interface_command__pop(std::deque<const IOperand *> & q, __attribute__((unused)) eOperandType type, __attribute__((unused)) OpFactory & fac, __attribute__((unused)) std::string value);
void		stack_interface_command__dump(std::deque<const IOperand *> & q, __attribute__((unused))eOperandType type, __attribute__((unused))OpFactory & fac, __attribute__((unused))std::string value);
//assert print exit
void		stack_interface_command__assert(std::deque<const IOperand *> & q, eOperandType type, __attribute__((unused))OpFactory & fac, std::string value);
void		stack_interface_command__print(std::deque<const IOperand *> & q, __attribute__((unused)) eOperandType type, __attribute__((unused)) OpFactory & fac, std::string value);
void		stack_interface_command__exit(__attribute__((unused)) std::deque<const IOperand *> & q, __attribute__((unused))eOperandType type, __attribute__((unused)) OpFactory & fac, __attribute__((unused)) std::string value);
//add sub mul div mod
void		stack_interface_command__add(std::deque<const IOperand *> & q, __attribute__((unused)) eOperandType type, __attribute__((unused)) OpFactory & fac, __attribute__((unused))std::string value);
void		stack_interface_command__sub(std::deque<const IOperand *> & q, __attribute__((unused))eOperandType type, __attribute__((unused))OpFactory & fac, __attribute__((unused))std::string value);
void		stack_interface_command__mul(std::deque<const IOperand *> & q, __attribute__((unused))eOperandType type, __attribute__((unused))OpFactory & fac, __attribute__((unused))std::string value);
void		stack_interface_command__div(std::deque<const IOperand *> & q, __attribute__((unused))eOperandType type, __attribute__((unused))OpFactory & fac, __attribute__((unused))std::string value);
void		stack_interface_command__mod(std::deque<const IOperand *> & q, __attribute__((unused))eOperandType type, __attribute__((unused))OpFactory & fac, __attribute__((unused))std::string value);

#endif
