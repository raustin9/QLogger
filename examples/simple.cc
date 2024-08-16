#include <iostream>
#include <qlogger/qlogger.h>

int main(void) {
    qlogger::Logger my_logger = qlogger::Logger();
    my_logger.use_colors(true);
    my_logger.use_console(true);

    my_logger.info("test log. my name is %s", "Alex");
    my_logger.debug("test log");
    my_logger.trace("test log");
    my_logger.warn("test log");
    my_logger.error("test log");
    my_logger.fatal("test log");
   
	return 0;
}
