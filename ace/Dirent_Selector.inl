// -*- C++ -*-
//
// $Id$

ACE_BEGIN_VERSIONED_NAMESPACE_DECL

ACE_INLINE int
ACE_Dirent_Selector::length (void) const
{
  return n_;
}

ACE_INLINE dirent *
ACE_Dirent_Selector::operator[] (const int n) const
{
  return this->namelist_[n];
}

ACE_END_VERSIONED_NAMESPACE_DECL
