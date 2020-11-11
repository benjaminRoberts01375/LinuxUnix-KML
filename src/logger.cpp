#include "logger.h"

bool log(std::string msg, std::string programName, std::ofstream& logFile)
{
    //Get time and format it for storage
    std::string strTime;
    time_t logTime = time(0);
    strTime = ctime(&logTime);

    int timeSize = strTime.size();
    strTime[timeSize - 1] = ' ';

    //Get program name | Help from https://stackoverflow.com/questions/504810/how-do-i-find-the-current-machines-full-hostname-in-c-hostname-and-domain-info
    char hostname[256];
    gethostname(hostname, sizeof(hostname)); 

    pid_t pid = getpid();
    
    if (logFile.good())
    {
        logFile << strTime << " " << hostname << " " << programName << "[" << pid << "]" << ": " << msg << std::endl;
        return true;
    }
    else
    {
        return false;
    }    
}