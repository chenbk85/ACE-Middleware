// Constraint_Nodes.cpp

// =====================================================================
// $Id$
// 
// = LIBRARY 
//    Lookup
//  
// = FILENAME
//    Constraint_Nodes.cpp
// 
// = AUTHOR 
//    Seth Widoff <sbw1@cs.wustl.edu> 
//   
// =====================================================================


#include "Constraint_Nodes.h"

const CORBA::Long MAX_SIGNED_INTEGER = (~(CORBA::Long)0) >> 1;
const CORBA::Long MIN_SIGNED_INTEGER = ~(MAX_SIGNED_INTEGER);
const CORBA::ULong MAX_UNSIGNED_INTEGER = (~(CORBA::ULong)0);

int
TAO_Noop_Constraint::accept(TAO_Constraint_Visitor* visitor)
{
  int return_value = -1;
  switch(this->type_)
    {
    case FIRST:
      return_value = visitor->visit_first(this);
      break;
    case RANDOM:
      return_value = visitor->visit_random(this);
    }

  return return_value;
}

TAO_Binary_Constraint::
TAO_Binary_Constraint(TAO_Expression_Type op_type,
				TAO_Constraint* left,
				TAO_Constraint* right)
  : op_ (op_type),
    left_ (left),
    right_ (right)
{
}

TAO_Binary_Constraint::~TAO_Binary_Constraint()
{
  delete left_;
  delete right_;
}

// Dispatch table for the accept method
static int (*dispatch_table[]) (TAO_Constraint_Visitor*,
				 TAO_Binary_Constraint*)=
{
  TAO_Binary_Constraint::visit_greater_than,
  TAO_Binary_Constraint::visit_greater_than_equal,
  TAO_Binary_Constraint::visit_less_than,
  TAO_Binary_Constraint::visit_less_than_equal,
  TAO_Binary_Constraint::visit_equal,
  TAO_Binary_Constraint::visit_not_equal,
  0,
  TAO_Binary_Constraint::visit_and,
  TAO_Binary_Constraint::visit_or,
  0,
  TAO_Binary_Constraint::visit_in,
  TAO_Binary_Constraint::visit_twiddle,
  0,
  TAO_Binary_Constraint::visit_add,
  TAO_Binary_Constraint::visit_sub,
  TAO_Binary_Constraint::visit_mult,
  TAO_Binary_Constraint::visit_div
};

// Simulate the fun of actual double dispatching.
int
TAO_Binary_Constraint::accept(TAO_Constraint_Visitor* visitor)
{
  int offset = this->op_ - GT,
    return_value = -1;

  if (dispatch_table[offset] != 0)
    return_value = dispatch_table[offset](visitor, this);

  return return_value;
}

int
TAO_Binary_Constraint::
visit_or(TAO_Constraint_Visitor* visitor,
		  TAO_Binary_Constraint* expr)
{
  return visitor->visit_or(expr);
}

int
TAO_Binary_Constraint::
visit_and(TAO_Constraint_Visitor* visitor,
	  TAO_Binary_Constraint* expr)
{
  return visitor->visit_and(expr);
}

int
TAO_Binary_Constraint::
visit_less_than(TAO_Constraint_Visitor* visitor,
		TAO_Binary_Constraint* expr)
{
  return visitor->visit_less_than(expr);
}

int
TAO_Binary_Constraint::
visit_less_than_equal(TAO_Constraint_Visitor* visitor,
		      TAO_Binary_Constraint* expr)
{
  return visitor->visit_less_than_equal(expr);
}

int
TAO_Binary_Constraint::
visit_greater_than(TAO_Constraint_Visitor* visitor,
		   TAO_Binary_Constraint* expr)
{
  return visitor->visit_greater_than(expr);
}

int
TAO_Binary_Constraint::
visit_greater_than_equal(TAO_Constraint_Visitor* visitor,
			 TAO_Binary_Constraint* expr)
{
  return visitor->visit_greater_than_equal(expr);
}

int
TAO_Binary_Constraint::
visit_equal(TAO_Constraint_Visitor* visitor,
	    TAO_Binary_Constraint* expr)
{
  return visitor->visit_equal(expr);
}

int
TAO_Binary_Constraint::
visit_not_equal(TAO_Constraint_Visitor* visitor,
		TAO_Binary_Constraint* expr)
{
  return visitor->visit_not_equal(expr);
}

int
TAO_Binary_Constraint::
visit_add(TAO_Constraint_Visitor* visitor,
	  TAO_Binary_Constraint* expr)
{
  return visitor->visit_add(expr);
}

int
TAO_Binary_Constraint::
visit_sub(TAO_Constraint_Visitor* visitor,
	  TAO_Binary_Constraint* expr)
{
  return visitor->visit_sub(expr);
}

int
TAO_Binary_Constraint::
visit_mult(TAO_Constraint_Visitor* visitor,
	   TAO_Binary_Constraint* expr)
{
  return visitor->visit_mult(expr);
}

int
TAO_Binary_Constraint::
visit_div(TAO_Constraint_Visitor* visitor,
	  TAO_Binary_Constraint* expr)
{
  return visitor->visit_div(expr);
}

int
TAO_Binary_Constraint::
visit_twiddle(TAO_Constraint_Visitor* visitor,
	      TAO_Binary_Constraint* expr)
{
  return visitor->visit_twiddle(expr);
}

int
TAO_Binary_Constraint::
visit_in(TAO_Constraint_Visitor* visitor,
	 TAO_Binary_Constraint* expr)
{
  return visitor->visit_in(expr);
}


TAO_Constraint*
TAO_Binary_Constraint::left_operand()
{
  return this->left_;
}

TAO_Constraint*
TAO_Binary_Constraint::right_operand()
{
  return this->right_;
}

TAO_Unary_Constraint::
TAO_Unary_Constraint(TAO_Expression_Type op_type,
		     TAO_Constraint* operand)
  : op_ (op_type),
    operand_ (operand)
{
}

TAO_Unary_Constraint::~TAO_Unary_Constraint()
{
  delete operand_;
}

  
int
TAO_Unary_Constraint::accept(TAO_Constraint_Visitor* visitor)
{
  // Since there are only three unary operators, there's no need for a
  // dispatch table.
  int return_value = -1;
  switch (this->op_)
    {
    case CONSTRAINT:
      return_value = visitor->visit_constraint(this);
      break;
    case WITH:
      return_value = visitor->visit_with(this);
      break;
    case MIN:
      return_value = visitor->visit_min(this);
      break;
    case MAX:
      return_value = visitor->visit_max(this);
      break;
    case NOT:
      return_value = visitor->visit_not(this);
      break;
    case UMINUS:
      return_value = visitor->visit_unary_minus(this);
      break;
    case EXIST:
      return_value = visitor->visit_exist(this);
      break;
    }

  return return_value;
}

TAO_Constraint*
TAO_Unary_Constraint::operand()
{
  return this->operand_;
}

TAO_Property_Constraint::
TAO_Property_Constraint(const char* name)
  : name_ (ACE_OS::strdup (name))
{
}

TAO_Property_Constraint::~TAO_Property_Constraint()
{
  delete this->name_;
}
  
int
TAO_Property_Constraint::accept(TAO_Constraint_Visitor* visitor)
{
  return visitor->visit_property(this);
}

const char*
TAO_Property_Constraint::name() const
{
  return name_;
}

TAO_Literal_Constraint::
TAO_Literal_Constraint (const TAO_Literal_Constraint& lit)
{
  this->copy (lit);
}


TAO_Literal_Constraint::
TAO_Literal_Constraint(CORBA::Any* any)
  : type_ (TAO_Literal_Constraint::comparable_type (any->type ()))
{
  CORBA::Any& any_ref = *any;
  CORBA::TCKind corba_type = any_ref.type()->kind();
  
  switch(this->type_)
    {
    case SIGNED_INTEGER:
      this->op_.integer_ = 0;
      if (corba_type == CORBA::tk_short)
	{
	  CORBA::Short sh;
	  any_ref >>= sh;
	  this->op_.integer_ = (CORBA::Long)sh;
	}
      else
	any_ref >>= this->op_.integer_;
      break;
    case UNSIGNED_INTEGER:
      this->op_.uinteger_ = 0;
      if (corba_type == CORBA::tk_ushort)
	{
	  CORBA::UShort sh;
	  any_ref >>= sh;
	  this->op_.uinteger_ = (CORBA::ULong)sh;
	}
      else
	any_ref >>= this->op_.uinteger_;
      break;
    case DOUBLE:
      if (corba_type == CORBA::tk_float)
	{
	  CORBA::Float fl;
	  (*any) >>= fl;
	  this->op_.double_ = (CORBA::Double)fl;
	}
      else
	(*any) >>= this->op_.double_;
      break;
    case BOOLEAN:
      {
	CORBA_Any::to_boolean tmp(this->op_.bool_);
	(*any) >>= tmp;
      }
      break;
    case STRING:
      {
	char * s;
	any_ref >>= s;
	this->op_.str_ = ACE_OS::strdup(s);
      }
      break;
    case SEQUENCE:
      this->op_.any_ = any;
    }
}

TAO_Literal_Constraint::TAO_Literal_Constraint(CORBA::ULong uinteger)
  : type_ (UNSIGNED_INTEGER)
{
  this->op_.uinteger_ = uinteger;
}

TAO_Literal_Constraint::TAO_Literal_Constraint(CORBA::Long integer)
  : type_ (SIGNED_INTEGER)
{
  this->op_.integer_ = integer;
}

TAO_Literal_Constraint::TAO_Literal_Constraint(CORBA::Boolean boolean)
  : type_ (BOOLEAN)
{
  this->op_.bool_ = boolean;
}

TAO_Literal_Constraint::TAO_Literal_Constraint(CORBA::Double doub)
  : type_ (DOUBLE)
{
  this->op_.double_ = doub;
}

TAO_Literal_Constraint::TAO_Literal_Constraint(const char* str)
  : type_ (STRING)
{
  this->op_.str_ = ACE_OS::strdup(str);
}

TAO_Literal_Constraint::~TAO_Literal_Constraint(void)
{
  if (this->type_ == STRING)
    free (this->op_.str_);
  else if (this->type_ == SEQUENCE)
    CORBA::Any::_release (this->op_.any_);
}

int
TAO_Literal_Constraint::accept(TAO_Constraint_Visitor* visitor)
{
  return visitor->visit_literal(this);
}

void
TAO_Literal_Constraint::operator= (const TAO_Literal_Constraint& co)
{
  this->copy (co);
}

TAO_Literal_Constraint::operator CORBA::Boolean(void) const
{
  return (this->type_ == BOOLEAN) ? this->op_.bool_ : (CORBA::Boolean)0;
}

TAO_Literal_Constraint::operator CORBA::ULong(void) const
{
  CORBA::ULong return_value = (CORBA::ULong)0;
  
  if (this->type_ == UNSIGNED_INTEGER)
    return_value = this->op_.uinteger_;
  else if (this->type_ == SIGNED_INTEGER)
    return_value =
      (this->op_.integer_ > 0) ? (CORBA::ULong)this->op_.integer_ : 0;
  else if (this->type_ == DOUBLE)
    return_value =
      (this->op_.double_ > 0) ?
      ((this->op_.double_ > MAX_UNSIGNED_INTEGER) ?
       MAX_UNSIGNED_INTEGER :
       (CORBA::ULong)this->op_.double_)
      : 0;
  
  return return_value;
}

TAO_Literal_Constraint::operator CORBA::Long(void) const
{
  CORBA::Long return_value = (CORBA::Long)0;

  if (this->type_ == SIGNED_INTEGER)
    return_value = this->op_.integer_;
  else if (this->type_ == UNSIGNED_INTEGER)
    return_value =
      (this->op_.uinteger_ > MAX_SIGNED_INTEGER) ?
      MAX_SIGNED_INTEGER : this->op_.uinteger_;
  else if (this->type_ == DOUBLE)
    return_value  =
      (this->op_.double_ > 0) ?
      ((this->op_.double_ > MAX_SIGNED_INTEGER) ?
       MAX_SIGNED_INTEGER :
       (CORBA::Long)this->op_.double_) :
    ((this->op_.double_ < MIN_SIGNED_INTEGER) ?
     MIN_SIGNED_INTEGER :
     (CORBA::Long)this->op_.double_);

  return return_value;
}

TAO_Literal_Constraint::operator CORBA::Double(void) const
{
  CORBA::Double return_value = (CORBA::Double)0.0;
  
  if (this->type_ == DOUBLE)
    return_value = this->op_.double_;
  else if (this->type_ == SIGNED_INTEGER)
    return_value = (CORBA::Double)this->op_.integer_;
  else if (this->type_ == UNSIGNED_INTEGER)
    return_value = (CORBA::Double)this->op_.uinteger_;

  return return_value;
}

TAO_Literal_Constraint::operator const char* (void) const
{
  return (this->type_ == STRING) ? this->op_.str_ : 0;
}

TAO_Literal_Constraint::operator const CORBA::Any* (void) const
{
  return (this->type_ == SEQUENCE) ? this->op_.any_ : 0;
}

TAO_Expression_Type
TAO_Literal_Constraint::comparable_type (CORBA::TypeCode_ptr type)
{
  // Convert a CORBA::TCKind into a TAO_Literal_Type
  CORBA::TCKind kind = type->kind();
  TAO_Expression_Type return_value = UNKNOWN;
  
  switch (kind)
    {
    case CORBA::tk_ushort:
    case CORBA::tk_ulong:
      return_value = UNSIGNED_INTEGER;
      break;
    case CORBA::tk_long:
    case CORBA::tk_short:
      return_value = SIGNED_INTEGER;
      break;
    case CORBA::tk_boolean:
      return_value = BOOLEAN;
      break;
    case CORBA::tk_float:
    case CORBA::tk_double:
      return_value = DOUBLE;
      break;
    case CORBA::tk_string:
      return_value = STRING;
      break;
    case CORBA::tk_sequence:
      return_value = SEQUENCE;
      break;
    case CORBA::tk_alias:
      {
	if (type->content_type ()->kind () == CORBA::tk_sequence)
	  return_value = SEQUENCE;
      }
      break;
    default:
      return_value = UNKNOWN;
    }

  return return_value;
}

int
operator== (const TAO_Literal_Constraint& left,
	    const TAO_Literal_Constraint& right)
{
  int return_value = 0;
  TAO_Expression_Type widest_type =
    TAO_Literal_Constraint::widest_type(left, right);

  switch (widest_type)
    {
    case STRING:
      return_value = (ACE_OS::strcmp((const char*)left, (const char*)right) == 0);
      break;
    case DOUBLE:
      return_value = (CORBA::Double)left == (CORBA::Double)right;
      break;
    case SIGNED_INTEGER:
      return_value = (CORBA::Long)left == (CORBA::Long)right;
      break;
    case UNSIGNED_INTEGER:
      return_value = (CORBA::ULong)left == (CORBA::ULong)right;
      break;
    case BOOLEAN:
      return_value = (CORBA::Boolean)left == (CORBA::Boolean)right;
      break;
    }

  return return_value;
}


int
operator!= (const TAO_Literal_Constraint& left,
	    const TAO_Literal_Constraint& right)
{
  int return_value = 0;
  TAO_Expression_Type widest_type =
    TAO_Literal_Constraint::widest_type(left, right);

  switch (widest_type)
    {
    case STRING:
      return_value = (ACE_OS::strcmp((const char*)left, (const char*)right) != 0);
      break;
    case DOUBLE:
      return_value = (CORBA::Double)left != (CORBA::Double)right;
      break;
    case SIGNED_INTEGER:
      return_value = (CORBA::Long)left != (CORBA::Long)right;
      break;
    case UNSIGNED_INTEGER:
      return_value = (CORBA::ULong)left != (CORBA::ULong)right;
      break;
    case BOOLEAN:
      return_value = (CORBA::Boolean)left != (CORBA::Boolean)right;
      break;
    }

  return return_value;
}

int
operator< (const TAO_Literal_Constraint& left,
	   const TAO_Literal_Constraint& right)
{
  int return_value = 0;
  TAO_Expression_Type widest_type =
    TAO_Literal_Constraint::widest_type(left, right);

  switch (widest_type)
    {
    case STRING:
      return_value = (ACE_OS::strcmp((const char*)left, (const char*)right) < 0);
      break;
    case DOUBLE:
      return_value = (CORBA::Double)left < (CORBA::Double)right;
      break;
    case SIGNED_INTEGER:
      return_value = (CORBA::Long)left < (CORBA::Long)right;
      break;
    case UNSIGNED_INTEGER:
      return_value = (CORBA::ULong)left < (CORBA::ULong)right;
      break;
    case BOOLEAN:
      return_value = (CORBA::Boolean) left < (CORBA::Boolean) right;
      break;
    }

  return return_value;
}

int
operator<= (const TAO_Literal_Constraint& left,
	    const TAO_Literal_Constraint& right)
{
  int return_value = 0;
  TAO_Expression_Type widest_type =
    TAO_Literal_Constraint::widest_type(left, right);
  
  switch (widest_type)
    {
    case STRING:
      return_value = (ACE_OS::strcmp((const char*)left, (const char*)right) <= 0);
      break;
    case DOUBLE:
      return_value = (CORBA::Double)left <= (CORBA::Double)right;
      break;
    case SIGNED_INTEGER:
      return_value = (CORBA::Long)left <= (CORBA::Long)right;
      break;
    case UNSIGNED_INTEGER:
      return_value = (CORBA::ULong)left <= (CORBA::ULong)right;
      break;
    }
  
  return return_value;
}

int
operator> (const TAO_Literal_Constraint& left,
	   const TAO_Literal_Constraint& right)
{
  int return_value = 0;
  TAO_Expression_Type widest_type =
    TAO_Literal_Constraint::widest_type(left, right);

  switch (widest_type)
    {
    case STRING:
      return_value = (ACE_OS::strcmp((const char*)left, (const char*)right) > 0);
      break;
    case DOUBLE:
      return_value = (CORBA::Double)left > (CORBA::Double)right;
      break;
    case SIGNED_INTEGER:
      return_value = (CORBA::Long)left > (CORBA::Long)right;
      break;
    case UNSIGNED_INTEGER:
      return_value = (CORBA::ULong)left > (CORBA::ULong)right;
      break;
    }

  return return_value;
}

int
operator>= (const TAO_Literal_Constraint& left,
	    const TAO_Literal_Constraint& right)
{
  int return_value = 0;
  TAO_Expression_Type widest_type =
    TAO_Literal_Constraint::widest_type(left, right);

  switch (widest_type)
    {
    case STRING:
      return_value = (ACE_OS::strcmp((const char*)left, (const char*)right) >= 0);
      break;
    case DOUBLE:
      return_value = (CORBA::Double)left >= (CORBA::Double)right;
      break;
    case SIGNED_INTEGER:
      return_value = (CORBA::Long)left >= (CORBA::Long)right;
      break;
    case UNSIGNED_INTEGER:
      return_value = (CORBA::ULong)left >= (CORBA::ULong)right;
      break;
    }

  return return_value;
}


int
operator== (CORBA::Double left, const TAO_Literal_Constraint& right)
{
  return (left == (CORBA::Double) right);
}

int
operator== (const StringSeq::Sequence_string& left,
	    const TAO_Literal_Constraint& right)
{
  int result =  0;

  if ((const char*)right != 0)
    result = ACE_OS::strcmp ((const char*) left,
			     (const char*) right) == 0;
  return result;
}
 

TAO_Literal_Constraint
operator+ (const TAO_Literal_Constraint& left,
	   const TAO_Literal_Constraint& right)
{
  TAO_Expression_Type widest_type =
    TAO_Literal_Constraint::widest_type(left, right);

  switch (widest_type)
    {
    case DOUBLE:
      {
	CORBA::Double result = (CORBA::Double)left + (CORBA::Double)right;
	return TAO_Literal_Constraint((CORBA::Double)result);
      }
      break;
    case SIGNED_INTEGER:
      {
	CORBA::Long result = (CORBA::Long)left + (CORBA::Long)right;
	return TAO_Literal_Constraint((CORBA::Long)result);
      }
      break;
    case UNSIGNED_INTEGER:
      {
	CORBA::ULong result = (CORBA::ULong)left + (CORBA::ULong)right;
	return TAO_Literal_Constraint((CORBA::ULong)result);
      }
      break;
    default:
      return TAO_Literal_Constraint((CORBA::Long)0);
    }
}

TAO_Literal_Constraint
operator- (const TAO_Literal_Constraint& left,
	   const TAO_Literal_Constraint& right)
{
  TAO_Expression_Type widest_type =
    TAO_Literal_Constraint::widest_type(left, right);

  switch (widest_type)
    {
    case DOUBLE:
      {
	CORBA::Double result = (CORBA::Double)left - (CORBA::Double)right;
	return TAO_Literal_Constraint((CORBA::Double)result);
      }
      break;
    case SIGNED_INTEGER:
      {
	CORBA::Long result = (CORBA::Long)left - (CORBA::Long)right;
	return TAO_Literal_Constraint((CORBA::Long)result);
      }
      break;
    case UNSIGNED_INTEGER:
      {
	CORBA::ULong result = (CORBA::ULong)left - (CORBA::ULong)right;
	return TAO_Literal_Constraint((CORBA::ULong)result);
      }
      break;
    default: 
      return TAO_Literal_Constraint((CORBA::Long)0);
    }
}

TAO_Literal_Constraint
operator* (const TAO_Literal_Constraint& left,
	   const TAO_Literal_Constraint& right)
{  
  TAO_Expression_Type widest_type =
    TAO_Literal_Constraint::widest_type(left, right);

  switch (widest_type)
    {
    case DOUBLE:
      {
	CORBA::Double result = (CORBA::Double)left * (CORBA::Double)right;
	return TAO_Literal_Constraint((CORBA::Double)result);
      }
      break;
    case SIGNED_INTEGER:
      {
	CORBA::Long result = (CORBA::Long)left * (CORBA::Long)right;
	return TAO_Literal_Constraint((CORBA::Long)result);
      }
      break;
    case UNSIGNED_INTEGER:
      {
	CORBA::ULong result = (CORBA::ULong)left * (CORBA::ULong)right;
	return TAO_Literal_Constraint((CORBA::ULong)result);
      }
      break;
    default:
      return TAO_Literal_Constraint((CORBA::Long)0);
    }  
}

TAO_Literal_Constraint
operator/ (const TAO_Literal_Constraint& left,
	   const TAO_Literal_Constraint& right)
{
  TAO_Expression_Type widest_type =
    TAO_Literal_Constraint::widest_type(left, right);

  switch (widest_type)
    {
    case DOUBLE:
      {
	CORBA::Double result = (CORBA::Double)left / (CORBA::Double)right;
	return TAO_Literal_Constraint((CORBA::Double)result);
      }
      break;
    case SIGNED_INTEGER:
      {
	CORBA::Long result = (CORBA::Long)left / (CORBA::Long)right;
	return TAO_Literal_Constraint((CORBA::Long)result);
      }
      break;
    case UNSIGNED_INTEGER:
      {
	CORBA::ULong result = (CORBA::ULong)left / (CORBA::ULong)right;
	return TAO_Literal_Constraint((CORBA::ULong)result);
      }
      break;
    default:
      return TAO_Literal_Constraint((CORBA::Long)0);
    }  
}

TAO_Literal_Constraint
operator- (const TAO_Literal_Constraint& operand)
{  
  switch (operand.expr_type())
    {
    case DOUBLE:
      {
	CORBA::Double result = - (CORBA::Double)operand;
	return TAO_Literal_Constraint((CORBA::Double)result);
      }
      break;
    case SIGNED_INTEGER:
      {
	CORBA::Long result = - (CORBA::Long)operand;
	return TAO_Literal_Constraint((CORBA::Long)result);
      }
      break;
    case UNSIGNED_INTEGER:
      {
	CORBA::Long result = - (CORBA::ULong)operand;
	return TAO_Literal_Constraint((CORBA::ULong)result);
      }
      break;
    default:
      return TAO_Literal_Constraint((CORBA::Long)0);
    }  
}

TAO_Expression_Type
TAO_Literal_Constraint::widest_type(TAO_Literal_Constraint& left,
				    TAO_Literal_Constraint& right)
{
  TAO_Expression_Type left_type = left.expr_type(),
    right_type = right.expr_type(),
    return_value = right_type;

  if (right_type != left_type)
    {
      if (right_type > left_type)
	return_value = right_type;
      else
	return_value = left_type;
    }

  return return_value;
}

void
TAO_Literal_Constraint::copy (const TAO_Literal_Constraint& lit)
{
  this->type_ = lit.type_;
  if (this->type_ == STRING)
    this->op_.str_ = ACE_OS::strdup(lit.op_.str_);
  else if (this->type_ == DOUBLE)
    this->op_.double_ = lit.op_.double_;
  else if (this->type_ == UNSIGNED_INTEGER)
    this->op_.uinteger_ = lit.op_.uinteger_;
  else if (this->type_ == SIGNED_INTEGER)
    this->op_.integer_ = lit.op_.integer_;
  else if (this->type_ == BOOLEAN)
    this->op_.bool_ = lit.op_.bool_;
  else if (this->type_ == SEQUENCE)
    this->op_.any_ = CORBA::Any::_duplicate (lit.op_.any_);
  else
    type_ = UNKNOWN;
}
