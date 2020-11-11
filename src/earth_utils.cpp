#include "earth_utils.h"

int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    std::string strCountry, strCapital, strLat, strLong, strLine;
    int recordCount{};

    //Setup KML File
    std::ofstream kml (kmlFileName, std::ios::out);

    if (inFile && kml.good())
    {
        kml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl;
        kml << "<kml xmlns=\"http://www.opengis.net/kml/2.2\">" << std::endl;
        kml << "<Document>" << std::endl;

        getline(inFile, strLine); //Remove that starting line

        while (getline(inFile, strLine))
        {
            std::stringstream s_stream(strLine);
            
            std::getline(s_stream, strCountry, ',');
            std::cout << strCountry << " ~ "; //Debug as requested in video

            std::getline(s_stream, strCapital, ',');
            std::cout << strCapital << " ~ "; //Debug as requested in video

            std::getline(s_stream, strLat, ','); 
            std::cout << strLat << " ~ "; //Debug as requested in video

            std::getline(s_stream, strLong, ',');
            std::cout << strLong; //Debug as requested in video

            writePlacemark(kml, strCapital + ", " + strCountry, strLat, strLong);

            std::cout << std::endl;
            recordCount++;
        }

        kml << "</Document>" << std::endl;
        kml << "</kml>" << std::endl;
    }

    return recordCount;
}

void writePlacemark(std::ofstream& kmlFile, std::string name, std::string latitude, std::string longitude)
{
    kmlFile << PLACEMARK << std::endl;
    kmlFile << NAME << name << NAME_END << std::endl;
    kmlFile << COORDS << longitude << "," << latitude << COORDS_END << std::endl;
    kmlFile << PLACEMARK_END << std::endl;
}