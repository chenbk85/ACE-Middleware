
//=============================================================================
/**
 *  @file    root_is.h
 *
 *  $Id$
 *
 *  Concrete visitor for the Root class
 *  This one provides code generation for elements of the Root node in the
 *  implementation skeletons.
 *
 *
 *  @author Yamuna Krishnamurthy (yamuna@cs.wustl.edu)
 */
//=============================================================================


#ifndef _BE_VISITOR_ROOT_ROOT_IS_H_
#define _BE_VISITOR_ROOT_ROOT_IS_H_

/**
 * @class be_visitor_root_is
 *
 * @brief be_visitor_root_is
 *
 * This is a concrete visitor to generate the implementation skeletons for root
 */
class be_visitor_root_is : public be_visitor_root
{
public:
  /// constructor
  be_visitor_root_is (be_visitor_context *ctx);

  /// destructor
  ~be_visitor_root_is (void);

  /// set the right context and make a visitor
  virtual int init (void);
};

#endif /* _BE_VISITOR_ROOT_ROOT_IS_H_ */
