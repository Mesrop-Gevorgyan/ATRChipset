

#include "selection.h"


bool CSelection::isEmpty() const
{
	return mapSelection.isEmpty();
}


bool CSelection::isContains(Field const& oID) const
{
	return mapSelection.contains(oID);
}


int CSelection::getCount() const
{
	return mapSelection.count();
}


void CSelection::clear()
{
	mapSelection.clear();
}


SFieldValueSelection CSelection::getFieldValueSelection(Field const& oID) const
{
	return mapSelection.value(oID, SFieldValueSelection());
}


void CSelection::addFieldValueSelection(SFieldValueSelection const& oSel)
{
	if (oSel.isValid())
		mapSelection[oSel.oFieldID] = oSel;
}


void CSelection::remove(Field const& oID)
{
	if (!mapSelection.isEmpty())
		mapSelection.remove(oID);
}