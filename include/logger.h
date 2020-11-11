/**
 * @file logger.cpp
 * @brief Lecture 10.2 code – implementation of logging functions
 * @author Ben Roberts
 * @credits Bilbo (Devin) Baggins, Zxaos from stackoverflow
 * @assignment Lecture 10.2
 * @date 11/11/20
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
#include <unistd.h>

/**
 * @brief creates a discrete syslog message
 * @date 11/11/2020
 * @return a bool indicating the message was written
 * @param msg string containing syslog message
 * @param programName Name of the program calculated in main
 * @param logFile ofstream reference, validation of this file is expected
 */
bool log(std::string msg, std::string programName, std::ofstream& logFile);


#endif