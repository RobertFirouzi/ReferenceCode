/*
 * subject.h
 *
 *  Created on: Jun 1, 2016
 *      Author: Robert
 *
 *  Base classes for a Subject and Observer
 *  Should extend these with needed fields and methods for specific
 *  implementation
 *
 */

#ifndef OBSERVER_HEADERS_OBSERVER_H_
#define OBSERVER_HEADERS_OBSERVER_H_

#include <iostream>
#include <vector>

class SubjectBase;
class SubjectData;
class ObserverBase;

/**
 * Public class to hold generic Subject Data that an oberver can be passed
 * on update calls - extend with the needed data fields
 */
class SubjectData
{
public:
	virtual ~SubjectData();
	SubjectData();
};

class ObserverBase
{
protected:
	const SubjectBase *subject;
	bool isUpdate;
	SubjectData data;
public:
	ObserverBase();
	ObserverBase(const SubjectBase *_subject);
	virtual ~ObserverBase();

	/**
	 * Subject calls this method to notify observer of state change
	 * @param type Subject
	 */
	virtual void update(const SubjectBase *subject);
	/**
	 * Subject calls this method to pass new data to observer
	 * @param type SubjectBase
	 * @param type SubjectData
	 */
	virtual void update(const SubjectBase *subject, const SubjectData *data);

	/*returns true if passed in observer is same as calling observer*/
	virtual bool equals(const ObserverBase &observer);

};

/**
 * Base class for a Subject in an Observer pattern implementation
 */
class SubjectBase
{
protected:
	std::vector<ObserverBase> observers;
	bool isChanged;
	SubjectData data;
public:
	SubjectBase();
	SubjectBase(SubjectData data);
	virtual ~SubjectBase();
	/*returns false if observer already on list*/
	virtual bool registerObserver(const ObserverBase & observer);
	/*returns all instances of observer and returns false if observer not in list*/
	virtual bool removeObserver(const ObserverBase & observer);
	/*notify all obervers of a change if isChanged=true, do not pass data*/
	virtual void notifyObservers();
	/*notify all obervers of a change if isChanged=true, pass a ptr to data*/
	virtual void notifyObservers(const SubjectData *data);
};



#endif /* OBSERVER_HEADERS_OBSERVER_H_ */
