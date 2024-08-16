#include <iostream>
#include <qlogger/qlogger.h>

int main(void) {
    qlogger::Logger my_logger = qlogger::Logger();
    my_logger.use_colors(true);
    my_logger.use_console(true);

    my_logger.info("test log. My name is %s", "alex");
   
	return 0;
}
