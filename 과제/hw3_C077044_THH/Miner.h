#ifndef MINER_H
#define MINER_H
//------------------------------------------------------------------------
//
//  Name:   Miner.h
//
//  Desc:   A class defining a goldminer.
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <string>
#include <cassert>
#include <iostream>

#include "BaseGameEntity.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "MinerOwnedStates.h"
#include "fsm/StateMachine.h"

template <class entity_type> class State; //pre-fixed with "template <class entity_type> " for vs8 compatibility

struct Telegram;

//the amount of gold a miner must have before he feels he can go home
const int CodeLevel       = 5;
//the amount of nuggets a miner can carry
const int MaxCode         = 3;
//above this value a miner is Hungry
const int HungryLevel        = 5;
//above this value a miner is sleepy
const int TirednessThreshold = 5;



class Miner : public BaseGameEntity
{
private:

  //an instance of the state machine class
  StateMachine<Miner>*  m_pStateMachine;
  
  location_type         m_Location;

  //how many nuggets the miner has in his pockets
  int                   m_CurrentCode;

  int                   m_WholeCode;

  //the higher the value, the thirstier the miner
  int                   m_Hungry;

  //the higher the value, the more tired the miner
  int                   m_Fatigue;

public:

  Miner(int id):m_Location(shack),
                          m_CurrentCode(0),
                          m_WholeCode(0),
                          m_Hungry(0),
                          m_Fatigue(0),
                          BaseGameEntity(id)
                               
  {
    //set up state machine
    m_pStateMachine = new StateMachine<Miner>(this);
    
    m_pStateMachine->SetCurrentState(WriteCode::Instance());

    /* NOTE, A GLOBAL STATE HAS NOT BEEN IMPLEMENTED FOR THE MINER */
  }

  ~Miner(){delete m_pStateMachine;}

  //this must be implemented
  void Update();

  //so must this
  virtual bool  HandleMessage(const Telegram& msg);

  
  StateMachine<Miner>* GetFSM()const{return m_pStateMachine;}


  
  //-------------------------------------------------------------accessors
  location_type Location()const{return m_Location;}
  void          ChangeLocation(location_type loc){m_Location=loc;}
    
  int           CurrentCode()const{return m_CurrentCode;}
  void          SetCurrentCode(int val){m_CurrentCode = val;}
  void          AddToCurrentCode(int val);
  bool          CodeFull()const{return m_CurrentCode >= MaxCode;}

  bool          Fatigued()const;
  void          DecreaseFatigue(){m_Fatigue -= 1;}
  void          IncreaseFatigue(){m_Fatigue += 1;}

  int           Wealth()const{return m_WholeCode;}
  void          SetWealth(int val){m_WholeCode = val;}
  void          AddToWealth(int val);

  bool          Hungry()const; 
  void          EatAChocolate(){m_Hungry = 0; m_WholeCode-=2;}

};



#endif
