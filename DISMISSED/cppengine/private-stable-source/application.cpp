#include "application.h"
#include "globals.h"

application* application::getInstance()
{
	gcThrow("Feature not implemented: \napplication* application::getInstance","NOT_IMPLEMENTED");
}

void application::quitApplication(int exitCode)
{
	gcThrow("Feature not implemented: \nvoid application::quitApplication","NOT_IMPLEMENTED");
}

void application::setExceptionHandler(function* handler)
{
	gcThrow("Feature not implemented: \nvoid application::setExceptionHandler","NOT_IMPLEMENTED");
}

void application::terminate(int exitCode)
{
	gcThrow("Feature not implemented: \nvoid application::terminate","NOT_IMPLEMENTED");
}

void application::setExceptionScene(scene* Scene)
{
	gcThrow("Feature not implemented: \nvoid application::setExceptionScene","NOT_IMPLEMENTED");
}

bool application::init()
{
    return true;
}

int application::run()
{
    return 0;
}
