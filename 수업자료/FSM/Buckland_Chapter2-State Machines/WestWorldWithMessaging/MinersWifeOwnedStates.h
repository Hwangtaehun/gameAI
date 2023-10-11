#ifndef MINERSWIFE_OWNED_STATES_H
#define MINERSWIFE_OWNED_STATES_H
//------------------------------------------------------------------------
//
//  Name:   MinersWifeOwnedStates.h
//
//  Desc:   All the states that can be assigned to the MinersWife class
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "fsm/State.h"

class MinersWife;


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class ProfessorGlobalState : public State<MinersWife>
{  
private:
  
  ProfessorGlobalState(){}

  //copy ctor and assignment should be private
  ProfessorGlobalState(const ProfessorGlobalState&);
  ProfessorGlobalState& operator=(const ProfessorGlobalState&);
 
public:

  //this is a singleton
  static ProfessorGlobalState* Instance();
  
  virtual void Enter(MinersWife* wife){}

  virtual void Execute(MinersWife* wife);

  virtual void Exit(MinersWife* wife){}

  virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class CheckCode : public State<MinersWife>
{
private:

  CheckCode(){}
  
  //copy ctor and assignment should be private
  CheckCode(const CheckCode&);
  CheckCode& operator=(const CheckCode&);

public:

  //this is a singleton
  static CheckCode* Instance();
  
  virtual void Enter(MinersWife* wife);

  virtual void Execute(MinersWife* wife);

  virtual void Exit(MinersWife* wife);
  
  virtual bool OnMessage(MinersWife* wife, const Telegram& msg);

};



//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class WriteMemo : public State<MinersWife>
{
private:
  
  WriteMemo(){}

  //copy ctor and assignment should be private
  WriteMemo(const WriteMemo&);
  WriteMemo& operator=(const WriteMemo&);
 
public:

  //this is a singleton
  static WriteMemo* Instance();
  
  virtual void Enter(MinersWife* wife);

  virtual void Execute(MinersWife* wife);

  virtual void Exit(MinersWife* wife);

  virtual bool OnMessage(MinersWife* wife, const Telegram& msg);

};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class FindReference : public State<MinersWife>
{
private:

	FindReference() {}

	//copy ctor and assignment should be private
	FindReference(const FindReference&);
	FindReference& operator=(const FindReference&);

public:

	//this is a singleton
	static FindReference* Instance();

	virtual void Enter(MinersWife* wife);

	virtual void Execute(MinersWife* wife);

	virtual void Exit(MinersWife* wife);

	virtual bool OnMessage(MinersWife* wife, const Telegram& msg);

};


//------------------------------------------------------------------------
//

//------------------------------------------------------------------------
class InOffice : public State<MinersWife>
{
private:
  
  InOffice(){}

  //copy ctor and assignment should be private
  InOffice(const InOffice&);
  InOffice& operator=(const InOffice&);
 
public:

  //this is a singleton
  static InOffice* Instance();
  
  virtual void Enter(MinersWife* wife);

  virtual void Execute(MinersWife* wife);

  virtual void Exit(MinersWife* wife);

  virtual bool OnMessage(MinersWife* wife, const Telegram& msg);
};


#endif