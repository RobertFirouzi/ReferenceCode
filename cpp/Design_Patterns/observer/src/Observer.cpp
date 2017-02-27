/*
 * Observer.cpp
 *
 *  Created on: Jun 1, 2016
 *      Author: Robert
 */

#include "../h/observer.h"

/*SubjectData*/
SubjectData::~SubjectData(){};
SubjectData::SubjectData(){};

/*ObserverBase Definitions*/
ObserverBase::ObserverBase() : subject(0), isUpdate(false) {};
ObserverBase::ObserverBase(const SubjectBase *_subject) : subject(_subject),isUpdate(false){};

ObserverBase::~ObserverBase(){};

void ObserverBase::update(const SubjectBase *_subject)
{
	this->subject=_subject;
	this->isUpdate=true;
};

void ObserverBase::update(const SubjectBase *_subject, const SubjectData *_data)
{
	this->subject=_subject;
	this->data=*_data;
};

bool ObserverBase::equals(const ObserverBase &_observer)
{
	if(&_observer == this)
		return true;
	else
		return false;
};

/*SubjectBase Definitions*/
SubjectBase::SubjectBase():isChanged(false){};
SubjectBase::SubjectBase(SubjectData _data) : isChanged(false),data(_data){};
SubjectBase::~SubjectBase(){};

bool SubjectBase::registerObserver(const ObserverBase & _observer)//TODO make sure they are not already on list
{
	observers.push_back(_observer);
	return true;
};

bool SubjectBase::removeObserver(const ObserverBase & _observer)//TODO - use an iterator
{
	bool retVal = false;

	for(unsigned int i =0; i<observers.size();i++)
	{
		if(observers[i].equals(_observer))
		{
			observers.erase(observers.begin()+i);
			retVal=true;
		}
	}

	return retVal;
};

void SubjectBase::notifyObservers()//TODO - use an iterator
{
	for(unsigned int i =0; i<observers.size();i++)
	{
		observers[i].update(this);
	}
};

void SubjectBase::notifyObservers(const SubjectData *_data)//TODO - use an iterator
{
	for(unsigned int i =0; i<observers.size();i++)
	{
		observers[i].update(this,_data);
	}
};
