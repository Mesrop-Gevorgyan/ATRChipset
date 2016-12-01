

#include "selection.h"


///////////////////////////////////////////////////////////////////////////////
//
// Implementation of CSelection
//
bool CSelection::isEmpty() const
{
	return vecSelection.isEmpty();
}


bool CSelection::isContains(Field const& oID) const
{
	return (getIndexFromFieldID(oID) != -1);
}


int CSelection::getCount() const
{
	return vecSelection.count();
}


void CSelection::clear()
{
	vecSelection.clear();
}


SFieldValueSelection CSelection::getAt(int nIndex) const
{
	if (nIndex >= 0 && nIndex < vecSelection.size())
		return vecSelection[nIndex];
	else
		SFieldValueSelection(); // Invalid selection
}


SFieldValueSelection CSelection::getFieldValueSelection(Field const& oID) const
{
	int nIndex = getIndexFromFieldID(oID);
	if (nIndex != -1)
		return vecSelection[nIndex];
	else
		return SFieldValueSelection(); // Invalid selection
}


void CSelection::addFieldValueSelection(SFieldValueSelection const& oSel)
{
	if (oSel.isValid())
	{
		int nIndex = getIndexFromFieldID(oSel.oFieldID);
		if (nIndex != -1)
			vecSelection[nIndex] = oSel;
		else
			vecSelection.append(oSel);
	}
}


void CSelection::remove(int nIndex)
{
	if (nIndex >= 0 && nIndex < vecSelection.size())
		vecSelection.remove(nIndex);
}


void CSelection::remove(Field const& oID)
{
	int nIndex = getIndexFromFieldID(oID);
	if (nIndex != -1)
		vecSelection.remove(nIndex);
}


int CSelection::getIndexFromFieldID(Field const& oID) const
{
	if (oID.isEmpty())
		return -1;

	int nIndex = -1;
	for (int i = 0; i < vecSelection.size(); ++i)
	{
		if (vecSelection[i].oFieldID == oID)
		{
			nIndex = i;
			break;
		}
	}
	return nIndex;
}
///////////////////////////////////////////////////////////////////////////////