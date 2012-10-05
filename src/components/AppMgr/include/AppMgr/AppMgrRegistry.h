/*
 * AppMgrRegistry.h
 *
 *  Created on: Oct 4, 2012
 *      Author: vsalo
 */

#ifndef APPMGRREGISTRY_H_
#define APPMGRREGISTRY_H_

#include "IApplication.h"
#include "RegistryItem.h"

#include <set>
#include <string>

class AppMgrRegistry
{
public:
	~AppMgrRegistry( );

	static AppMgrRegistry& getInstance( );

	const RegistryItem& registerApplication( const IApplication& app );
	void unregisterApplication( RegistryItem& item  );

private:
	AppMgrRegistry( );

	std::set<RegistryItem> mRegistryItems;
};

#endif /* APPMGRREGISTRY_H_ */
