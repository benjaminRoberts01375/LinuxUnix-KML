#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>
#include "logger.h"
#include "earth_utils.h"

using namespace std;

int main(int argc, char *argv[])
{
    int opt{};
    bool kmlFlag, logFlag = false;
    bool optErr = true;
    string logValue, kmlValue;

    while ((opt = getopt(argc, argv, "k:l:")) != EOF) //Import arguments
    {
        switch (opt)
        {
        case 'k':
            kmlFlag = true;
            kmlValue = optarg;
            break;

        case 'l':
            logFlag = true;
            logValue = optarg;
            break;

        default: //Error if args are incorrect
            optErr = true;
            break;
        }
    }

    cout << "flags - countFlag: " << kmlFlag << " - logFlag: " << logFlag << endl;

    if (kmlFlag && logFlag) //Check for good args
    {
        cout << "Flags set!" << endl;

        if (logValue.empty() || kmlValue.empty())
        {
            optErr = true;
            cout << "Option arguments were not set!" << endl;
        }
        else
        {
            optErr = false;

            //Logging
            ofstream flog;
            flog.open(logValue, ios_base::app);
            if (flog)
            {
                string programName = basename(argv[0]);
                string msg = "The kmlfile is: " + kmlValue + " and the logfile is: " + logValue + ".";
                log(msg, programName, flog);
                optErr = false;
                flog.close();

                //CSV file parsing
                ifstream inFile;
                inFile.open(kmlValue);
                if (inFile)
                {
                    int recordCount = processCSV(inFile, kmlValue + ".kml");
                    inFile.close();
                    if (recordCount)
                    {
                        cout << recordCount << " records processed" << endl;
                        optErr = false;
                    }
                    else
                    {
                        optErr = true;
                    }
                }
            }
            else
            {
                cout << "Unable to open " << logValue << endl;
                optErr = true;
            }
        }
    }
    else
    {
        cout << "Error: Flags are not set!" << endl;
        optErr = true;
    }

    if (optErr)
    {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}