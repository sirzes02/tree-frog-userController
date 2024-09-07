#include "uservalidator.h"

UserValidator::UserValidator() : TFormValidator()
{
    // Set the rules below
    // setRule("xxxx", Tf::MaxLength, 20);
    //   :
    setRule("email", Tf::EmailAddress, true);
    setRule("password", Tf::MinLength, 6);
    setRule("password", Tf::MaxLength, 10);
}
